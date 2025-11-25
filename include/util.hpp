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
        output.resize(n); // Ensure output has the correct size
        int bits = 0;
        for (int tmp = n; tmp > 1; tmp >>= 1) bits++; //tried log2 but got accuracy issues.

        // Bit Rreversal
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

   /*
   Calculate the next power of 2 for size
   */
    size_t calc_next_pow2(size_t size){
        size_t factor = 1;
        while (factor < size)
        {
            factor <<= 1; 
        }
        return factor;
    }
}