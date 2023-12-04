cmake_minimum_required(VERSION 3.14)

project(CMaizePrivateDepend VERSION 1.0.0 LANGUAGES CXX)

set(
    CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${PROJECT_SOURCE_DIR}/cmake"
    CACHE STRING "" FORCE
)

include(get_cmaize)

# Get dependencies
cmaize_find_or_build_dependency(
    CMakePrivate
    URL https://github.com/CMaizeExamples/CMakePrivate.git
    PRIVATE TRUE
    BUILD_TARGET CMakePrivate
    FIND_TARGET CMakePrivate::CMakePrivate
    CMAKE_ARGS BUILD_TESTING=FALSE
)

# Build the library
cmaize_add_library(
    ${PROJECT_NAME}
    INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/include/cmaize_private_depend"
    SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/src/cmaize_private_depend"
    DEPENDS CMakePrivate
)

if (BUILD_TESTING)
    # Build tests
    cmaize_find_or_build_dependency(
        Catch2
        URL github.com/catchorg/Catch2
        BUILD_TARGET Catch2
        FIND_TARGET Catch2::Catch2WithMain
        VERSION v3.4.0
    )

    cmaize_add_tests(
        test_${PROJECT_NAME}
        SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/test/cmaize_private_depend"
        INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/src/cmaize_private_depend"
        DEPENDS Catch2::Catch2WithMain ${PROJECT_NAME}
    )
endif()

# Install the package
cmaize_add_package(${PROJECT_NAME})
