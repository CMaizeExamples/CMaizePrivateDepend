cmake_minimum_required(VERSION 3.13.4)
project(CMaize_Private_Depend)

include("${PROJECT_SOURCE_DIR}/cmake/get_cpp.cmake")

set(CPP_GITHUB_TOKEN 3778029c236c9733e1d1595117c7e467b0ee6cd5)

cpp_find_or_build_dependency(
    CMakePrivate
    PRIVATE true
    URL github.com/CMaizeExamples/CMakePrivate
    VERSION ally
    BUILD_TARGET CMakePrivate
    FIND_TARGET CMakePrivate::CMakePrivate
)

cpp_add_library(
    CMaizePrivateDepend
    SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}"
    INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}"
    DEPENDS CMakePrivate
)

target_include_directories (CMaizePrivateDepend PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

message("Processing private depend...")
