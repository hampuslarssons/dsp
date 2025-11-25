#pragma once

#include <vector>
#include <complex>
#include "util.hpp"
#include <cmath>

namespace dsp {
    
    /*
    *Summary: Calculate iterative FFT using radix-2 and bit-reversal
    */
    template<typename T>
    void fft(std::vector<std::complex<T>> & data) {
        std::complex<T> i(0, 1); // Define imaginary unit

        // Safe use of bit-reverse-copy
        std::vector<std::complex<T>> temp;
        dsp::bit_reverse_copy(data, temp);
        data = std::move(temp);

        int n = data.size();
        int bits = std::log2(n); // Number of stages, log2 works here, presumably since n is a power of 2.

        for (int s = 0; s < bits; s++){
            int m = 1 << (s+1); // Using shift instead of pow since i got accuracy errors using pow
            std::complex<T> omega_m = std::exp(-2.0 * M_PI * i / static_cast<T>(m));

            // This is the 'for' that does the butterfly operations, see Cooley-Tukey
            for (int k = 0; k < n ; k+=m){
                std::complex<T> omega(1, 0);
                for(int j = 0; j < m/2; j++){
                    std::complex<T> t = omega * data[k + j + m/2];
                    std::complex<T> u = data[k + j];
                    data[k + j] = u + t;
                    data[k + j + m/2] = u - t;
                    omega = omega * omega_m;
                }
            }
        }
    }
    /*
    * Summary: Calculate iterative inverse FFT using radix-2 and bit-reversal
    */
    template<typename T>
    void ifft(std::vector<std::complex<T>> & data){
        for (auto& x : data) {
            x = std::conj(x); //Conjugate
        }

        dsp::fft(data); // FFT
        
        for (auto& x : data) {
            x = std::conj(x); // Conjugate
            x = x / static_cast<T>(data.size()); // Normalize by N
        }
    }

}