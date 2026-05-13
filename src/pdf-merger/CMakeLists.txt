file(GLOB PDF_MERGER_SOURCES "*.cpp")
file(GLOB PDF_MERGER_HEADERS "*.h")

add_library(sankore_pdf_merger STATIC
    ${PDF_MERGER_SOURCES}
    ${PDF_MERGER_HEADERS}
)

target_include_directories(sankore_pdf_merger PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(sankore_pdf_merger PUBLIC
    Qt6::Core
)

find_package(ZLIB REQUIRED)
target_link_libraries(sankore_pdf_merger PRIVATE ZLIB::ZLIB)
