cmake_minimum_required(VERSION 3.16)
project(OpenSankore VERSION 2.5.1 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Find Qt 6
find_package(Qt6 COMPONENTS Core Gui Widgets Svg Network Multimedia Xml REQUIRED)
find_package(Qt6 COMPONENTS WebEngineWidgets QUIET)
if(NOT Qt6WebEngineWidgets_FOUND)
    message(WARNING "Qt6WebEngineWidgets not found - web engine features will be disabled")
    add_definitions(-DNO_WEBENGINE)
endif()

# Platform-specific configuration
if(APPLE)
    set(CMAKE_OSX_DEPLOYMENT_TARGET "12.0" CACHE STRING "Minimum macOS deployment target")
    set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64" CACHE STRING "Build architectures for macOS")
    enable_language(OBJCXX)
endif()

if(WIN32)π
    set(CMAKE_VS_PLATFORM_TOOLSET "v143" CACHE STRING "Visual Studio platform toolset")
    add_definitions(-D_WIN32_WINNT=0x0A00)  # Windows 10
endif()

# Global definitions
add_definitions(-DNO_THIRD_PARTY_WARNINGS)
add_definitions(-DUBVERSION=\"${PROJECT_VERSION}\")
add_definitions(-DVERSION_TYPE=\"r\")
add_definitions(-DVERSION_PATCH=\"1\")

# Third-party dependencies
# QuaZIP via FetchContent
include(FetchContent)
FetchContent_Declare(
    quazip
    GIT_REPOSITORY https://github.com/stachenov/quazip.git
    GIT_TAG v1.4
)
set(QUAZIP_QT_MAJOR_VERSION 6 CACHE STRING "" FORCE)
FetchContent_MakeAvailable(quazip)

# Include paths
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/plugins/cffadaptor/src)

# Module subdirectories
add_subdirectory(src/frameworks)
add_subdirectory(src/interfaces)
add_subdirectory(src/globals)
add_subdirectory(src/core)
add_subdirectory(src/network)
add_subdirectory(src/pdf)
add_subdirectory(src/pdf-merger)
add_subdirectory(src/domain)
add_subdirectory(src/tools)
add_subdirectory(src/adaptors)
add_subdirectory(src/document)
add_subdirectory(src/board)
add_subdirectory(src/web)
add_subdirectory(src/podcast)
add_subdirectory(src/gui)
add_subdirectory(src/desktop)
add_subdirectory(src/api)
add_subdirectory(src/customWidgets)
add_subdirectory(src/transition)

# Main executable
add_executable(OpenSankore)

target_link_libraries(OpenSankore PRIVATE
    sankore_frameworks
    sankore_interfaces
    sankore_globals
    sankore_core
    sankore_network
    sankore_pdf
    sankore_pdf_merger
    sankore_domain
    sankore_tools
    sankore_adaptors
    sankore_document
    sankore_board
    sankore_web
    sankore_podcast
    sankore_gui
    sankore_desktop
    sankore_api
    sankore_customwidgets
    sankore_transition
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::Svg
    Qt6::Network
    Qt6::Multimedia
    Qt6::Xml
    QuaZip::QuaZip
)
if(Qt6WebEngineWidgets_FOUND)
    target_link_libraries(OpenSankore PRIVATE Qt6::WebEngineWidgets)
endif()

if(APPLE)
    target_link_libraries(OpenSankore PRIVATE
        "-framework Foundation"
        "-framework AppKit"
    )
    find_library(CRYPTO_LIBRARY crypto)
    if(CRYPTO_LIBRARY)
        target_link_libraries(OpenSankore PRIVATE ${CRYPTO_LIBRARY})
    endif()
endif()

if(UNIX AND NOT APPLE)
    target_link_libraries(OpenSankore PRIVATE crypto X11)
    target_compile_options(OpenSankore PRIVATE -fopenmp)
    target_link_options(OpenSankore PRIVATE -fopenmp)
endif()

if(WIN32)
    target_link_libraries(OpenSankore PRIVATE Qt6::AxContainer)
endif()

# Resources
target_sources(OpenSankore PRIVATE
    resources/sankore.qrc
    plugins/cffadaptor/resources/resources.qrc
)

# UI Forms
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/resources/forms)

# Tests
enable_testing()
add_subdirectory(tests)
