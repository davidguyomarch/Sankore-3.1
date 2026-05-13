add_library(sankore_customwidgets STATIC
    UBActionableWidget.cpp
    UBActionableWidget.h
    UBGraphicsItemAction.cpp
    UBGraphicsItemAction.h
    UBMediaWidget.cpp
    UBMediaWidget.h
)

target_include_directories(sankore_customwidgets PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(sankore_customwidgets PUBLIC
    sankore_core
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::Multimedia
)
