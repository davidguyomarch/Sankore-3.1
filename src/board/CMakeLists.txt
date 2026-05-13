add_library(sankore_board STATIC
    UBBoardController.cpp
    UBBoardController.h
    UBBoardPaletteManager.cpp
    UBBoardPaletteManager.h
    UBBoardView.cpp
    UBBoardView.h
    UBDrawingController.cpp
    UBDrawingController.h
    UBFeaturesController.cpp
    UBFeaturesController.h
)

target_include_directories(sankore_board PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(sankore_board PUBLIC
    sankore_domain
    sankore_core
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)
