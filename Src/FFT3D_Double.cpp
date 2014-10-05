#include "FFT3D_Double.h"
#include "Profiler.h"

#include <iostream>
#include <sstream>
#include <omp.h>

/**
 * @brief serialFFT3D_DOUBLE
 * @param data
 * @param N
 */
void serialFFT3D_DOUBLE(fftw_complex* data, const int N) {

    // 3D FFT plan
    fftw_plan fftPlan = fftw_plan_dft_3d(N, N, N, data, data,
                                           FFTW_FORWARD, FFTW_ESTIMATE);

    // Execution
    START_PROFILING();
    fftw_execute(fftPlan);
    END_PROFILING();

    std::stringstream log;
    log << "In-place serialFFT3D_DOUBLE for volume size of : "
        << "[" << N << "x" << N << "x" << N << "]"
        << " and type " << "fftw_complex" << " is : ";
    profile.PrintProfile (log.str ());

    // Cleaning
    fftw_destroy_plan (fftPlan);
    fftw_cleanup ();
}


/**
 * @brief serialFFT3D
 * @param input
 * @param output
 * @param N
 */
void serialFFT3D_DOUBLE(const fftw_complex* input, fftw_complex* output, const int N) {

    // 3D FFT plan
    fftw_plan fftPlan = fftw_plan_dft_3d(N, N, N, input, output,
                                           FFTW_FORWARD, FFTW_ESTIMATE);

    // Execution
    START_PROFILING();
    fftw_execute(fftPlan);
    END_PROFILING();

    std::stringstream log;
    log << "Out-of-place serialFFT3D_DOUBLE for volume size of : "
        << "[" << N << "x" << N << "x" << N << "]"
        << " and type " << "fftw_complex" << " is : ";
    profile.PrintProfile (log.str ());

    // Cleaning
    fftw_destroy_plan (fftPlan);
    fftw_cleanup ();
}


/**
 * @brief parallelFFT3D
 * @param data
 * @param N
 * @param numThreads
 */
void parallelFFT3D_DOUBLE(fftw_complex* data, const int N, const int numThreads) {

    // Initialization
    if (!fftw_init_threads()) {
        std::cout << "Initialization problem for parallel FFT" << std::endl;
        return;
    }

    fftw_plan_with_nthreads(numThreads);
    omp_set_num_threads(numThreads);

    // 3D FFT plan
    fftw_plan fftPlan = fftw_plan_dft_3d(N, N, N, data, data,
                                           FFTW_FORWARD, FFTW_ESTIMATE);

    START_PROFILING();
    fftw_execute(fftPlan);
    END_PROFILING();
    std::stringstream log;
    log << "In-place parallelFFT3D_DOUBLE for volume size of : "
        << "[" << N << "x" << N << "x" << N << "]"
        << " and type " << "fftw_complex" << " is : ";
    profile.PrintProfile (log.str ());

    // Cleaning
    fftw_destroy_plan (fftPlan);
    fftw_cleanup_threads();
}


/**
 * @brief parallelFFT3D
 * @param input
 * @param output
 * @param N
 * @param numThreads
 */
void parallelFFT3D_DOUBLE(const fftw_complex* input, fftw_complex* output,
                   const int N, const int numThreads) {

    // Initialization
    if (!fftw_init_threads()) {
        std::cout << "Initialization problem for parallel FFT" << std::endl;
        return;
    }

    fftw_plan_with_nthreads(numThreads);
    omp_set_num_threads(numThreads);

    // 3D FFT plan
    fftw_plan fftPlan = fftw_plan_dft_3d(N, N, N, input, output,
                                           FFTW_FORWARD, FFTW_ESTIMATE);

    START_PROFILING();
    fftw_execute(fftPlan);
    END_PROFILING();
    std::stringstream log;
    log << "Out-of-place parallelFFT3D_DOUBLE for volume size of : "
        << "[" << N << "x" << N << "x" << N << "]"
        << " and type " << "fftw_complex" << " is : ";
    profile.PrintProfile (log.str ());

    // Cleaning
    fftw_destroy_plan (fftPlan);
    fftw_cleanup_threads();
}
