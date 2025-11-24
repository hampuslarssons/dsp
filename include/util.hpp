#pragma once

#include <vector>
#include <complex>

namespace dsp {
    
    /*
    algorithm bit-reverse-copy(a,A):
    input: Array a of n complex values where n is a power of 2.
    output: Array A of size n.
    */
    template<typename T>
    void bit_reverse_copy(const std::vector<std::complex<T>> & input, std::vector<std::complex<T>> & output) {
        
        int n = input.size();
        output.resize(n);
        int bits = std::log2(n);

        for (int i = 0; i < n; i++) {
            int rev = 0;
            int x = i;

            for (int b = 0; b < bits; b++) {
                rev = (rev << 1) | (x & 1);
                x >>= 1;
            }

            output[rev] = input[i];
        }
    }    
}