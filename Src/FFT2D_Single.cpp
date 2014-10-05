#include "FFT2D_Single.h"
#include "Profiler.h"

#include <iostream>
#include <sstream>
#include <omp.h>

/**
 * @brief serialFFT2D_SINGLE
 * @param data
 * @param N
 */
void serialFFT2D_SINGLE(fftwf_complex* data, const int N) {

    // 2D FFT plan
    fftwf_plan fftPlan = fftwf_plan_dft_2d(N, N, data, data,
                                          FFTW_BACKWARD, FFTW_ESTIMATE);

    // Execution
    START_PROFILING();
    fftwf_execute(fftPlan);
    END_PROFILING();

    std::stringstream log;
    log << "In-place serialFFT2D_SINGLE for volume size of : "
        << "[" << N << "x" << N << "]"
        << " and type " << "fftwf_complex" << " is : ";
    profile.PrintProfile (log.str ());

    // Cleaning
    fftwf_destroy_plan (fftPlan);
    fftwf_cleanup ();
}


/**
 * @brief serialFFT2D_SINGLE
 * @param input
 * @param output
 * @param N
 */
void serialFFT2D_SINGLE(const fftwf_complex* input, fftwf_complex* output,
                        const int N) {

    // 2D FFT plan
    fftwf_plan fftPlan = fftwf_plan_dft_2d(N, N, input, output,
                                           FFTW_BACKWARD, FFTW_ESTIMATE);

    // Execution
    START_PROFILING();
    fftwf_execute(fftPlan);
    END_PROFILING();

    std::stringstream log;
    log << "Out-of-place serialFFT2D_SINGLE for volume size of : "
        << "[" << N << "x" << N << "]"
        << " and type " << "fftwf_complex" << " is : ";
    profile.PrintProfile (log.str ());

    // Cleaning
    fftwf_destroy_plan (fftPlan);
    fftwf_cleanup ();
}


/**
 * @brief parallelFFT2D_SINGLE
 * @param data
 * @param N
 * @param numThreads
 */
void parallelFFT2D_SINGLE(fftwf_complex* data, const int N,
                          const int numThreads) {

    // Initialization
    if (!fftwf_init_threads()) {
        std::cout << "Initialization problem for parallel FFT" << std::endl;
        return;
    }

    fftwf_plan_with_nthreads(numThreads);
    omp_set_num_threads(numThreads);

    // 2D FFT plan
    fftwf_plan fftPlan = fftwf_plan_dft_2d(N, N, data, data,
                                           FFTW_BACKWARD, FFTW_ESTIMATE);

    START_PROFILING();
    fftwf_execute(fftPlan);
    END_PROFILING();
    std::stringstream log;
    log << "In-place parallelFFT2D_SINGLE for volume size of : "
        << "[" << N << "x" << N << "]"
        << " and type " << "fftwf_complex" << " is : ";
    profile.PrintProfile (log.str ());

    // Cleaning
    fftwf_destroy_plan (fftPlan);
    fftw_cleanup_threads();
}


/**
 * @brief parallelFFT2D_SINGLE
 * @param input
 * @param output
 * @param N
 * @param numThreads
 */
void parallelFFT2D_SINGLE(const fftwf_complex* input, fftwf_complex* output,
                   const int N, const int numThreads) {

    // Initialization
    if (!fftwf_init_threads()) {
        std::cout << "Initialization problem for parallel FFT" << std::endl;
        return;
    }

    fftwf_plan_with_nthreads(numThreads);
    omp_set_num_threads(numThreads);

    // 2D FFT plan
    fftwf_plan fftPlan = fftwf_plan_dft_2d(N, N, input, output,
                                           FFTW_BACKWARD, FFTW_ESTIMATE);

    START_PROFILING();
    fftwf_execute(fftPlan);
    END_PROFILING();
    std::stringstream log;
    log << "Out-of-place parallelFFT2D_SINGLE for volume size of : "
        << "[" << N << "x" << N << "]"
        << " and type " << "fftwf_complex" << " is : ";
    profile.PrintProfile (log.str ());

    // Cleaning
    fftwf_destroy_plan (fftPlan);
    fftw_cleanup_threads();
}
