add_library(sankore_core STATIC
    main.cpp
    UBApplication.cpp
    UBApplication.h
    UBSettings.cpp
    UBSettings.h
    UBSetting.cpp
    UBSetting.h
    UBPersistenceManager.cpp
    UBPersistenceManager.h
    UBSceneCache.cpp
    UBSceneCache.h
    UBPreferencesController.cpp
    UBPreferencesController.h
    UBMimeData.cpp
    UBMimeData.h
    UBIdleTimer.cpp
    UBIdleTimer.h
    UBDisplayManager.cpp
    UBDisplayManager.h
    UBDocumentManager.cpp
    UBDocumentManager.h
    UBApplicationController.cpp
    UBApplicationController.h
    UBDownloadManager.cpp
    UBDownloadManager.h
    UBDownloadThread.cpp
    UBDownloadThread.h
    UBTextTools.cpp
    UBTextTools.h
    UBForeignObjectsHandler.cpp
    UBForeignObjectsHandler.h
    UB.h
)

target_include_directories(sankore_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(sankore_core PUBLIC
    sankore_frameworks
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::Network
    Qt6::Svg
    Qt6::Xml
)
