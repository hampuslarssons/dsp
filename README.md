# Signal Processing Library
### by Hampus Larsson

## Summary
A signal processing library currently implementing the FFT using the Radix-2 with bit reversal method, as well as discrete time-domain convolution (as defined by Damelin & Miller). FFT convolution is TODO. 
### Features
- C++ Header-Only Signal Processing Library
- Templated Design

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
Testing is performed using the Catch2 framework (https://github.com/catchorg/Catch2). After building navigate to the *build* directory and execute:

```
ctest
```
### Usage Example
```
#include "dsp/fft.hpp"
std::vector<std::complex<double>> signal = {1,0,0,0};
dsp::fft(signal); // Fast Fourier Transform, FFT
dsp::ifft(signal); // Inverse Fourier Transform, IFFT
```