#pragma once

#include "util.hpp"
#include "fft.hpp"
#include <vector>
#include <complex>
#include <cmath>

namespace dsp {

    /*
    Time Domain convolution, discrete non-circular implemenatation. 
    Notaion according to Damelin & Miller 2011.
     
    */
    template <typename T>
    std::vector<T> time_domain_convolve(
        const std::vector<T>& f, 
        const std::vector<T>& g 
    ) {
        int f_size = f.size();
        int g_size = g.size();
        int M2 = f_size + g_size - 1; //output size
        std::vector<T> f_conv_g(M2, 0); // Initialize output with zeros

        for (int n = 0; n < M2; n++) {
            for (int m = 0; m < g_size; m++) {
                if (n - m >= 0 && n - m < f_size) {
                    f_conv_g[n] += f[n - m] * g[m];
                }
            }
        }
        return f_conv_g;
    }

    /*
    FFT convolution G (fft version of input g) multiplied onto F (fft version of input f)
    */
    template <typename T>
    std::vector<T> fft_convolve(
        const std::vector<T>& f,
        const std::vector<T>& g
    ) {
        size_t size = f.size() + g.size() - 1;
        size_t fft_size = dsp::calc_next_pow2(size);

        std::vector<T> F(fft_size, 0);
        std::vector<T> G(fft_size, 0);
        
        std::copy(f.begin(), f.end(), F.begin());
        std::copy(g.begin(), g.end(), G.begin());

        dsp::fft(F);
        dsp::fft(G);    

        for (size_t i = 0; i < fft_size; i++)
        {
            F[i] *= G[i];
        }
                 
        dsp::ifft(F);
        F.resize(size); // Resize to the correct output size
        
        return F;
    }

} // namespace dsp
