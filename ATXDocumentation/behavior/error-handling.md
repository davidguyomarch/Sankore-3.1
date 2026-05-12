> ⚠️ **Early Access**: Behavior documentation is in early access. Please review critically.

# Error Handling

## Exception Handling Patterns

### Qt Signal/Slot Error Propagation
Open-Sankoré uses Qt's signal/slot mechanism rather than C++ exceptions for error handling. Errors are typically handled through:
- Return value checking (null pointers, boolean success)
- `qDebug()` / `qWarning()` diagnostic output
- Graceful degradation (skip operation on failure)

### File I/O Error Handling

#### Document Loading
```
loadDocumentScene(proxy, index):
├── File not found → Return null scene, log warning
├── SVG parse error → Return partially loaded scene
├── Asset missing (image/video) → Item created with placeholder
└── Permission error → Return null, log error
```

#### Document Saving
```
persistDocumentScene(proxy, scene, index):
├── Directory creation failure → Log error, abort save
├── SVG write failure → Log error (data loss risk)
├── Thumbnail generation failure → Continue (non-critical)
└── Metadata write failure → Continue, log warning
```

### Network Error Handling

#### HTTP Download (UBHttpGet)
- Connection timeout → Emit failure signal
- HTTP error (4xx, 5xx) → Report via `downloadFinished(false, ...)`
- Partial download → Discard, report failure
- SSL errors → Log warning, may proceed or fail based on Qt config

#### Software Update Check
- Network unreachable → Silent failure (no user notification)
- Invalid response → Ignore, set `isNoUpdateDisplayed = true`
- Parse error → Skip update notification

### Graphics Item Error Handling

#### Item Creation Failures
```
Adding item to scene:
├── Null item → Skip add, log warning
├── Invalid geometry → Use default bounds
├── Missing media file → Create item with error indicator
└── Widget load failure → Show error in web view
```

#### Undo/Redo
- Invalid undo state → Clear undo stack (`ClearUndoStack()`)
- Item reference invalidated → Skip operation silently

### Import Error Handling

#### PDF Import
- Corrupted PDF → Skip unreadable pages, import readable ones
- Password-protected → Fail with user notification
- Large file → Process page by page (memory management)

#### CFF/IWB Import
- Invalid XML → Report error, abort import
- Unsupported element types → Skip with warning
- Asset references broken → Create placeholder items

### Platform-Specific Error Handling

#### macOS
- Carbon event errors return `eventNotHandledErr`
- Bundle resource missing → Fall back to relative paths

#### Windows
- ActiveX initialization failure → Disable web features
- Registry access failure → Use default settings

### Memory Management

#### Scene Cache Eviction
- Memory pressure → Persist and evict least-recently-used scenes
- Failed persistence on eviction → Log critical error (potential data loss)

#### Widget Memory
- `UBForeignObjectsHandler` tracks external assets
- `UBTrashRegistery` manages deleted items for deferred cleanup
- `staticMemoryCleaner` QObject parent for auto-deletion

### Graceful Degradation Patterns

1. **Missing translations**: Falls back to "en_US"
2. **Multi-screen unavailable**: Disables multi-screen action
3. **No camera/recording**: Podcast features disabled
4. **Tablet not detected**: Falls back to mouse input (fixed pressure=1.0)
5. **Third-party library missing**: Features dependent on library disabled

### User-Facing Error Communication

- `UBApplication::showMessage(message, showSpinningWheel)` - Status bar messages
- `UBMessageWindow` - Transient overlay messages on board
- Preferences dialog for configuration errors
- Silent logging for non-critical issues (no user interruption)

## Error Recovery Strategies

### Document Recovery
- Auto-save timer (`UBAutoSaver`) provides periodic checkpoints
- Scene cache persists dirty scenes before eviction
- Document folder structure preserved even on partial save failure

### Application Crash Recovery
- `UBPersistenceManager::closing()` called on orderly shutdown
- Dirty scenes flushed to disk
- No explicit crash recovery mechanism (data may be lost on abnormal termination)

## Cross-References
- [Business Logic](business-logic.md)
- [Workflows](workflows.md)
- [Security Patterns](../analysis/security-patterns.md)
