# CMake generated Testfile for 
# Source directory: /Users/hampuslarsson/Dev/dsp
# Build directory: /Users/hampuslarsson/Dev/dsp/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[FFTTest]=] "/Users/hampuslarsson/Dev/dsp/build/test_fft" "--success" "--reporter=compact")
set_tests_properties([=[FFTTest]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/hampuslarsson/Dev/dsp/CMakeLists.txt;21;add_test;/Users/hampuslarsson/Dev/dsp/CMakeLists.txt;0;")
add_test([=[ConvolutionTest]=] "/Users/hampuslarsson/Dev/dsp/build/test_convolution")
set_tests_properties([=[ConvolutionTest]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/hampuslarsson/Dev/dsp/CMakeLists.txt;26;add_test;/Users/hampuslarsson/Dev/dsp/CMakeLists.txt;0;")
