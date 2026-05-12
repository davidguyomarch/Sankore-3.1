# API Reference

## JavaScript Widget API (UBWidgetUniboardAPI)

Exposed to embedded W3C widgets via `window.sankore` object.

### Properties

| Property | Type | Description |
|----------|------|-------------|
| `pageCount` | int | Number of pages in current document |
| `currentPageNumber` | int | Current page index |
| `uuid` | QString | Unique widget instance identifier |
| `lang` | QString | Locale string (e.g., "fr-CH") |
| `messages` | QObject* | Inter-widget messaging API |
| `datastore` | QObject* | Persistent data storage API |

### Drawing Methods

| Method | Parameters | Description |
|--------|-----------|-------------|
| `setTool(toolString)` | "pen", "marker", "arrow", "line" | Set active tool |
| `setPenColor(color)` | HTML color or index (1-4) | Set pen color |
| `setMarkerColor(color)` | HTML color/rgba or index | Set marker color |
| `moveTo(x, y)` | Scene coordinates | Move drawing position |
| `drawLineTo(x, y, width)` | Scene coordinates, line width | Draw line |
| `eraseLineTo(x, y, width)` | Scene coordinates, erase width | Erase content |
| `clear()` | — | Remove all content |
| `setBackground(isDark, isCrossed)` | booleans | Set background |

### View Methods

| Method | Parameters | Description |
|--------|-----------|-------------|
| `zoom(factor, x, y)` | Zoom factor, center position | Zoom viewport |
| `move(x, y)` | Pixel offsets | Pan viewport |
| `centerOn(x, y)` | Scene coordinates | Center viewport |

### Content Methods

| Method | Parameters | Description |
|--------|-----------|-------------|
| `addObject(url, w, h, x, y, background)` | URL + placement | Add media/widget |
| `addText(text, x, y, height, font, bold, italic)` | Text + styling | Add text item |
| `resize(width, height)` | Widget dimensions | Resize widget |

### Widget Instance Methods

| Method | Parameters | Description |
|--------|-----------|-------------|
| `setPreference(key, value)` | String key/value | Save preference |
| `preference(key, default)` | Key + fallback | Get preference |
| `preferenceKeys()` | — | List all preference keys |
| `locale()` | — | Get locale string (deprecated) |
| `showMessage(message)` | Message string | Show status message |
| `loadUrl(url)` | URL string | Open URL in browser |
| `pageThumbnail(pageNumber)` | Page index | Get thumbnail URL |

### Font Preference Methods

| Method | Description |
|--------|-------------|
| `updateFontFamilyPreference(family)` | Set font family |
| `updateFontSizePreference(size)` | Set font size |
| `updateFontBoldPreference()` | Toggle bold |
| `updateFontItalicPreference()` | Toggle italic |
| `fontFamilyPreference()` | Get current font |
| `fontSizePreference()` | Get current size |
| `fontBoldPreference()` | Get bold state |
| `fontItalicPreference()` | Get italic state |

### Drag & Drop Methods

| Method | Description |
|--------|-------------|
| `enableDropOnWidget(enable)` | Enable/disable drop |
| `ProcessDropEvent(event)` | Handle dropped content |

## Document Datastore API (UBDocumentDatastoreAPI)

Accessed via `window.sankore.datastore.document`:

| Method | Parameters | Description |
|--------|-----------|-------------|
| `key(index)` | Integer index | Get key at index |
| `getItem(key)` | Key string | Get stored value |
| `setItem(key, value)` | Key, value strings | Store value |
| `removeItem(key)` | Key string | Remove stored value |
| `clear()` | — | Clear all data |
| `length` | — (property) | Number of stored items |

## Internal C++ APIs

### UBPersistenceManager Public API

| Method | Description |
|--------|-------------|
| `createDocument(group, name, withEmptyPage, dir, pageCount)` | Create new document |
| `createDocumentFromDir(dir, group, name)` | Import from directory |
| `duplicateDocument(proxy)` | Clone document |
| `deleteDocument(proxy)` | Delete document |
| `persistDocumentScene(proxy, scene, index)` | Save scene to SVG |
| `loadDocumentScene(proxy, index)` | Load scene from SVG |
| `createDocumentSceneAt(proxy, index)` | Add new page |
| `moveSceneToIndex(proxy, source, target)` | Reorder pages |
| `deleteDocumentScenes(proxy, indexes)` | Delete pages |

### UBBoardController Key Public API

| Method | Description |
|--------|-------------|
| `setActiveDocumentScene(proxy, index)` | Navigate to page |
| `addScene()` | Add new page |
| `duplicateScene()` | Duplicate current page |
| `deleteScene(index)` | Remove page |
| `downloadURL(url, ...)` | Add web content to board |
| `addVideo(url, autoplay, pos)` | Add video item |
| `addAudio(url, autoplay, pos)` | Add audio item |
| `addW3cWidget(url, pos)` | Add widget item |
| `cut() / copy() / paste()` | Clipboard operations |
| `zoomIn() / zoomOut() / zoomRestore()` | Zoom control |
| `previousScene() / nextScene()` | Page navigation |
| `changeBackground(isDark, isCrossed)` | Set background |

### UBDrawingController Public API

| Method | Description |
|--------|-------------|
| `stylusTool()` | Get current tool enum |
| `setStylusTool(tool)` | Set active tool |
| `currentToolWidth()` | Get tool width |
| `currentToolColor()` | Get tool color |
| `setPenColor(onDark, color, index)` | Set pen color |
| `setMarkerColor(onDark, color, index)` | Set marker color |

## Cross-References
- [Interfaces](interfaces.md)
- [Modules](modules.md)
- [Business Logic](../behavior/business-logic.md)
