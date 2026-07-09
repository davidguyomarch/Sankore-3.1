# New Sankoré — Architecture from Scratch

## Contexte

Si on devait recréer Open-Sankoré aujourd'hui en partant de zéro, en ciblant Windows, Linux et macOS, voici l'architecture que je proposerais.

Les contraintes clés du projet :
- Tableau blanc interactif haute performance (dessin temps réel, faible latence)
- Multi-plateforme (Win/Linux/Mac, desktop et potentiellement tablettes)
- Export PDF, import/export de documents (.ubz = zip)
- Widgets HTML5 embarqués
- Enregistrement vidéo des cours (screencasting)
- Instruments géométriques (règle, compas, rapporteur...)
- Mode annotation sur le bureau (overlay transparent)
- Accessibilité et internationalisation

---

## Option A : Qt 6 + QML (recommandé)

### Stack technique

| Couche | Technologie | Justification |
|--------|-------------|---------------|
| **Langage** | C++20 + QML/JavaScript | C++ pour le moteur, QML pour l'UI déclarative |
| **Framework** | Qt 6.8+ | Mature, cross-platform natif, GPU acceleré |
| **UI** | Qt Quick (QML) | UI fluide, animations, touch-friendly, scalable HiDPI |
| **Canvas de dessin** | Qt Quick Scene Graph custom | Performance GPU native, shaders pour effets |
| **Widgets HTML5** | QtWebEngine (Chromium) | Full web rendering pour les widgets interactifs |
| **PDF** | QPdfDocument (Qt PDF) | Intégré à Qt 6, pas de dépendance externe |
| **Enregistrement** | Qt Multimedia + FFmpeg | QMediaRecorder pour capture, FFmpeg pour encodage |
| **ZIP/Documents** | QuaZip ou libzip | Gestion des .ubz |
| **Build system** | CMake | Standard moderne, meilleur support IDE |
| **Tests** | Qt Test + Catch2 | Unit + intégration |
| **CI/CD** | GitHub Actions | Multi-platform matrix (win/linux/mac) |
| **Packaging** | CPack + windeployqt/macdeployqt | Installeurs natifs |

### Architecture

```
new-sankore/
├── CMakeLists.txt
├── src/
│   ├── main.cpp
│   ├── core/                    # Application lifecycle, settings
│   │   ├── Application.h/cpp
│   │   ├── Settings.h/cpp
│   │   └── DocumentManager.h/cpp
│   ├── canvas/                  # Le cœur : moteur de dessin
│   │   ├── CanvasScene.h/cpp    # Scene graph custom
│   │   ├── StrokeItem.h/cpp     # Trait de stylo (Bézier, pressure)
│   │   ├── ShapeItem.h/cpp      # Formes géométriques
│   │   ├── ImageItem.h/cpp      # Images importées
│   │   ├── TextItem.h/cpp       # Texte riche
│   │   ├── WebWidgetItem.h/cpp  # Widget HTML5 embarqué
│   │   └── ToolController.h/cpp # Gestion des outils actifs
│   ├── tools/                   # Instruments
│   │   ├── Ruler.h/cpp
│   │   ├── Compass.h/cpp
│   │   ├── Protractor.h/cpp
│   │   └── Triangle.h/cpp
│   ├── document/                # Modèle de document
│   │   ├── Document.h/cpp       # Collection de pages
│   │   ├── Page.h/cpp           # Une page = une scène
│   │   ├── Serializer.h/cpp     # Save/Load .ubz (ZIP + SVG)
│   │   └── PdfExporter.h/cpp    # Export PDF
│   ├── recording/               # Screencasting
│   │   ├── Recorder.h/cpp       # Capture écran + audio
│   │   └── Encoder.h/cpp        # Encodage vidéo (FFmpeg)
│   ├── desktop/                 # Mode annotation bureau
│   │   ├── OverlayWindow.h/cpp  # Fenêtre transparente plein écran
│   │   └── Capturer.h/cpp       # Capture de fenêtre
│   └── ui/                      # Composants QML
│       ├── MainWindow.qml
│       ├── Toolbar.qml
│       ├── PageNavigator.qml
│       ├── Palette.qml
│       └── Preferences.qml
├── qml/                         # Fichiers QML purs
├── resources/                   # Icons, traductions, fonts
├── tests/
│   ├── unit/                    # Tests unitaires (C++)
│   └── integration/             # Tests d'intégration
├── packaging/
│   ├── windows/                 # NSIS/WiX installer
│   ├── linux/                   # AppImage/Flatpak/deb
│   └── macos/                   # DMG bundle
└── docs/
```

### Avantages

