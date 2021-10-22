cmake_minimum_required(VERSION 3.0.0)
project(SimpleGraphics VERSION 0.1.0)

add_executable(SimpleGraphics
    src/main.cpp

    src/graphics/array.cpp
    src/graphics/window.cpp
)

file(COPY "assets" DESTINATION "${CMAKE_BINARY_DIR}")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_CXX_STANDARD 20)

target_link_libraries(SimpleGraphics "-lGL -lglfw -lGLEW")

include(CPack)