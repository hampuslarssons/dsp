#define CATCH_CONFIG_MAIN
#include "external/catch.hpp"
#include "conv.hpp"

#include <complex>
#include <vector>
#include <cmath>

TEST_CASE("Dimension of Time Domain Convolution") {
    using T = double;
    constexpr std::size_t EXPECTED_SIZE = 15;

    std::vector<std::complex<T>> f = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
    std::vector<std::complex<T>> g = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};

    std::vector<std::complex<T>> f_conv_g = dsp::time_domain_convolve(f,g);

    REQUIRE(f_conv_g.size() == EXPECTED_SIZE);
}

TEST_CASE("Expected output of Time Domain Convolution") {
    using T = double;

    std::vector<std::complex<T>> f = {1.0, 3.0, 1.0, 0.0};
    std::vector<std::complex<T>> g = {0.0, 1.0, 0.0, 1.0};
    std::vector<std::complex<T>> expected_output = {0.0, 1.0, 3.0, 2.0, 3.0, 1.0, 0.0};

    std::vector<std::complex<T>> f_conv_g = dsp::time_domain_convolve(f,g);

    REQUIRE(f_conv_g.size() == expected_output.size());
    for (std::size_t i = 0; i < expected_output.size(); ++i) {
        REQUIRE(f_conv_g[i].real() == Approx(expected_output[i].real()));
        REQUIRE(f_conv_g[i].imag() == Approx(expected_output[i].imag()));
    }
}

TEST_CASE("Dimension of FFT Convolution") {
    using T = double;
    constexpr std::size_t EXPECTED_SIZE = 15;

    std::vector<std::complex<T>> f = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};
    std::vector<std::complex<T>> g = {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0};

    std::vector<std::complex<T>> f_conv_g = dsp::fft_convolve(f,g);

    REQUIRE(f_conv_g.size() == EXPECTED_SIZE);
}

TEST_CASE("Expected output of FFT Convolution") {
    using T = double;

    std::vector<std::complex<T>> f = {1.0, 3.0, 1.0, 0.0};
    std::vector<std::complex<T>> g = {0.0, 1.0, 0.0, 1.0};
    std::vector<std::complex<T>> expected_output = {0.0, 1.0, 3.0, 2.0, 3.0, 1.0, 0.0};
    std::vector<std::complex<T>> f_conv_g = dsp::fft_convolve(f,g);

    REQUIRE(f_conv_g.size() == expected_output.size());
    for (std::size_t i = 0; i < expected_output.size(); ++i) {
        REQUIRE(f_conv_g[i].real() == Approx(expected_output[i].real()).margin(1e-12));
        REQUIRE(f_conv_g[i].imag() == Approx(expected_output[i].imag()).margin(1e-12));
    }
}


