add_subdirectory(math)

add_executable(ray_tests ray_tests.cpp)
target_link_libraries(ray_tests shapes math CONAN_PKG::Catch2)
add_test(NAME ray_tests COMMAND $<TARGET_FILE:ray_tests>)