- **QML** pour l'UI = 10x moins de code que les QWidgets actuels, design responsive natif
- **Scene Graph GPU** = performance de dessin incomparable vs QPainter software
- **QtWebEngine intégré** = widgets HTML5 fonctionnels out-of-the-box
- **Qt PDF** = plus besoin de XPDF/Poppler
- **CMake** = build reproductible, vcpkg/conan pour les dépendances
- **Architecture claire** = séparation canvas/document/UI, testable

### Inconvénients

- QtWebEngine = +200 Mo dans la distribution
- QML = courbe d'apprentissage si l'équipe ne connaît que C++/QWidgets
- Qt commercial license pour certains modules (mais LGPL suffit pour notre usage)

---

## Option B : Electron + Canvas2D/WebGL (alternative web-first)

### Stack technique

| Couche | Technologie |
|--------|-------------|
| **Runtime** | Electron (Chromium + Node.js) |
| **Langage** | TypeScript |
| **Canvas** | HTML5 Canvas + WebGL (via Fabric.js ou Konva.js) |
| **UI** | React/Vue + TailwindCSS |
| **PDF** | pdf-lib (JS) |
| **ZIP** | JSZip |
| **Enregistrement** | MediaRecorder API (WebRTC) |
| **Build** | Vite + electron-builder |

### Avantages

