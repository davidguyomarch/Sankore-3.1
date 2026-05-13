add_library(sankore_desktop STATIC
    UBCustomCaptureWindow.cpp
    UBCustomCaptureWindow.h
    UBDesktopAnnotationController.cpp
    UBDesktopAnnotationController.h
    UBDesktopPalette.cpp
    UBDesktopPalette.h
    UBDesktopPropertyPalette.cpp
    UBDesktopPropertyPalette.h
    UBWindowCapture.h
)

if(WIN32)
    target_sources(sankore_desktop PRIVATE
        UBWindowCapture_win.cpp
        UBWindowCaptureDelegate_win.cpp
        UBWindowCaptureDelegate_win.h
    )
endif()

if(APPLE)
    target_sources(sankore_desktop PRIVATE UBWindowCapture_mac.mm)
endif()

if(UNIX AND NOT APPLE)
    target_sources(sankore_desktop PRIVATE UBWindowCapture_linux.cpp)
endif()

target_include_directories(sankore_desktop PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(sankore_desktop PUBLIC
    sankore_core
    sankore_gui
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)
