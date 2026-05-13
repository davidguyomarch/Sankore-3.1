cmake_minimum_required(VERSION 3.16)

find_package(Qt6 COMPONENTS Core Gui Widgets Test REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(OpenSankoreTests
    main.cpp
    tst_UBStringUtils.cpp
    tst_UBStringUtils.h
    tst_UBFileSystemUtils.cpp
    tst_UBFileSystemUtils.h
    tst_UBGeometryUtils.cpp
    tst_UBGeometryUtils.h
    tst_UBCryptoUtils.cpp
    tst_UBCryptoUtils.h
    tst_UBDocumentProxy.cpp
    tst_UBDocumentProxy.h
    tst_UBSettings.cpp
    tst_UBSettings.h
    # Sources under test
    ../src/frameworks/UBStringUtils.cpp
    ../src/frameworks/UBGeometryUtils.cpp
    # Stubs
    stubs/UBFileSystemUtils_stub.cpp
    stubs/UBFileSystemUtils_stub.h
    stubs/UBCryptoUtils_stub.cpp
    stubs/UBCryptoUtils_stub.h
    stubs/UBSettings_stub.cpp
    stubs/UBSettings_stub.h
    stubs/UBDocumentManager_stub.cpp
    stubs/UBDocumentManager_stub.h
    stubs/UBDocumentProxy_stub.cpp
    stubs/UBDocumentProxy_stub.h
    stubs/UBPlatformUtils_stub.cpp
    stubs/UBPlatformUtils_stub.h
)

target_include_directories(OpenSankoreTests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../src
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(OpenSankoreTests PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::Test
    OpenSSL::Crypto
)

find_package(OpenSSL REQUIRED)

# Code coverage
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(OpenSankoreTests PRIVATE --coverage)
    target_link_options(OpenSankoreTests PRIVATE --coverage)
endif()

# Set output directory
set_target_properties(OpenSankoreTests PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build
)

add_test(NAME OpenSankoreTests COMMAND OpenSankoreTests)
