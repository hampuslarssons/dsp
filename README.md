# Signal Processing Library
### by Hampus Larsson

## Summary
A signal processing library currently implementing the FFT using the Radix-2 with bit reversal method, as well as discrete time-domain convolution (as defined by Damelin & Miller). FFT convolution is TODO. 
### Features
- C++ Header-Only Signal Processing Library
- Templated Design

## Usage
### Build Instructions (Apple Silicon Mac)
First, ensure you have cmake:

```
brew install cmake
```

Build using:
```
cmake -S . -B build && cmake --build build
```
### Run FFT Testbench
Testing is performed using the Catch2 framework (https://github.com/catchorg/Catch2). In the current version of this library, testing is only supported for the FFT.

```
./build/test_fft
```
### Usage Example
```
#include "dsp/fft.hpp"
std::vector<std::complex<double>> signal = {1,0,0,0};
dsp::fft(signal); // Fast Fourier Transform, FFT
dsp::ifft(signal); // Inverse Fourier Transform, IFFT
```