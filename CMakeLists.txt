cmake_minimum_required(VERSION 3.20)
project(stdssg VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(stdssg 
    src/cli.cpp
    src/main.cpp
    src/site_builder.cpp
)

target_compile_options(stdssg PRIVATE -Wall -Wextra)
