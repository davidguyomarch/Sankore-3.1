add_library(sankore_document STATIC
    UBDocumentContainer.cpp
    UBDocumentContainer.h
    UBDocumentController.cpp
    UBDocumentController.h
    UBDocumentProxy.cpp
    UBDocumentProxy.h
    UBSortFilterProxyModel.cpp
    UBSortFilterProxyModel.h
)

target_include_directories(sankore_document PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(sankore_document PUBLIC
    sankore_core
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)
