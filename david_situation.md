# État des lieux — Open-Sankoré Qt6 Migration

*Mis à jour : 8 juillet 2025*

## Phase actuelle : Compilation Windows (MSVC) via GitHub Actions

On est dans la boucle "compilation → correction des erreurs → push → CI". Le build avance bien : moc passe, les .cpp compilent en grande partie. On corrige les erreurs restantes une par une.

---

## Ce qui est FAIT ✅

| Élément | Détail |
|---------|--------|
| **Migration Qt4 → Qt6 (Linux)** | 125K LOC migrés via AWS Transform, zéro erreurs sur Docker Linux (sankore-qt6) |
| **CI Windows GitHub Actions** | Pipeline fonctionnel : Qt 6.8.3 + MSVC 2022 + vcpkg |
| **pdf-merger réactivé** | Vrais sources (plus de stubs vides), zlib via vcpkg |
| **QuaZip** | Lié via vcpkg (`quazip1-qt6`) — fonctionnel |
| **QtSingleApplication** | Stub fonctionnel (QLockFile, 90% feature-complete) |
| **Plugin CFF** | Corrigé pour Qt6 (`QMultiMapIterator`, `Qt::KeepEmptyParts`) |
| **Stubs WebEngine** | Enrichis (`WebAction`, `NavigationType`, `settings()`, etc.) |
| **QDesktopWidget → QScreen** | Corrigé dans `UBBoardPaletteManager` et `UBWebController` |
| **Documentation** | Doxygen + `docs/README.md` |
| **Unit tests** | 117 tests QTest passant (Docker) |
| **Steering Kiro** | `.kiro/steering/project-context.md` créé |

---

## Ce qui est EN COURS 🔄

**Compilation MSVC Windows** — On attend le résultat du dernier push. Les étapes franchies :
1. ✅ qmake passe
2. ✅ moc passe (tous les headers)
3. ✅ rcc / uic passent
4. ✅ Compilation C++ : adaptors, api, pdf-merger compilent
5. ⏳ Compilation C++ : board, core, gui, web, domain, tools, desktop — possibles erreurs Qt6 résiduelles (type `QDesktopWidget`, qu'on vient de corriger)
6. ⬜ Link (résolution des symboles, libs externes)
7. ⬜ Production du .exe

---

## Ce qu'il RESTE À FAIRE 📋

### Court terme (obtenir un .exe fonctionnel)

| # | Tâche | Effort estimé | Impact |
|---|-------|---------------|--------|
| 1 | **Corriger les erreurs de compilation MSVC restantes** | Itératif (1-3 cycles CI) | Bloquant |
| 2 | **Résoudre le link** | Moyen | Bloquant — peut nécessiter des libs manquantes (OpenSSL?) |
| 3 | **Packager les DLLs Qt** | Facile (`windeployqt`) | Nécessaire pour que l'exe tourne |
| 4 | **Tester le lancement** | Manuel | Valider que l'app démarre |

### Moyen terme (application fonctionnelle)

| # | Tâche | Impact fonctionnel |
|---|-------|--------------------|
| 5 | **Intégrer QtWebEngine** (vrai module, pas stubs) | Widgets interactifs, browser intégré, teacher guide web |
| 6 | **Ajouter OpenSSL pour Windows** | HTTPS dans le browser/network |
| 7 | **Build Linux CI** | Second target (Ubuntu x64) |
| 8 | **Tests fonctionnels** | Valider open/save .ubz, export PDF, dessin |

### Long terme (qualité production)

| # | Tâche |
|---|-------|
| 9 | Remplacer les stubs WebEngine par la vraie lib ou une alternative (CEF?) |
| 10 | Installer / packaging (NSIS pour Windows, .deb pour Linux) |
| 11 | Signature code / certificat |
| 12 | Tests d'intégration automatisés |

---

## Risques identifiés

- **Link Windows** : possibles symboles manquants (OpenSSL `_crypto`, Windows APIs type `Dwmapi.lib`, `Wtsapi32.lib`)
- **QtWebEngine** : le module est volumineux (~400 MB), l'install via aqtinstall était bugguée. Peut nécessiter une approche alternative
- **pdf-merger + zlib** : le nom exact de la lib vcpkg (`zlib.lib` vs `zlibstatic.lib`) pourrait poser un problème au link

---

## Résumé en une phrase

On est à ~80% de la compilation Windows. Le moc, rcc, uic passent. Les .cpp compilent module par module. On corrige les dernières erreurs Qt6 résiduelles (API supprimées). Une fois la compilation terminée, il restera le link puis le packaging.
