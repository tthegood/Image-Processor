cmake_minimum_required(VERSION 3.10)
project(ImageProcessing)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)

# Include directory for headers
include_directories(${PROJECT_SOURCE_DIR}/include)

# Core image library
add_library(image STATIC src/Image.cpp src/Sobel.cpp)
target_include_directories(image PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Tests
enable_testing()
add_executable(test_sobel tests/test_sobel.cpp)
target_include_directories(test_sobel PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(test_sobel PRIVATE image)
add_test(NAME SobelTest COMMAND test_sobel)

# Example executable
add_executable(sobel_example examples/main.cpp)
target_include_directories(sobel_example PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(sobel_example PRIVATE image)