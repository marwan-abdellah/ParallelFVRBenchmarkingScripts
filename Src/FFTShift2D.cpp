#include "FFTShift2D.h"
#include "Profiler.h"

#include <typeinfo>

template <class T>
/**
 * @brief serialFFTShift2D
 * @param data
 * @param N
 */
void serialFFTShift2D(T* data, const int N)
{
    START_PROFILING();
    for (int i = 0; i < N/2; i++)
        for(int j = 0; j < N/2; j++)
        {
            int idx1; int idx2;

            // First and fourth quadrants
            idx1 = i + N * j;
            idx2 = ((N/2) + i) + (N * ((N/2) + j));

            T aux = data[idx1];
            data[idx1] = data[idx2];
            data[idx2] = aux;

            // Second and third quadrants
            idx1 = i + N * ((N/2) + j);
            idx2 = ((N/2) + i) + (N * j);

            aux = data[idx1];
            data[idx1] = data[idx2];
            data[idx2] = aux;
        }
    END_PROFILING();
    std::stringstream log;
    log << "In-place serialFFTShift2D for volume size of : "
        << "[" << N << "x" << N << "]"
        << " and type " << std::string(typeid(T).name()) << " is : ";
    profile.PrintProfile (log.str ());
}


template <class T>
/**
 * @brief parallelFFTShift2D
 * @param data
 * @param N
 */
void parallelFFTShift2D(T* data, const int N)
{
    START_PROFILING();
#pragma omp parallel for
    for (int i = 0; i < N/2; i++)
        for(int j = 0; j < N/2; j++)
        {
            int idx1; int idx2;

            // First and fourth quadrants
            idx1 = i + N * j;
            idx2 = ((N/2) + i) + (N * ((N/2) + j));

            T aux = data[idx1];
            data[idx1] = data[idx2];
            data[idx2] = aux;

            // Second and third quadrants
            idx1 = i + N * ((N/2) + j);
            idx2 = ((N/2) + i) + (N * j);

            aux = data[idx1];
            data[idx1] = data[idx2];
            data[idx2] = aux;
        }
    END_PROFILING();
    std::stringstream log;
    log << "In-place parallelFFTShift2D for volume size of : "
        << "[" << N << "x" << N << "]"
        << " and type " << std::string(typeid(T).name()) << " is : ";
    profile.PrintProfile (log.str ());
}

template <class T>
/**
 * @brief serialFFTShift2D
 * @param input
 * @param output
 * @param N
 */
void serialFFTShift2D(const T* input, T* output, const int N)
{
    START_PROFILING();
    for (int i = 0; i < N/2; i++)
        for(int j = 0; j < N/2; j++)
        {
            int idx1; int idx2;

            // First and fourth quadrants
            idx1 = i + N * j;
            idx2 = ((N/2) + i) + (N * ((N/2) + j));

            output[idx1] = input[idx2];
            output[idx2] = input[idx1];

            // Second and third quadrants
            idx1 = i + N * ((N/2) + j);
            idx2 = ((N/2) + i) + (N * j);

            output[idx1] = input[idx2];
            output[idx2] = input[idx1];
        }
    END_PROFILING();
    std::stringstream log;
    log << "Out-of-place serialFFTShift2D for volume size of : "
        << "[" << N << "x" << N << "]"
        << " and type " << std::string(typeid(T).name()) << " is : ";
    profile.PrintProfile (log.str ());
}


template <class T>
/**
 * @brief parallelFFTShift2D
 * @param input
 * @param output
 * @param N
 */
void parallelFFTShift2D(const T* input, T* output, const int N)
{
    START_PROFILING();
#pragma omp parallel for
    for (int i = 0; i < N/2; i++)
        for(int j = 0; j < N/2; j++)
        {
            int idx1; int idx2;

            // First and fourth quadrants
            idx1 = i + N * j;
            idx2 = ((N/2) + i) + (N * ((N/2) + j));

            output[idx1] = input[idx2];
            output[idx2] = input[idx1];

            // Second and third quadrants
            idx1 = i + N * ((N/2) + j);
            idx2 = ((N/2) + i) + (N * j);

            output[idx1] = input[idx2];
            output[idx2] = input[idx1];
        }
    END_PROFILING();
    std::stringstream log;
    log << "Out-of-place parallelFFTShift2D for volume size of : "
        << "[" << N << "x" << N << "]"
        << " and type " << std::string(typeid(T).name()) << " is : ";
    profile.PrintProfile (log.str ());
}


// Template instanciation
///////////////////////////////////////////////////////////////////////////////
template
void serialFFTShift2D(char* data, const int N);
template
void serialFFTShift2D(unsigned char* data, const int N);
template
void serialFFTShift2D(short* data, const int N);
template
void serialFFTShift2D(unsigned short* data, const int N);
template
void serialFFTShift2D(int* data, const int N);
template
void serialFFTShift2D(unsigned int* data, const int N);
template
void serialFFTShift2D(float* data, const int N);
template
void serialFFTShift2D(double* data, const int N);

template
void parallelFFTShift2D(char* data, const int N);
template
void parallelFFTShift2D(unsigned char* data, const int N);
template
void parallelFFTShift2D(short* data, const int N);
template
void parallelFFTShift2D(unsigned short* data, const int N);
template
void parallelFFTShift2D(int* data, const int N);
template
void parallelFFTShift2D(unsigned int* data, const int N);
template
void parallelFFTShift2D(float* data, const int N);
template
void parallelFFTShift2D(double* data, const int N);
///////////////////////////////////////////////////////////////////////////////
template
void serialFFTShift2D(const char* input, char* output, const int N);
template
void serialFFTShift2D(const unsigned char* input, unsigned char* output, const int N);
template
void serialFFTShift2D(const short* input, short* output, const int N);
template
void serialFFTShift2D(const unsigned short* input, unsigned short* output, const int N);
template
void serialFFTShift2D(const int* input, int* output, const int N);
template
void serialFFTShift2D(const unsigned int* input, unsigned int* output, const int N);
template
void serialFFTShift2D(const float* input, float* output, const int N);
template
void serialFFTShift2D(const double* input, double* output, const int N);
///////////////////////////////////////////////////////////////////////////////
template
void parallelFFTShift2D(const char* input, char* output, const int N);
template
void parallelFFTShift2D(const unsigned char* input, unsigned char* output, const int N);
template
void parallelFFTShift2D(const short* input, short* output, const int N);
template
void parallelFFTShift2D(const unsigned short* input, unsigned short* output, const int N);
template
void parallelFFTShift2D(const int* input, int* output, const int N);
template
void parallelFFTShift2D(const unsigned int* input, unsigned int* output, const int N);
template
void parallelFFTShift2D(const float* input, float* output, const int N);
template
void parallelFFTShift2D(const double* input, double* output, const int N);
///////////////////////////////////////////////////////////////////////////////
