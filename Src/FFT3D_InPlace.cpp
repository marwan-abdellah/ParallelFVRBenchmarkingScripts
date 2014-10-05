#include "FFT3D_InPlace.h"
#include "Profiler.h"
#include "RandomNumberGeneration.h"
#include "FFT3D_Single.h"
#include "FFT3D_Double.h"

#include <iostream>

/**
 * @brief FFT3D_IN_PLACE
 * @param n
 * @param threading
 * @param precision
 * @param numThreads
 */
void FFT3D_IN_PLACE(const int n, const THREADING threading,
                    const PRECISION precision, const int numThreads) {
    if (threading == SERIAL) {
        switch (precision) {
        case SINGLE_PRECISION: {
            // Allocate the arrays
            std::cout << "Allocation" << std::endl;
            const int imageSize = n * n * n;
            fftwf_complex* a = new fftwf_complex[imageSize];

            std::cout << "Initialization" << std::endl;
            for (int i = 0; i < imageSize; i++) {
                a[i][0] = RNG (float(0));
                a[i][1] = RNG (float(0));
            }

            // Extecute operation
            std::cout << "Executing operation" << std::endl;
            serialFFT3D_SINGLE (a, n);

            // Free array
            std::cout << "Freeing memory" << std::endl;
            delete [] a;

            break;
        }
        case DOUBLE_PRECISION: {

            // Allocate the arrays
            std::cout << "Allocation" << std::endl;
            const int imageSize = n * n * n;
            fftw_complex* a = new fftw_complex[imageSize];

            std::cout << "Initialization" << std::endl;
            for (int i = 0; i < imageSize; i++) {
                a[i][0] = RNG (double(0));
                a[i][1] = RNG (double(0));
            }

            // Extecute operation
            std::cout << "Executing operation" << std::endl;
            serialFFT3D_DOUBLE (a, n);

            // Free array
            std::cout << "Freeing memory" << std::endl;
            delete [] a;

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
            const int imageSize = n * n * n;
            fftwf_complex* a = new fftwf_complex[imageSize];

            std::cout << "Initialization" << std::endl;
            for (int i = 0; i < imageSize; i++) {
                a[i][0] = RNG (float(0));
                a[i][1] = RNG (float(0));
            }

            // Extecute operation
            std::cout << "Executing operation" << std::endl;
            parallelFFT3D_SINGLE (a, n, numThreads);

            // Free array
            std::cout << "Freeing memory" << std::endl;
            delete [] a;

            break;
        }
        case DOUBLE_PRECISION: {
            // Allocate the arrays
            std::cout << "Allocation" << std::endl;
            const int imageSize = n * n * n;
            fftw_complex* a = new fftw_complex[imageSize];

            std::cout << "Initialization" << std::endl;
            for (int i = 0; i < imageSize; i++) {
                a[i][0] = RNG (double(0));
                a[i][1] = RNG (double(0));
            }

            // Extecute operation
            std::cout << "Executing operation" << std::endl;
            parallelFFT3D_DOUBLE (a, n, numThreads);

            // Free array
            std::cout << "Freeing memory" << std::endl;
            delete [] a;

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
