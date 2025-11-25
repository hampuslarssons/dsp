# Signal Processing Library

## Summary
A signal processing library currently implementing the FFT using the Radix-2 with bit reversal method. It also supports discrete time-domain convolution (as defined by Damelin & Miller) and FFT convolution.
- Header-only C++ signal processing library
- Templated Design
- Fast Fourier Transform
- Convolution

## Structure
- `include/dsp/fft.hpp` - Header file for FFT and Inverse FFT functions.
- `include/dsp/conv.hpp` - Header file for convolution functions.
- `tests/fft_testbench.cpp` - Testbench for FFT and Inverse FFT functions using Catch2.
- `tests/conv_testbench.cpp` - Testbench for convolution functions using Catch2.

## Usage
### Build Instructions
First, ensure you have cmake (example using *brew*):

```
brew install cmake
```

Build using:
```
cmake -S . -B build && cmake --build build
```
### Run Testbench
Testing is performed using the [Catch2](https://github.com/catchorg/Catch2) framework. After building navigate to the *build* directory and execute:

```
ctest
```
### Usage Example - FFT
```
#include "dsp/fft.hpp"
#include <vector>
#include <complex>

// Make sure to use the 'dsp' namespace or prefix functions with 'dsp::'
std::vector<std::complex<double>> signal = {1,0,0,0};
dsp::fft(signal); // Fast Fourier Transform, FFT
dsp::ifft(signal); // Inverse Fourier Transform, IFFT
```
### Usage Example - FFT Convolution
```
#include "dsp/conv.hpp"
#include <vector>
#include <complex>

// Make sure to use the 'dsp' namespace or prefix functions with 'dsp::'
std::vector<std::complex<double>> f = {1, 2, 3};
std::vector<std::complex<double>> g = {0, 1, 0.5};
std::vector<std::complex<double>> result = dsp::fft_convolve(f, g); // FFT-based convolution
```