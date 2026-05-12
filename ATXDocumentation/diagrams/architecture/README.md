# Architecture Diagrams

## System Context

```
┌─────────────────────────────────────────────────────────────┐
│                    External Systems                           │
├──────────┬──────────┬───────────┬──────────┬───────────────┤
│  Web     │ YouTube  │ Intranet  │ Update   │ File System   │
│ Content  │ Upload   │ Publish   │ Server   │ (Documents)   │
└────┬─────┴────┬─────┴─────┬────┴────┬─────┴───────┬───────┘
     │          │            │         │             │
     ▼          ▼            ▼         ▼             ▼
┌─────────────────────────────────────────────────────────────┐
│                                                              │
│                    Open-Sankoré 2.5.1                        │
│                                                              │
│  ┌──────────┐  ┌──────────┐  ┌──────────┐                  │
│  │  Board   │  │   Web    │  │ Document │                  │
│  │  Mode    │  │  Browser │  │ Manager  │                  │
│  └──────────┘  └──────────┘  └──────────┘                  │
│                                                              │
│  ┌──────────┐  ┌──────────┐  ┌──────────┐                  │
│  │ Podcast  │  │ Desktop  │  │  Widget  │                  │
│  │ Record   │  │ Annotate │  │ Engine   │                  │
│  └──────────┘  └──────────┘  └──────────┘                  │
│                                                              │
└─────────────────────────────────────────────────────────────┘
     │          │            │
     ▼          ▼            ▼
┌──────────┐ ┌──────────┐ ┌──────────┐
│  Teacher │ │  Student │ │  Admin   │
│  (User)  │ │ (Viewer) │ │          │
└──────────┘ └──────────┘ └──────────┘
```

## Deployment Architecture

```
┌───────────────────────────────────────────────────┐
│              Local Machine (Desktop)               │
├───────────────────────────────────────────────────┤
│                                                    │
│  ┌──────────────────────────────────────────┐     │
│  │         Open-Sankoré Application          │     │
│  │                                           │     │
│  │  ┌─────────┐  ┌────────┐  ┌─────────┐   │     │
│  │  │   Qt    │  │ OpenSSL│  │ QuaZIP  │   │     │
│  │  │Framework│  │(crypto)│  │  (zip)  │   │     │
│  │  └─────────┘  └────────┘  └─────────┘   │     │
│  └──────────────────────────────────────────┘     │
│                                                    │
│  ┌──────────────────────────────────────────┐     │
│  │          Document Repository              │     │
│  │  ~/Sankore/documents/                     │     │
│  │  ├── document-uuid-1/                     │     │
│  │  │   ├── metadata.rdf                     │     │
│  │  │   ├── page001.svg                      │     │
│  │  │   ├── images/                          │     │
│  │  │   └── widgets/                         │     │
│  │  └── document-uuid-2/                     │     │
│  └──────────────────────────────────────────┘     │
│                                                    │
│  ┌──────────────────┐  ┌────────────────────┐     │
│  │  Display 1       │  │  Display 2         │     │
│  │  (Control View)  │  │  (Presentation)    │     │
│  └──────────────────┘  └────────────────────┘     │
│                                                    │
└───────────────────────────────────────────────────┘
```

## Integration Points

```
Open-Sankoré
    │
    ├── [HTTP/HTTPS] ──► Web Content (any URL)
    │                    - Embedded browser (QtWebKit)
    │                    - OEmbed resolution
    │                    - Widget downloads
    │
    ├── [HTTP/HTTPS] ──► YouTube API
    │                    - Video podcast upload
    │                    - OAuth authentication
    │
    ├── [FTP/HTTP] ───► Intranet Server
    │                    - Podcast publishing
    │                    - Document sharing
    │
    ├── [HTTP] ───────► Update Server
    │                    - Version check (QHttp)
    │                    - Download update package
    │
    ├── [File I/O] ───► Local File System
    │                    - Document repository
    │                    - Library resources
    │                    - Temp files
    │                    - Export/import
    │
    ├── [IPC] ────────► QtSingleApplication
    │                    - Inter-process messaging
    │                    - File open from second instance
    │
    └── [Display] ────► Multi-Monitor System
                         - Primary: Control view
                         - Secondary: Presentation view
```

## Service Communication

```
┌────────────────────────────────────────────┐
│            Application Process              │
│                                             │
│  ┌─────────┐    signals     ┌───────────┐  │
│  │ Board   │ ◄────────────► │    GUI    │  │
│  │Controller│               │  Palettes │  │
│  └────┬────┘                └───────────┘  │
│       │                                     │
│       │ direct calls                        │
│       ▼                                     │
│  ┌─────────┐    signal      ┌───────────┐  │
│  │  Scene  │ ──────────────►│   Undo    │  │
│  │         │                │   Stack   │  │
│  └────┬────┘                └───────────┘  │
│       │                                     │
│       │ persist                             │
│       ▼                                     │
│  ┌─────────┐    serialize   ┌───────────┐  │
│  │Persist  │ ──────────────►│   SVG     │  │
│  │Manager  │                │  Adaptor  │  │
│  └────┬────┘                └─────┬─────┘  │
│       │                           │         │
│       │ cache                     │ write   │
│       ▼                           ▼         │
│  ┌─────────┐                ┌───────────┐  │
│  │  Scene  │                │   File    │  │
│  │  Cache  │                │  System   │  │
│  └─────────┘                └───────────┘  │
│                                             │
│  ┌─────────┐    async       ┌───────────┐  │
│  │Download │ ──────────────►│  Network  │  │
│  │ Thread  │                │  (HTTP)   │  │
│  └─────────┘                └───────────┘  │
│                                             │
└────────────────────────────────────────────┘
```
