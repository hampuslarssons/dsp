#define CATCH_CONFIG_MAIN
#include "external/catch.hpp"
#include "fft.hpp"

#include <complex>
#include <vector>
#include <cmath>

TEST_CASE("FFT of dirac delta") {
    using T = double;
    std::vector<std::complex<T>> data = {1, 0, 0, 0};

    dsp::fft(data);

    REQUIRE(data.size() == 4);

    // All outputs should be 1 + 0i
    for (auto &val : data) {
        REQUIRE(std::abs(val - std::complex<T>(1, 0)) < 1e-10);
    }
}

TEST_CASE("FFT followed by IFFT returns original data") {
    using T = double;
    std::vector<std::complex<T>> original = {
        1, 2, 3, 4
    };

    std::vector<std::complex<T>> data = original;

    dsp::fft(data);
    dsp::ifft(data);

    REQUIRE(data.size() == original.size());

    for (size_t i = 0; i < data.size(); ++i) {
        REQUIRE(std::abs(data[i] - original[i]) < 1e-10);
    }
}

TEST_CASE("FFT of sinusoid") {
    using T = double;
    const int N = 8;
    std::vector<std::complex<T>> data(N);
    
    for (int n = 0; n < N; ++n)
        data[n] = std::sin(2 * M_PI * n / N);

    std::vector<std::complex<T>> original = data;
    dsp::fft(data);
    dsp::ifft(data);

    for (int i = 0; i < N; ++i) {
        REQUIRE(std::abs(data[i] - original[i]) < 1e-10);
    }
}

TEST_CASE("FFT of large input") {
    using T = double;
    const int N = pow(2,8);
    std::vector<std::complex<T>> data(N);

    for (int n = 0; n < N; ++n) {
        data[n] = std::sin(2 * M_PI * n / N);
    }

    std::vector<std::complex<T>> original = data;
    dsp::fft(data);
    dsp::ifft(data);

    for (int i = 0; i < N; ++i) {
        REQUIRE(std::abs(data[i] - original[i]) < 1e-10);
    }

}

