cmake_minimum_required(VERSION 3.20)
project(DSP VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include headers
include_directories(include)

# Library source files
add_library(fast_dsp
    src/fft.cpp
    src/convolution.cpp
)

# Tests
enable_testing()
add_executable(test_fft tests/test_fft.cpp)
target_link_libraries(test_fft fast_dsp)
add_test(NAME FFTTest COMMAND test_fft)

add_executable(test_convolution tests/test_convolution.cpp)
target_link_libraries(test_convolution fast_dsp)
add_test(NAME ConvolutionTest COMMAND test_convolution)
