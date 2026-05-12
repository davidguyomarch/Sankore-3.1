# Security Patterns

## Cryptographic Operations

### UBCryptoUtils (`src/frameworks/UBCryptoUtils.h`)
- **Library**: OpenSSL (libcrypto) via `#include <openssl/evp.h>`
- **Operations**: Symmetric encryption/decryption (EVP API)
- **Methods**: `symetricEncrypt()`, `symetricDecrypt()`
- **Pattern**: Singleton with `instance()` / `destroy()`
- **Risk**: OpenSSL version dependency; API changes between 1.x and 3.x

### Observations
- Uses EVP high-level API (good practice, forward-compatible)
- Encryption key management not visible in header (implementation detail)
- Used for: document encryption, potentially license/DRM features

## Network Security

### UBNetworkAccessManager (`src/network/UBNetworkAccessManager.h`)
- Custom `QNetworkAccessManager` subclass
- Handles all HTTP/HTTPS requests
- Cookie management via `UBCookieJar`

### UBCookieJar (`src/network/UBCookieJar.h`)
- Persistent cookie storage
- Manages session cookies for embedded web content
- Risk: Cookie persistence may retain sensitive web session data

### HTTP Operations
- `UBHttpGet` - Plain HTTP downloads (no HTTPS enforcement observed)
- `UBServerXMLHttpRequest` - XMLHttpRequest for widgets
- **Risk**: No certificate pinning observed; relies on Qt's default SSL handling

### Software Update
- `UBApplicationController` uses `QHttp` (deprecated, no SSL support in early versions)
- Update checking over potentially unencrypted channel
- **Risk**: Man-in-the-middle attack on update mechanism

## Web Content Security

### QtWebKit Security
- `QWebSettings::JavaEnabled = true` - Java applets enabled (high risk)
- `QWebSettings::PluginsEnabled = true` - All plugins enabled (Flash, etc.)
- `QWebSettings::JavascriptCanAccessClipboard = true` - JS clipboard access
- **Risk**: Embedded web content has broad permissions

### Widget Sandbox
- W3C widgets execute in QWebView within QGraphicsScene
- JavaScript API (`UBWidgetUniboardAPI`) exposes:
  - Drawing operations on board
  - File system access (via widget preferences)
  - Content addition to board
- **Risk**: Widget code can manipulate board content; limited sandboxing

### OEmbed / External Content
- `UBOEmbedParser` resolves external embed URLs
- External content loaded without apparent sanitization
- **Risk**: Potential XSS via embedded content

## File System Security

### Document Storage
- Documents stored in user-writable directory
- No file integrity verification observed (no checksums)
- SVG parsing of untrusted input (imported documents)
- **Risk**: Malicious SVG could trigger parser vulnerabilities

### Temp File Handling
- `UBFileSystemUtils::deleteAllTempDirCreatedDuringSession()` - cleanup on exit
- Widget packages extracted to temp directories
- **Risk**: Race conditions in temp file usage (standard temp file risk)

## Input Validation

### Import Operations
- PDF import: Relies on PDF library for parsing
- SVG import: Custom parser in `UBSvgSubsetAdaptor`
- CFF import: XML parsing in `UBCFFSubsetAdaptor`
- Image import: Relies on Qt's image decoders
- **Risk**: Parser vulnerabilities in handling malformed files

### Widget Input
- Widget drop events processed via `ProcessDropEvent()`
- MIME type checking via `isDropableData()`
- `supportedTypeHeader()` validates content types
- Moderate validation present

## Authentication/Authorization
- No user authentication system observed
- No access control on document operations
- No network authentication beyond cookie management
- Application operates in local-user context only

## Security Recommendations

1. **Disable Java in WebKit** - High risk, rarely needed
2. **Enforce HTTPS for updates** - Prevent MITM attacks
3. **Sandbox widget execution** - Limit API surface
4. **Validate imported documents** - Check SVG/XML before parsing
5. **Update OpenSSL usage** - Ensure compatibility with modern versions
6. **Remove clipboard access** - Unless explicitly needed per widget

## Cross-References
- [Error Handling](../behavior/error-handling.md)
- [Dependencies](../architecture/dependencies.md)
- [Tech Debt](tech-debt.md)
