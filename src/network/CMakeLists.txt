add_library(sankore_network STATIC
    UBAutoSaver.cpp
    UBAutoSaver.h
    UBCookieJar.cpp
    UBCookieJar.h
    UBHttpFileDownloader.cpp
    UBHttpFileDownloader.h
    UBHttpGet.cpp
    UBHttpGet.h
    UBNetworkAccessManager.cpp
    UBNetworkAccessManager.h
    UBServerXMLHttpRequest.cpp
    UBServerXMLHttpRequest.h
)

target_include_directories(sankore_network PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(sankore_network PUBLIC
    sankore_core
    Qt6::Core
    Qt6::Network
)
