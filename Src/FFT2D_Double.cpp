#include "FFT2D_Double.h"
#include "Profiler.h"

#include <iostream>
#include <sstream>
#include <omp.h>

/**
 * @brief serialFFT2D_DOUBLE
 * @param data
 * @param N
 */
void serialFFT2D_DOUBLE(fftw_complex* data, const int N) {

    // 2D FFT plan
    fftw_plan fftPlan = fftw_plan_dft_2d(N, N, data, data,
                                         FFTW_BACKWARD, FFTW_ESTIMATE);

    // Execution
    START_PROFILING();
    fftw_execute(fftPlan);
    END_PROFILING();

    std::stringstream log;
    log << "In-place serialFFT2D_DOUBLE for volume size of : "
        << "[" << N << "x" << N << "]"
        << " and type " << "fftw_complex" << " is : ";
    profile.PrintProfile (log.str ());

    // Cleaning
    fftw_destroy_plan (fftPlan);
    fftw_cleanup ();
}


/**
 * @brief serialFFT2D
 * @param input
 * @param output
 * @param N
 */
void serialFFT2D_DOUBLE(const fftw_complex* input, fftw_complex* output,
                        const int N) {

    // 2D FFT plan
    fftw_plan fftPlan = fftw_plan_dft_2d(N, N, input, output,
                                         FFTW_BACKWARD, FFTW_ESTIMATE);

    // Execution
    START_PROFILING();
    fftw_execute(fftPlan);
    END_PROFILING();

    std::stringstream log;
    log << "Out-of-place serialFFT2D_DOUBLE for volume size of : "
        << "[" << N << "x" << N << "]"
        << " and type " << "fftw_complex" << " is : ";
    profile.PrintProfile (log.str ());

    // Cleaning
    fftw_destroy_plan (fftPlan);
    fftw_cleanup ();
}


/**
 * @brief parallelFFT2D
 * @param data
 * @param N
 * @param numThreads
 */
void parallelFFT2D_DOUBLE(fftw_complex* data,
                          const int N, const int numThreads) {

    // Initialization
    if (!fftw_init_threads()) {
        std::cout << "Initialization problem for parallel FFT" << std::endl;
        return;
    }

    fftw_plan_with_nthreads(numThreads);
    omp_set_num_threads(numThreads);

    // 2D FFT plan
    fftw_plan fftPlan = fftw_plan_dft_2d(N, N, data, data,
                                         FFTW_BACKWARD, FFTW_ESTIMATE);

    START_PROFILING();
    fftw_execute(fftPlan);
    END_PROFILING();
    std::stringstream log;
    log << "In-place parallelFFT2D_DOUBLE for volume size of : "
        << "[" << N << "x" << N << "]"
        << " and type " << "fftw_complex" << " is : ";
    profile.PrintProfile (log.str ());

    // Cleaning
    fftw_destroy_plan (fftPlan);
    fftw_cleanup_threads();
}


/**
 * @brief parallelFFT2D
 * @param input
 * @param output
 * @param N
 * @param numThreads
 */
void parallelFFT2D_DOUBLE(const fftw_complex* input, fftw_complex* output,
                          const int N, const int numThreads) {

    // Initialization
    if (!fftw_init_threads()) {
        std::cout << "Initialization problem for parallel FFT" << std::endl;
        return;
    }

    fftw_plan_with_nthreads(numThreads);
    omp_set_num_threads(numThreads);

    // 2D FFT plan
    fftw_plan fftPlan = fftw_plan_dft_2d(N, N, input, output,
                                         FFTW_BACKWARD, FFTW_ESTIMATE);

    START_PROFILING();
    fftw_execute(fftPlan);
    END_PROFILING();
    std::stringstream log;
    log << "Out-of-place parallelFFT2D_DOUBLE for volume size of : "
        << "[" << N << "x" << N << "]"
        << " and type " << "fftw_complex" << " is : ";
    profile.PrintProfile (log.str ());

    // Cleaning
    fftw_destroy_plan (fftPlan);
    fftw_cleanup_threads();
}
