# Validation Criteria

## Migration Success Criteria

### Build Validation
- [ ] Application compiles without errors on target Qt version
- [ ] All modules compile independently
- [ ] No deprecated API warnings (or documented exceptions)
- [ ] Builds successfully on all target platforms (macOS, Windows, Linux)
- [ ] Third-party dependencies link correctly

### Functional Validation

#### Core Functions
- [ ] Application launches and displays board mode
- [ ] Documents can be created, opened, saved, deleted
- [ ] Page navigation works (add, remove, reorder, navigate)
- [ ] Document repository is discovered on startup

#### Drawing Functions
- [ ] Pen tool draws strokes with pressure sensitivity
- [ ] Marker tool draws semi-transparent strokes
- [ ] Eraser removes content
- [ ] Line tool creates straight lines
- [ ] Shape tools create geometric shapes
- [ ] Colors adapt to background (dark/light)

#### Content Functions
- [ ] Images can be added (drag-drop, file dialog)
- [ ] SVG content renders correctly
- [ ] Text items can be created and edited
- [ ] Groups can be created and ungrouped
- [ ] Copy/paste works for all item types

#### Undo/Redo
- [ ] All drawing operations can be undone
- [ ] All item additions can be undone
- [ ] Redo restores undone operations
- [ ] Undo stack clears on document change

#### Import/Export
- [ ] PDF import creates readable document
- [ ] Image import works (PNG, JPG, GIF)
- [ ] .ubz export creates valid archive
- [ ] .ubz import restores document completely
- [ ] PDF export generates valid PDF

#### Web Integration (Post Qt WebEngine Migration)
- [ ] Web browser mode loads pages
- [ ] Widgets (.wgt) load and execute
- [ ] Widget JavaScript API functions
- [ ] OEmbed URLs resolve

#### Media (Post Qt Multimedia Migration)
- [ ] Video items play
- [ ] Audio items play
- [ ] Podcast recording captures screen

### Performance Validation
- [ ] Application startup under acceptable threshold
- [ ] Page navigation is responsive
- [ ] Drawing latency is acceptable for interactive use
- [ ] Memory usage is stable (no leaks)
- [ ] Large documents (100+ pages) open without crash

### Data Compatibility
- [ ] Existing .ubz documents from Qt 4 version open correctly
- [ ] SVG scene files parse without data loss
- [ ] Metadata preserved through upgrade
- [ ] Document tree structure intact

### Platform Validation

#### macOS
- [ ] Builds as .app bundle
- [ ] Runs on macOS 12+ (Intel and Apple Silicon)
- [ ] Multi-screen support works
- [ ] File associations work (.ubz, .pdf)

#### Windows
- [ ] Builds with MSVC 2022+
- [ ] Runs on Windows 10/11
- [ ] Installer package works
- [ ] File associations work

#### Linux
- [ ] Builds with GCC 12+ / Clang 15+
- [ ] Runs on Ubuntu 22.04+
- [ ] X11/Wayland display support
- [ ] Package builds correctly (deb/rpm)

### Regression Criteria
- [ ] No feature regressions vs. Qt 4 version (except intentional removals)
- [ ] Document format remains backward-compatible or migration tool provided
- [ ] All 36 translation files load correctly
- [ ] UI layout matches design expectations

## Phase Gate Criteria

| Phase | Gate Criteria |
|-------|--------------|
| Phase 1 (Foundation) | frameworks/ compiles, unit tests pass |
| Phase 2 (Core) | Settings, network compile; basic app skeleton runs |
| Phase 3 (Domain) | Scene + items compile; basic drawing works |
| Phase 4 (Adaptors) | Save/load roundtrip preserves all item types |
| Phase 5 (Controllers) | Full application runs in board mode |
| Phase 6 (Web/Media) | Web and media features functional |
| Phase 7 (GUI) | Full UI operational, all palettes visible |
| Phase 8 (Build) | Clean build on all platforms, packaging works |

## Cross-References
- [Test Specifications](test-specifications.md)
- [Component Order](component-order.md)
- [Remediation Plan](../technical-debt/remediation-plan.md)
