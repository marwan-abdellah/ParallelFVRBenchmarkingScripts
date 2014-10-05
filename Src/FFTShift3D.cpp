#include "FFTShift3D.h"
#include "Profiler.h"

#include <iostream>
#include <cstdlib>
#include <sys/time.h>
#include <time.h>
#include <cmath>
#include <math.h>
#include <string>
#include <vector>
#include <stdlib.h>
#include <typeinfo>

template <class T>
/**
 * @brief serialFFTShift3D
 * @param data
 * @param N
 */
void serialFFTShift3D(T* data, const int N)
{
    START_PROFILING();
    for (int i = 0; i < N/2; i++) {
        for(int j = 0; j < N/2; j++) {
            for (int k = 0; k < N/2; k++) {
                int idx1, idx2;

                // 1st and 8th octants
                idx1 = ((N/2) + i) + N * (((N/2) + j) + N * ((N/2) + k));
                idx2 = i + N * (j + N * k);

                T aux = data[idx1];
                data[idx1] = data[idx2];
                data[idx2] = aux;

                // 2nd and 7th octants
                idx1 = ((N/2) + i) + N * (j + N * ((N/2) + k));
                idx2 = i + N * (((N/2) + j) + N * k);

                aux = data[idx1];
                data[idx1] = data[idx2];
                data[idx2] = aux;

                // 3rd and 6th octants
                idx1 = i + N * (((N/2) + j) + N * ((N/2) + k));
                idx2 = ((N/2) + i) + N * (j + N * k);

                aux = data[idx1];
                data[idx1] = data[idx2];
                data[idx2] = aux;

                // 4th and 5th octants
                idx1 = i + N * (j + N * ((N/2) + k));
                idx2 = ((N/2) + i) + N * (((N/2) + j) + N * k);

                aux = data[idx1];
                data[idx1] = data[idx2];
                data[idx2] = aux;
            }
        }
    }
    END_PROFILING();

    std::stringstream log;
    log << "In-place serialFFTShift3D for volume size of : "
           << "[" << N << "x" << N << "x" << N << "]"
           << " and type " << std::string(typeid(T).name()) << " is : ";
    profile.PrintProfile (log.str ());
}


template <class T>
/**
 * @brief serialFFTShift3D
 * @param input
 * @param output
 * @param N
 */
void serialFFTShift3D(const T* input , T* output, const int N)
{
    START_PROFILING();
    for (int i = 0; i < N/2; i++) {
        for(int j = 0; j < N/2; j++) {
            for (int k = 0; k < N/2; k++) {
                int idx1, idx2;

                // 1st and 8th octants
                idx1 = ((N/2) + i) + N * (((N/2) + j) + N * ((N/2) + k));
                idx2 = i + N * (j + N * k);

                output[idx1] = input[idx2];
                output[idx2] = input[idx1];

                // 2nd and 7th octants
                idx1 = ((N/2) + i) + N * (j + N * ((N/2) + k));
                idx2 = i + N * (((N/2) + j) + N * k);

                output[idx1] = input[idx2];
                output[idx2] = input[idx1];

                // 3rd and 6th octants
                idx1 = i + N * (((N/2) + j) + N * ((N/2) + k));
                idx2 = ((N/2) + i) + N * (j + N * k);

                output[idx1] = input[idx2];
                output[idx2] = input[idx1];

                // 4th and 5th octants
                idx1 = i + N * (j + N * ((N/2) + k));
                idx2 = ((N/2) + i) + N * (((N/2) + j) + N * k);

                output[idx1] = input[idx2];
                output[idx2] = input[idx1];
            }
        }
    }
    END_PROFILING();
    std::stringstream log;
    log << "Out-of-place serialFFTShift3D for volume size of : "
        << "[" << N << "x" << N << "x" << N << "]"
        << " and type " << std::string(typeid(T).name()) << " is : ";
    profile.PrintProfile (log.str ());
}


template <class T>
/**
 * @brief parallelFFTShift3D
 * @param data
 * @param N
 */
void parallelFFTShift3D(T* data, const int N)
{
    START_PROFILING();
#pragma omp parallel for
    for (int i = 0; i < N/2; i++) {
        for(int j = 0; j < N/2; j++) {
            for (int k = 0; k < N/2; k++) {
                int idx1, idx2;

                // 1st and 8th octants
                idx1 = ((N/2) + i) + N * (((N/2) + j) + N * ((N/2) + k));
                idx2 = i + N * (j + N * k);

                T aux = data[idx1];
                data[idx1] = data[idx2];
                data[idx2] = aux;

                // 2nd and 7th octants
                idx1 = ((N/2) + i) + N * (j + N * ((N/2) + k));
                idx2 = i + N * (((N/2) + j) + N * k);

                aux = data[idx1];
                data[idx1] = data[idx2];
                data[idx2] = aux;

                // 3rd and 6th octants
                idx1 = i + N * (((N/2) + j) + N * ((N/2) + k));
                idx2 = ((N/2) + i) + N * (j + N * k);

                aux = data[idx1];
                data[idx1] = data[idx2];
                data[idx2] = aux;

                // 4th and 5th octants
                idx1 = i + N * (j + N * ((N/2) + k));
                idx2 = ((N/2) + i) + N * (((N/2) + j) + N * k);

                aux = data[idx1];
                data[idx1] = data[idx2];
                data[idx2] = aux;
            }
        }
    }
    END_PROFILING();

    std::stringstream log;
    log << "In-place parallelFFTShift3D for volume size of : "
        << "[" << N << "x" << N << "x" << N << "]"
        << " and type " << std::string(typeid(T).name()) << " is : ";
    profile.PrintProfile (log.str ());


}


