#include "FFT3D_Single.h"
#include "Profiler.h"

#include <iostream>
#include <sstream>
#include <omp.h>

/**
 * @brief serialFFT3D_SINGLE
 * @param data
 * @param N
 */
void serialFFT3D_SINGLE(fftwf_complex* data, const int N) {

    // 3D FFT plan
    fftwf_plan fftPlan = fftwf_plan_dft_3d(N, N, N, data, data,
                                           FFTW_FORWARD, FFTW_ESTIMATE);

    // Execution
    START_PROFILING();
    fftwf_execute(fftPlan);
    END_PROFILING();

    std::stringstream log;
    log << "In-place serialFFT3D_SINGLE for volume size of : "
        << "[" << N << "x" << N << "x" << N << "]"
        << " and type " << "fftwf_complex" << " is : ";
    profile.PrintProfile (log.str ());

    // Cleaning
    fftwf_destroy_plan (fftPlan);
    fftwf_cleanup ();
}


/**
 * @brief serialFFT3D_SINGLE
 * @param input
 * @param output
 * @param N
 */
void serialFFT3D_SINGLE(const fftwf_complex* input, fftwf_complex* output,
                        const int N) {

    // 3D FFT plan
    fftwf_plan fftPlan = fftwf_plan_dft_3d(N, N, N, input, output,
                                           FFTW_FORWARD, FFTW_ESTIMATE);

    // Execution
    START_PROFILING();
    fftwf_execute(fftPlan);
    END_PROFILING();

    std::stringstream log;
    log << "Out-of-place serialFFT3D_SINGLE for volume size of : "
        << "[" << N << "x" << N << "x" << N << "]"
        << " and type " << "fftwf_complex" << " is : ";
    profile.PrintProfile (log.str ());

    // Cleaning
    fftwf_destroy_plan (fftPlan);
    fftwf_cleanup ();
}


/**
 * @brief parallelFFT3D_SINGLE
 * @param data
 * @param N
 * @param numThreads
 */
void parallelFFT3D_SINGLE(fftwf_complex* data, const int N,
                          const int numThreads) {

    // Initialization
    if (!fftwf_init_threads()) {
        std::cout << "Initialization problem for parallel FFT" << std::endl;
        return;
    }

    fftwf_plan_with_nthreads(numThreads);
    omp_set_num_threads(numThreads);

    // 3D FFT plan
    fftwf_plan fftPlan = fftwf_plan_dft_3d(N, N, N, data, data,
                                           FFTW_FORWARD, FFTW_ESTIMATE);

    START_PROFILING();
    fftwf_execute(fftPlan);
    END_PROFILING();
    std::stringstream log;
    log << "In-place parallelFFT3D_SINGLE for volume size of : "
        << "[" << N << "x" << N << "x" << N << "]"
        << " and type " << "fftwf_complex" << " is : ";
    profile.PrintProfile (log.str ());

    // Cleaning
    fftwf_destroy_plan (fftPlan);
    fftw_cleanup_threads();
}


/**
 * @brief parallelFFT3D_SINGLE
 * @param input
 * @param output
 * @param N
 * @param numThreads
 */
void parallelFFT3D_SINGLE(const fftwf_complex* input, fftwf_complex* output,
                   const int N, const int numThreads) {

    // Initialization
    if (!fftwf_init_threads()) {
        std::cout << "Initialization problem for parallel FFT" << std::endl;
        return;
    }

    fftwf_plan_with_nthreads(numThreads);
    omp_set_num_threads(numThreads);

    // 3D FFT plan
    fftwf_plan fftPlan = fftwf_plan_dft_3d(N, N, N, input, output,
                                           FFTW_FORWARD, FFTW_ESTIMATE);

    START_PROFILING();
    fftwf_execute(fftPlan);
    END_PROFILING();
    std::stringstream log;
    log << "Out-of-place parallelFFT3D_SINGLE for volume size of : "
        << "[" << N << "x" << N << "x" << N << "]"
        << " and type " << "fftwf_complex" << " is : ";
    profile.PrintProfile (log.str ());

    // Cleaning
    fftwf_destroy_plan (fftPlan);
    fftw_cleanup_threads();
}
