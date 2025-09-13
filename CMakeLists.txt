cmake_minimum_required(VERSION 3.10)

project(ServerTest
    LANGUAGES C CXX
    VERSION 1.0.0
)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(FRAMEWORK_TARGET_NAME framework)
set(SERVER_TARGET_NAME ${PROJECT_NAME})

set(IPC_TARGET_NAME ipcInterface)

set(OUTPUT_DIR ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(framework)
add_subdirectory(external)

add_subdirectory(server)
