cmake_minimum_required(VERSION 3.0.0)
project(foo VERSION 0.1.0)

add_library(foo SHARED foo/foo.cpp)
target_include_directories(foo
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/foo>
        $<INSTALL_INTERFACE:include/foo>)
target_compile_definitions(foo
    PRIVATE
        FOO_EXPORTS)

add_executable(foo_exe main.cpp)
target_link_libraries(foo_exe
    PUBLIC
        foo)
