add_library(sankore_pdf STATIC
    GraphicsPDFItem.cpp
    GraphicsPDFItem.h
    PDFRenderer.cpp
    PDFRenderer.h
    UBWebPluginPDFWidget.cpp
    UBWebPluginPDFWidget.h
    XPDFRenderer.cpp
    XPDFRenderer.h
)

target_include_directories(sankore_pdf PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(sankore_pdf PUBLIC
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)
