cmake_minimum_required(VERSION 3.16)

set(PROJECT_NAME Vulgine)

project(${PROJECT_NAME} VERSION 1.0 LANGUAGES CXX)

add_library(VulgineLib
    Src/Engine/engine.cpp
    Src/Window/window.cpp
)
target_include_directories(VulgineLib
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Include
)
target_compile_features(VulgineLib PUBLIC cxx_std_20)

add_executable(${PROJECT_NAME}
    main.cpp
)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE VulgineLib glfw vulkan)