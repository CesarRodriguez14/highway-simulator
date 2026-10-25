add_library(highway)

target_sources(
    highway
    PRIVATE
    highway.cpp
)

target_include_directories(
    highway
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)