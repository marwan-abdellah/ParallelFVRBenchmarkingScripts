#include "FFT2D_OutofPlace.h"
#include "FFT2D_Single.h"
#include "FFT2D_Double.h"
#include "RandomNumberGeneration.h"

#include <iostream>

/**
 * @brief FFT2D_OUT_OF_PLACE
 * @param n
 * @param threading
 * @param precision
 * @param numThreads
 */
void FFT2D_OUT_OF_PLACE(const int n, const THREADING threading,
                    const PRECISION precision, const int numThreads) {

    if (threading == SERIAL) {
        switch (precision) {
        case SINGLE_PRECISION: {
            // Allocate the arrays
            std::cout << "Allocation" << std::endl;
            const int imageSize = n * n;
            fftwf_complex* a = new fftwf_complex[imageSize];
            fftwf_complex* b = new fftwf_complex[imageSize];

            std::cout << "Initialization" << std::endl;
            for (int i = 0; i < imageSize; i++) {
                a[i][0] = RNG (float(0));
                a[i][1] = RNG (float(0));

                // Output
                b[i][0] = 0.f;
                b[i][1] = 1.f;
            }

            // Do the FFT operation
            std::cout << "Executing operation" << std::endl;
            serialFFT2D_SINGLE (a, b, n);

            // Free array
            std::cout << "Freeing memory" << std::endl;
            delete [] a;
            delete [] b;

            break;
        }
        case DOUBLE_PRECISION: {
            // Allocate the arrays
            std::cout << "Allocation" << std::endl;
            const int imageSize = n * n;
            fftw_complex* a = new fftw_complex[imageSize];
            fftw_complex* b = new fftw_complex[imageSize];

            std::cout << "Initialization" << std::endl;
            for (int i = 0; i < imageSize; i++) {
                a[i][0] = RNG (float(0));
                a[i][1] = RNG (float(0));

                // Output
                b[i][0] = 0.f;
                b[i][1] = 1.f;
            }

            // Do the FFT operation
            std::cout << "Executing operation" << std::endl;
            serialFFT2D_DOUBLE (a, b, n);

            // Free array
            std::cout << "Freeing memory" << std::endl;
            delete [] a;
            delete [] b;

            break;
        }
        default:
            std::cout << "Wrong precision has been selected" << std::endl;
            break;
        }
    } else if (threading == PARALLEL) {
        switch (precision) {
        case SINGLE_PRECISION: {
            // Allocate the arrays
            std::cout << "Allocation" << std::endl;
            const int imageSize = n * n;
            fftwf_complex* a = new fftwf_complex[imageSize];
            fftwf_complex* b = new fftwf_complex[imageSize];

            std::cout << "Initialization" << std::endl;
            for (int i = 0; i < imageSize; i++) {
                a[i][0] = RNG (float(0));
                a[i][1] = RNG (float(0));

                // Output
                b[i][0] = 0.f;
                b[i][1] = 1.f;
            }

            // Do the FFT operation
            std::cout << "Executing operation" << std::endl;
            parallelFFT2D_SINGLE (a, b, n, numThreads);

            // Free array
            std::cout << "Freeing memory" << std::endl;
            delete [] a;
            delete [] b;

            break;
        }
        case DOUBLE_PRECISION: {
            // Allocate the arrays
            std::cout << "Allocation" << std::endl;
            const int imageSize = n * n;
            fftw_complex* a = new fftw_complex[imageSize];
            fftw_complex* b = new fftw_complex[imageSize];

            std::cout << "Initialization" << std::endl;
            for (int i = 0; i < imageSize; i++) {
                a[i][0] = RNG (float(0));
                a[i][1] = RNG (float(0));

                // Output
                b[i][0] = 0.f;
                b[i][1] = 1.f;
            }

            // Do the FFT operation
            std::cout << "Executing operation" << std::endl;
            parallelFFT2D_DOUBLE (a, b, n, numThreads);

            // Free array
            std::cout << "Freeing memory" << std::endl;
            delete [] a;
            delete [] b;

            break;
        }
        default:
            std::cout << "Wrong precision has been selected" << std::endl;
            break;
        }
    } else {
        std::cout << "Wrong threading has been selected" << std::endl;
    }

    return;
}
