add_library(sankore_tools STATIC
    UBAbstractDrawRuler.cpp
    UBAbstractDrawRuler.h
    UBGraphicsAristo.cpp
    UBGraphicsAristo.h
    UBGraphicsCache.cpp
    UBGraphicsCache.h
    UBGraphicsCompass.cpp
    UBGraphicsCompass.h
    UBGraphicsCurtainItem.cpp
    UBGraphicsCurtainItem.h
    UBGraphicsCurtainItemDelegate.cpp
    UBGraphicsCurtainItemDelegate.h
    UBGraphicsProtractor.cpp
    UBGraphicsProtractor.h
    UBGraphicsRuler.cpp
    UBGraphicsRuler.h
    UBGraphicsTriangle.cpp
    UBGraphicsTriangle.h
    UBToolsManager.cpp
    UBToolsManager.h
)

target_include_directories(sankore_tools PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(sankore_tools PUBLIC
    sankore_domain
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)
