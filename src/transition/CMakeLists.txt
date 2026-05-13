add_library(sankore_transition STATIC
    UniboardSankoreTransition.cpp
    UniboardSankoreTransition.h
)

target_include_directories(sankore_transition PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(sankore_transition PUBLIC
    sankore_core
    Qt6::Core
)
