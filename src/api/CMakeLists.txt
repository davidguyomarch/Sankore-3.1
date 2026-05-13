add_library(sankore_api STATIC
    UBWidgetUniboardAPI.cpp
    UBWidgetUniboardAPI.h
    UBW3CWidgetAPI.cpp
    UBW3CWidgetAPI.h
    UBWidgetMessageAPI.cpp
    UBWidgetMessageAPI.h
    UBLibraryAPI.cpp
    UBLibraryAPI.h
)

target_include_directories(sankore_api PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(sankore_api PUBLIC
    sankore_core
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::Qml
    Qt6::WebEngineWidgets
)