- Développement beaucoup plus rapide (TypeScript, hot reload)
- Widgets HTML5 = natifs (c'est du web !)
- Grande communauté, bibliothèques abondantes
- UI moderne facilement

### Inconvénients

- **Performance de dessin** : Canvas2D/WebGL ne rivalise pas avec le GPU natif pour du dessin vectoriel haute résolution avec pressure sensitivity
- **Latence stylet** : Le pipeline Chromium ajoute 1-2 frames de latence
- **Consommation mémoire** : Electron = 200+ Mo RAM de base
- **Mode bureau** : Fenêtre overlay transparente = complexe en Electron
- **Accès hardware** : Tablettes graphiques, multi-écran = limité

---

## Option C : Flutter (desktop)

### Stack technique

| Couche | Technologie |
|--------|-------------|
| **Runtime** | Flutter Desktop (Skia + Impeller) |
| **Langage** | Dart |
| **Canvas** | CustomPainter (Skia backend) |
| **UI** | Material/Custom widgets |
| **PDF** | printing package + pdf (Dart) |
| **Web** | webview_flutter |

### Avantages

- Rendu Skia = excellente performance de dessin
- UI déclarative moderne
- Hot reload
- Single codebase desktop + mobile (tablettes !)

### Inconvénients

- Flutter desktop encore jeune (bugs, manque de maturité)
- Écosystème Dart limité vs C++/JS
- Pas de QtWebEngine-level de web embedding
- Accès OS natif plus limité

---

## Ma recommandation : Option A (Qt 6 + QML)

### Pourquoi

1. **Performance** — Le dessin au stylet exige du temps réel. Qt Quick Scene Graph avec le rendu GPU est imbattable pour ça. C'est le cœur du produit.

2. **Cross-platform natif** — Qt gère Windows/Linux/macOS/Android/iOS avec un seul code. Les pipelines graphiques sont natifs (Direct3D, Metal, Vulkan, OpenGL).

3. **Maturité** — Qt a 30 ans. Les APIs tablette graphique (QTabletEvent, pressure, tilt, rotation) sont les meilleures du marché desktop.

4. **Mode bureau** — Les fenêtres overlay transparentes, la capture d'écran, le multi-écran sont des APIs Qt natives et éprouvées.

5. **Continuité** — L'équipe connaît déjà Qt/C++. La migration vers QML peut être progressive (commencer par le canvas, garder QWidgets pour les palettes).

6. **Taille** — L'app sans WebEngine fait ~30 Mo. Avec WebEngine ~250 Mo. Electron serait ~350 Mo minimum pour les mêmes fonctionnalités.

### Différences clés vs le Sankoré actuel

| Aspect | Sankoré 3.1 | New Sankoré |
|--------|-------------|-------------|
| Build system | qmake (.pro) | CMake |
| UI | QWidgets (code C++) | QML (déclaratif) |
| Canvas | QGraphicsScene (CPU) | Qt Quick Scene Graph (GPU) |
| Web widgets | QtWebKit (mort) → stubs | QtWebEngine (Chromium) |
| PDF render | XPDF (obsolète) | Qt PDF module |
| Enregistrement | Windows Media SDK | Qt Multimedia + FFmpeg |
| Architecture | Monolithique, couplé | Modulaire, interfaces, injectable |
| Tests | 6 classes QTest | Full coverage, CI obligatoire |
| CI | GitHub Actions (ajouté récemment) | Matrix build (3 OS), tests, packaging |
| Document format | .ubz (SVG + ZIP) | .ubz v2 (JSON + ZIP) — rétrocompat possible |

### Estimation effort

Pour un développeur senior full-time :
- **MVP** (dessin, pages, save/load, export PDF) : 3-4 mois
- **V1** (+ instruments, mode bureau, import ancien .ubz) : 6-8 mois
- **V2** (+ widgets HTML5, enregistrement, teacher guide) : 10-12 mois

Pour une équipe de 3 :
- MVP en 6 semaines
- V1 en 3 mois
- V2 en 5 mois

---

## Alternative hybride : Garder le C++ actuel, refactorer progressivement

Plutôt que de tout réécrire, on peut aussi :
1. Finir la migration Qt6 (en cours — presque terminée)
2. Remplacer progressivement QGraphicsScene par Qt Quick pour le canvas
3. Migrer l'UI vers QML palette par palette
4. Ajouter QtWebEngine quand le build est stable
5. Remplacer le screencasting par Qt Multimedia

C'est moins risqué mais plus lent. Le code actuel a 125K LOC avec beaucoup de dette technique. La réécriture serait probablement 30-40K LOC pour la même fonctionnalité.


---

## Option D : Rust

### Pourquoi Rust est séduisant

Rust offre des avantages réels par rapport à C++ pour un projet comme Sankoré :
- **Sécurité mémoire sans GC** — Plus de use-after-free, double-free, buffer overflows (nombreux dans le code actuel)
- **Concurrence safe** — Le borrow checker empêche les data races à la compilation
- **Performance native** — Équivalente à C++, parfois meilleure (meilleures optimisations grâce aux garanties d'aliasing)
- **Outillage moderne** — Cargo (build + deps), rustfmt, clippy, docs.rs, crates.io
- **Pas de header files** — Un module = un fichier. Compilation incrémentale rapide.
- **Cross-compilation facile** — `cargo build --target x86_64-pc-windows-msvc` depuis Linux

### Stack Rust envisageable

| Couche | Option 1 (natif) | Option 2 (hybride) |
|--------|-------------------|---------------------|
| **GUI** | Slint ou Iced | Tauri 2.0 (frontend web) |
| **Canvas** | wgpu + lyon (tessellation) | HTML Canvas/WebGL via Tauri |
| **Rendu vectoriel** | vello (GPU 2D) | Fabric.js / Konva.js |
| **Stylet** | raw-window-handle + OS APIs | Web Pointer Events |
| **Web widgets** | wry (WebView natif) | Natif (c'est du web) |
| **PDF** | lopdf + printpdf | pdf-lib (JS) |
| **ZIP** | zip crate | JSZip |
| **Enregistrement** | ffmpeg-next (bindings FFmpeg) | MediaRecorder API |
| **Sérialisation** | serde + serde_json | serde-wasm-bindgen |

### Analyse par critère

| Critère | Score Rust | Commentaire |
|---------|------------|-------------|
| Performance canvas | ⭐⭐⭐⭐⭐ | vello/wgpu = state of the art GPU 2D |
| Gestion stylet | ⭐⭐ | Pas de framework standard, il faut écrire les bindings OS |
| Web embedding | ⭐⭐⭐ | wry fonctionne mais basique vs QtWebEngine |
| Overlay bureau | ⭐⭐ | Possible via winit mais non-trivial, peu documenté |
| Instruments géométriques | ⭐⭐⭐⭐ | Maths = excellent en Rust, rendu = à construire |
| Multi-écran | ⭐⭐⭐ | winit le gère, mais moins mature que Qt |
| Packaging cross-platform | ⭐⭐⭐ | cargo-bundle, tauri-bundler |
| Vitesse de développement | ⭐⭐ | Borrow checker = friction, moins de libs GUI prêtes |
| Maintenabilité long terme | ⭐⭐⭐⭐⭐ | Code quasi incassable une fois compilé |
| Recrutement | ⭐⭐ | Moins de devs Rust que C++/Qt disponibles |

### Le problème fondamental

Le moteur de dessin (vello/wgpu) serait **supérieur** à Qt pour le rendu pur. Mais un logiciel de tableau blanc n'est pas qu'un canvas — c'est :

1. **Un éditeur GUI complexe** — Palettes, docking, menus contextuels, drag & drop, undo/redo multi-niveaux, arbre de widgets
2. **Un gestionnaire de fenêtres** — Overlay transparent, multi-écran, mirror display
3. **Un mini-navigateur web** — Pour les widgets HTML5 interactifs
4. **Un enregistreur vidéo** — Capture + encodage temps réel
5. **Un viewer PDF** — Rendu fidèle de documents
6. **Un gestionnaire de périphériques** — Tablettes Wacom, stylets, surface pen

En Qt, tout ça existe. En Rust, il faut assembler 10+ crates partielles et combler les trous soi-même.

### Sous-option : Rust + Qt via cxx-qt

[cxx-qt](https://github.com/KDAB/cxx-qt) permet d'écrire le backend en Rust et l'UI en QML. C'est la combinaison la plus prometteuse :

```
┌──────────────────────────────┐
│         QML (UI)             │  ← Déclaratif, rapide à itérer
├──────────────────────────────┤
│     cxx-qt bridge            │  ← Bindings auto-générés
├──────────────────────────────┤
│    Rust (moteur, document,   │  ← Safe, performant
│    canvas, sérialisation)    │
├──────────────────────────────┤
│    Qt Quick Scene Graph      │  ← Rendu GPU natif
│    QtWebEngine, QtMultimedia │  ← Fonctionnalités Qt
└──────────────────────────────┘
```

**Avantages** :
- Backend Rust = fiable, performant, testable
- Frontend QML = toute la puissance de Qt (stylet, overlay, web, multi-écran)
- Le meilleur des deux mondes

**Inconvénients** :
- cxx-qt est encore jeune (v0.7 en 2026, KDAB le maintient activement)
- Debugging cross-language complexe
- Documentation limitée pour les cas avancés
- Deux toolchains à gérer (cargo + CMake/qmake)

### Verdict Rust

| Scénario | Recommandation |
|----------|----------------|
| Équipe expérimentée Rust, projet neuf, pas de pression deadline | **Rust + cxx-qt** — meilleure architecture long terme |
| Équipe C++/Qt, produit à livrer en < 12 mois | **Qt 6 + QML pur** — pragmatique, éprouvé |
| Prototype rapide, audience web possible aussi | **Tauri 2.0 + Rust backend** — léger, moderne, mais limité pour le stylet |

**Pour Sankoré spécifiquement** : Si c'est un projet à 5+ ans d'horizon avec une équipe motivée, Rust + cxx-qt est le meilleur investissement. Si l'objectif est de livrer un produit fonctionnel dans l'année, Qt natif reste plus sûr.

---

## Tableau récapitulatif final

| Critère | Qt6/QML (C++) | Electron (TS) | Flutter (Dart) | Rust (natif) | Rust + cxx-qt |
|---------|:---:|:---:|:---:|:---:|:---:|
| Performance dessin | ⭐⭐⭐⭐ | ⭐⭐ | ⭐⭐⭐⭐ | ⭐⭐⭐⭐⭐ | ⭐⭐⭐⭐ |
| Latence stylet | ⭐⭐⭐⭐⭐ | ⭐⭐ | ⭐⭐⭐ | ⭐⭐⭐⭐ | ⭐⭐⭐⭐⭐ |
| Cross-platform | ⭐⭐⭐⭐⭐ | ⭐⭐⭐⭐⭐ | ⭐⭐⭐⭐ | ⭐⭐⭐ | ⭐⭐⭐⭐⭐ |
| Web widgets | ⭐⭐⭐⭐⭐ | ⭐⭐⭐⭐⭐ | ⭐⭐ | ⭐⭐⭐ | ⭐⭐⭐⭐⭐ |
| Mode bureau overlay | ⭐⭐⭐⭐⭐ | ⭐⭐ | ⭐⭐ | ⭐⭐ | ⭐⭐⭐⭐⭐ |
| Vitesse dev | ⭐⭐⭐ | ⭐⭐⭐⭐⭐ | ⭐⭐⭐⭐ | ⭐⭐ | ⭐⭐⭐ |
| Maintenabilité | ⭐⭐⭐ | ⭐⭐⭐ | ⭐⭐⭐ | ⭐⭐⭐⭐⭐ | ⭐⭐⭐⭐⭐ |
| Taille distribution | ⭐⭐⭐⭐ | ⭐⭐ | ⭐⭐⭐ | ⭐⭐⭐⭐⭐ | ⭐⭐⭐⭐ |
| Écosystème/libs | ⭐⭐⭐⭐⭐ | ⭐⭐⭐⭐⭐ | ⭐⭐⭐ | ⭐⭐⭐ | ⭐⭐⭐⭐ |
| **Score total** | **39** | **32** | **30** | **33** | **41** |

**Conclusion** : Rust + cxx-qt est théoriquement le meilleur choix architectural, mais Qt6/QML pur reste le choix pragmatique le plus sûr aujourd'hui. La décision dépend de l'horizon temporel et de la tolérance au risque technique.