template <class T>
/**
 * @brief parallelFFTShift3D
 * @param input
 * @param output
 * @param N
 */
void parallelFFTShift3D(const T* input , T* output, const int N)
{
    START_PROFILING();
#pragma omp parallel for
    for (int i = 0; i < N/2; i++)
        for(int j = 0; j < N/2; j++)
            for (int k = 0; k < N/2; k++)
            {
                int idx1, idx2;

                // 1st and 8th octants
                idx1 = ((N/2) + i) + N * (((N/2) + j) + N * ((N/2) + k));
                idx2 = i + N * (j + N * k);

                output[idx1] = input[idx2];
                output[idx2] = input[idx1];

                // 2nd and 7th octants
                idx1 = ((N/2) + i) + N * (j + N * ((N/2) + k));
                idx2 = i + N * (((N/2) + j) + N * k);

                output[idx1] = input[idx2];
                output[idx2] = input[idx1];

                // 3rd and 6th octants
                idx1 = i + N * (((N/2) + j) + N * ((N/2) + k));
                idx2 = ((N/2) + i) + N * (j + N * k);

                output[idx1] = input[idx2];
                output[idx2] = input[idx1];

                // 4th and 5th octants
                idx1 = i + N * (j + N * ((N/2) + k));
                idx2 = ((N/2) + i) + N * (((N/2) + j) + N * k);

                output[idx1] = input[idx2];
                output[idx2] = input[idx1];
            }
    END_PROFILING();
    std::stringstream log;
    log << "Out-of-place parallelFFTShift3D for volume size of : "
        << "[" << N << "x" << N << "x" << N << "]"
        << " and type " << std::string(typeid(T).name()) << " is : ";
    profile.PrintProfile (log.str ());
}

// Template instanciation
///////////////////////////////////////////////////////////////////////////////
template
void serialFFTShift3D(char* data, const int N);
template
void serialFFTShift3D(unsigned char* data, const int N);
template
void serialFFTShift3D(short* data, const int N);
template
void serialFFTShift3D(unsigned short* data, const int N);
template
void serialFFTShift3D(int* data, const int N);
template
void serialFFTShift3D(unsigned int* data, const int N);
template
void serialFFTShift3D(float* data, const int N);
template
void serialFFTShift3D(double* data, const int N);
///////////////////////////////////////////////////////////////////////////////
template
void serialFFTShift3D(const char* input , char* output, const int N);
template
void serialFFTShift3D(const unsigned char* input , unsigned char* output,
    const int N);
template
void serialFFTShift3D(const short* input , short* output, const int N);
template
void serialFFTShift3D
(const unsigned short* input , unsigned short* output, const int N);
template
void serialFFTShift3D(const int* input , int* output, const int N);
template
void serialFFTShift3D(
const unsigned int* input , unsigned int* output, const int N);
template
void serialFFTShift3D(const float* input , float* output, const int N);
template
void serialFFTShift3D(const double* input , double* output, const int N);
///////////////////////////////////////////////////////////////////////////////
template
void parallelFFTShift3D(char* data, const int N);
template
void parallelFFTShift3D(unsigned char* data, const int N);
template
void parallelFFTShift3D(short* data, const int N);
template
void parallelFFTShift3D(unsigned short* data, const int N);
template
void parallelFFTShift3D(int* data, const int N);
template
void parallelFFTShift3D(unsigned int* data, const int N);
template
void parallelFFTShift3D(float* data, const int N);
template
void parallelFFTShift3D(double* data, const int N);
///////////////////////////////////////////////////////////////////////////////
template
void parallelFFTShift3D(const char* input , char* output, const int N);
template
void parallelFFTShift3D
(const unsigned char* input , unsigned char* output, const int N);
template
void parallelFFTShift3D(const short* input , short* output, const int N);
template
void parallelFFTShift3D
(const unsigned short* input , unsigned short* output, const int N);
template
void parallelFFTShift3D(const int* input , int* output, const int N);
template
void parallelFFTShift3D
(const unsigned int * input , unsigned int* output, const int N);
template
void parallelFFTShift3D(const float* input , float* output, const int N);
template
void parallelFFTShift3D(const double* input , double* output, const int N);
///////////////////////////////////////////////////////////////////////////////
