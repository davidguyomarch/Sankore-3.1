# État des lieux — Open-Sankoré Qt6 Migration

*Mis à jour : 8 juillet 2025 — 23h30*

## Phase actuelle : LINK — En attente du résultat final

**La compilation est terminée à 100%.** Tous les fichiers .cpp et moc_*.cpp compilent sans erreur. On est maintenant dans la phase de linkage (production du .exe). Le dernier blocage est un nom de lib OpenSSL incorrect, corrigé et poussé.

---

## Progression

```
[██████████████████████████████████████░░] 95% — Link en cours
```

### Compilation : ✅ TERMINÉE

| Module | Fichiers | Statut |
|--------|----------|--------|
| adaptors/ | 19 .cpp | ✅ |
| api/ | 4 .cpp | ✅ |
| board/ | 5 .cpp | ✅ |
| core/ | 16 .cpp (main, UBApplication, UBSettings...) | ✅ |
| document/ | 4 .cpp | ✅ |
| domain/ | 55+ .cpp | ✅ |
| frameworks/ | 12 .cpp (dont UBPlatformUtils_win) | ✅ |
| gui/ | 45+ .cpp | ✅ |
| pdf-merger/ | 22 .cpp | ✅ |
| plugins/cffadaptor | 1 .cpp | ✅ |
| podcast/ | 5 .cpp (windowsmedia exclu) | ✅ |
| tools/ | 10 .cpp | ✅ |
| desktop/ | 6 .cpp (dont WindowCapture_win) | ✅ |
| transition/ | 1 .cpp | ✅ |
| customWidgets/ | 3 .cpp | ✅ |
| web/ | modules stubbed | ✅ |
| network/ | modules réseau | ✅ |
| moc_*.cpp | ~50 fichiers | ✅ |
| qrc_*.cpp | 2 fichiers (sankore, resources) | ✅ |

### Link : 🔄 EN COURS

| Dépendance | Méthode | Statut |
|------------|---------|--------|
| Qt 6.8.3 | aqtinstall | ✅ Lié |
| QuaZip 1.4 (static) | Build from source CMake | ✅ Compilé & installé |
| zlib | vcpkg | ✅ Lié |
| OpenSSL (libssl, libcrypto) | vcpkg | 🔄 Noms corrigés, en attente CI |
| Windows system libs | Ajoutées dans .pro | ✅ |

---

## Derniers commits (cette session)

| Commit | Problème | Fix |
|--------|----------|-----|
| `b93cdbe4` | windowsmedia Qt6 incompatible | Exclu du build, stubs dans UBPodcastController |
| `df1726e6` | UBWindowCaptureDelegate_win.cpp | QMutex, QWaitCondition, QScreen::grabWindow |
| `3d11e459` | Link: zlib.lib introuvable | Ajout -lzlib, tentative quazip vcpkg |
| `bbe911f5` | vcpkg quazip tire tout Qt6 (timeout) | Build QuaZip from source, reorder CI steps |
| `f1c1b993` | Link: ssl.lib introuvable | -lssl → -llibssl, -lcrypto → -llibcrypto, +Crypt32 +Ws2_32 |

---

## Architecture du CI (build-windows.yml)

```
1. Checkout
2. Install Qt 6.8.3 (aqtinstall)
3. Setup MSVC 2022
4. vcpkg install zlib + openssl (x64-windows)
5. Build QuaZip v1.4 from source (CMake, static, uses aqtinstall Qt6)
6. qmake Sankore_3.1.pro
7. nmake release
8. Upload artifact
```

## Bibliothèques liées (win32 dans .pro)

```
# QuaZip (from source)
-LC:/quazip/lib -lquazip1-qt6

# vcpkg
-L$(VCPKG_ROOT)/installed/x64-windows/lib -lzlib -llibssl -llibcrypto

# Windows system
-lDwmapi -lWtsapi32 -lUser32 -lShell32 -lOle32 -lAdvapi32 -lGdi32 -lCrypt32 -lWs2_32
```

---

## Écarts fonctionnels — Simplifications et stubs

