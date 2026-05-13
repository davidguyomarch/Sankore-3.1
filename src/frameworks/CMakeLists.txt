add_library(sankore_frameworks STATIC
    UBGeometryUtils.cpp
    UBGeometryUtils.h
    UBPlatformUtils.cpp
    UBPlatformUtils.h
    UBFileSystemUtils.cpp
    UBFileSystemUtils.h
    UBStringUtils.cpp
    UBStringUtils.h
    UBVersion.cpp
    UBVersion.h
    UBCoreGraphicsScene.cpp
    UBCoreGraphicsScene.h
    UBCryptoUtils.cpp
    UBCryptoUtils.h
    UBBase32.cpp
    UBBase32.h
    UBTrashRegistery.cpp
    UBTrashRegistery.h
    UBWidgetUtils.cpp
    UBWidgetUtils.h
    UBImageUtils.cpp
    UBImageUtils.h
)

if(WIN32)
    target_sources(sankore_frameworks PRIVATE UBPlatformUtils_win.cpp)
endif()

if(APPLE)
    target_sources(sankore_frameworks PRIVATE UBPlatformUtils_mac.mm)
endif()

if(UNIX AND NOT APPLE)
    target_sources(sankore_frameworks PRIVATE UBPlatformUtils_linux.cpp)
endif()

target_include_directories(sankore_frameworks PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(sankore_frameworks PUBLIC
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)

find_package(OpenSSL REQUIRED)
target_link_libraries(sankore_frameworks PRIVATE OpenSSL::Crypto)

if(APPLE)
    target_link_libraries(sankore_frameworks PRIVATE "-framework Foundation" "-framework AppKit")
endif()

if(UNIX AND NOT APPLE)
    target_link_libraries(sankore_frameworks PRIVATE X11)
endif()
