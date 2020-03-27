cmake_minimum_required(VERSION 3.12)

set(PROJECT_NAME ray_tracer)

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Werror -Wextra)

if (NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/v0.12/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake")
endif ()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_cmake_run(
        BASIC_SETUP
        CONANFILE conan_file.txt
        CMAKE_TARGETS
        BUILD missing)

add_subdirectory(src)
add_subdirectory(tests)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} math shapes)