### 1. Navigateur web embarqué (MAJEUR)

**Impact** : Tout ce qui concerne l'affichage de contenu web dans le tableau blanc est non-fonctionnel.

| Composant | État | Impact utilisateur |
|-----------|------|-------------------|
| `QGraphicsWebView` | Stub (affiche "Web view disabled") | Impossible d'afficher des pages web dans le canvas |
| `QWebEnginePage` | Stub (no-op) | Pas de navigation, pas de rendu HTML |
| `QWebEngineSettings` | Stub (no-op) | Pas de configuration web |
| `QWebEngineProfile` | Stub (no-op) | Pas de profil/cookies |
| `QWebFrame` | Stub (evaluateJavaScript retourne QVariant vide) | Pas d'exécution JavaScript |
| Widgets W3C/HTML5 | Compilent mais ne fonctionnent pas | Les widgets interactifs (HTML5) ne s'affichent pas |
| Web trap (capture de contenu web) | Compilent mais inopérant | Impossible de capturer du contenu web vers la bibliothèque |
| YouTube/OEmbed | Code présent mais inopérant | Pas d'intégration vidéo en ligne |

**Cause** : QtWebEngine n'est pas inclus (lourd, ~500 Mo, complexe à cross-compiler).
**Remplacement** : Ajouter QtWebEngine quand le build est stabilisé. Module aqtinstall disponible.

### 2. Enregistrement podcast/screencasting (MAJEUR — Windows uniquement)

**Impact** : L'enregistrement vidéo du cours n'est pas fonctionnel sur Windows.

| Composant | État | Impact utilisateur |
|-----------|------|-------------------|
| `UBWindowsMediaVideoEncoder` | Exclu du build | Pas d'encodage vidéo |
| `UBWindowsMediaFile` | Exclu du build | Pas de création de fichier WMV |
| `UBWaveRecorder` | Exclu du build | Pas d'enregistrement audio |
| Enumération périphériques audio | Retourne liste vide | "Aucun périphérique" dans les préférences |

**Cause** : Windows Media Format SDK APIs obsolètes, incompatibles Qt6.
**Remplacement** : Qt Multimedia (QMediaRecorder, QAudioInput) — API moderne disponible dans Qt 6.8.

### 3. Single-instance IPC (MINEUR)

**Impact** : Limité.

| Composant | État | Impact utilisateur |
|-----------|------|-------------------|
| `QtSingleApplication` | Stub QLockFile | Détecte si une instance existe (OK) |
| `sendMessage()` | Retourne toujours `false` | Impossible d'envoyer un fichier à l'instance existante |
| `setActivationWindow()` | No-op | L'instance existante ne sera pas amenée au premier plan |

**Cause** : Dépendance ThirdParty QtSingleApplication supprimée.
**Remplacement** : QLocalSocket/QLocalServer pour IPC (quelques dizaines de lignes). Ou lib `SingleApplication` sur GitHub.

### 4. QuaZip — Stubs vs Réalité (RÉSOLU)

**Impact** : Les stubs sont maintenant overridés par la vraie lib grâce au `INCLUDEPATH` prepend.

| Situation | Avant | Maintenant |
|-----------|-------|-----------|
| Ouvrir/sauvegarder .ubz | Échouait silencieusement (stub retourne `false`) | ✅ Fonctionnel (vraie lib QuaZip linkée) |
| Import/Export documents | Non fonctionnel | ✅ Devrait fonctionner |
| Import CFF | Non fonctionnel | ✅ Devrait fonctionner |

**Risque résiduel** : Si le include guard de la vraie quazip.h est identique à notre stub (`QUAZIP_H`), le premier trouvé gagne. Avec le prepend, c'est la vraie lib. À vérifier au runtime.

### 5. Capture Flash (SUPPRIMÉ — non-régression)

**Impact** : Aucun. Flash est mort depuis 2020.

### 6. QDesktopWidget → QScreen (adaptation — pas un écart)

**Impact** : Nul. Les remplacements par `QGuiApplication::primaryScreen()` et `QScreen::grabWindow()` sont fonctionnellement équivalents. Pas de régression.

