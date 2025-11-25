cmake_minimum_required(VERSION 3.20)
project(DSP VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Header-only library
add_library(dsp INTERFACE)
target_include_directories(dsp INTERFACE include)

# Tests
enable_testing()

# FFT test
add_executable(test_fft tests/fft_testbench.cpp)
target_include_directories(test_fft PRIVATE include/external)
target_link_libraries(test_fft PRIVATE dsp)
add_test(NAME FFTTest COMMAND test_fft --success --reporter=compact)

# Convolution test
add_executable(test_convolution tests/conv_testbench.cpp)
target_include_directories(test_convolution PRIVATE include/external)
target_link_libraries(test_convolution PRIVATE dsp)
add_test(NAME ConvolutionTest COMMAND test_convolution --success --reporter=compact)