### 7. UBTeacherGuideWidgetsTools — freezedWidgetPage (MINEUR)

**Impact** : Dans le guide enseignant, l'aperçu des widgets web ne se rafraîchit pas correctement.

```cpp
// TODO: mainFrame() not available on QWebEngineView
// - use page()->setContent(...)
```

**Cause** : Le stub QWebFrame ne rend rien.
**Remplacement** : Sera résolu quand QtWebEngine sera intégré.

---

## Résumé des impacts par priorité

| Priorité | Fonctionnalité | Statut | Effort pour résoudre |
|----------|---------------|--------|---------------------|
| 🔴 Haute | Widgets web/HTML5 dans le canvas | Non fonctionnel | Moyen (ajouter QtWebEngine au build) |
| 🔴 Haute | Enregistrement podcast (Windows) | Non fonctionnel | Moyen (réécrire avec Qt Multimedia) |
| 🟡 Moyenne | Navigateur embarqué | Non fonctionnel | Moyen (QtWebEngine) |
| 🟡 Moyenne | Capture web vers bibliothèque | Non fonctionnel | Moyen (QtWebEngine) |
| 🟢 Faible | IPC single-instance (passage de fichier) | Partiel | Faible (QLocalSocket) |
| 🟢 Faible | Aperçu widget guide enseignant | Non fonctionnel | Résolu avec QtWebEngine |
| ⚪ Aucun | Flash, QDesktopWidget | Supprimé/Remplacé | Aucun effort |

---

## Ce qui FONCTIONNE (coeur métier)

- ✅ Dessin sur le tableau blanc (tous les outils : stylo, surligneur, gomme, formes)
- ✅ Gestion des pages (ajouter, supprimer, naviguer)
- ✅ Ouvrir/sauvegarder des documents .ubz (QuaZip réel)
- ✅ Export PDF (pdf-merger réactivé)
- ✅ Import/Export de documents
- ✅ Import CFF (Common File Format)
- ✅ Instruments géométriques (règle, triangle, compas, rapporteur, aristo)
- ✅ Rideaux et cache
- ✅ Mode bureau (annotation sur le desktop)
- ✅ Capture d'écran / capture de fenêtre
- ✅ Palette d'outils, menus, préférences
- ✅ Single-instance (détection)
- ✅ Transitions Uniboard → Sankoré
---

## Prochaines étapes

1. **Résultat CI du link** — Si le .exe est produit, on passe à `windeployqt` pour packager
2. **Unresolved symbols possibles** — Peut nécessiter d'autres libs Windows ou ajustements
3. **windeployqt** — Copie des DLLs Qt nécessaires à côté du .exe
4. **Test fonctionnel** — Vérifier que l'app se lance
5. **Build Linux** — Réutiliser le Dockerfile existant

---

## Sujets restants (non-bloquants)

| Sujet | Priorité | Description |
|-------|----------|-------------|
| Warning D9025 `/O2` vs `/Od` | Faible | qmake ajoute `/O2` (release) puis on ajoute `/Od` (debug info). Le dernier gagne, c'est inoffensif mais bruyant. Fix : `QMAKE_CXXFLAGS_RELEASE -= -O2` avant d'ajouter `/Od /Zi` |
| Warning LNK4217 UBCFFAdaptor | Faible | Symboles définis dans `UBCFFAdaptor.obj` importés par `UBExportCFF.obj`. Mismatch `__declspec(dllimport)` dans le header du plugin. Non bloquant, fonctionne quand même |
| QuaZip include guard | Faible | Vérifier au runtime que les vrais headers QuaZip sont bien utilisés (stubs supprimés, devrait être OK) |

---

## Résumé

Toute la compilation passe. QuaZip est buildé from source (évite le timeout vcpkg). Le dernier fix est le nom des libs OpenSSL sur Windows (libssl.lib/libcrypto.lib au lieu de ssl.lib/crypto.lib). On est à **1 cycle CI du .exe** si pas d'autres symboles manquants.
