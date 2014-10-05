#include <iostream>
#include <stdlib.h>

#include "Common.h"
#include "FFTProfiler.h"

/**
 * @brief main Profiles FFT operations in the FVR pipeline.
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char** argv)
{
    if (argc < 6) {
        std::cout << "run <n> <dimension> <type> <precision> <threading> <num cores>" << std::endl;
        std::cout << "***************************************************" << std::endl;
        std::cout << "<n> : number of elements in the array in 1d" << std::endl;
        std::cout << "<dimension> : 2d or 3d" << std::endl;
        std::cout << "<type> : in-place(ip) or out-of-place(op)" << std::endl;
        std::cout << "<precision> : half(h) or single(s) or double(d) or quad(q)" << std::endl;
        std::cout << "<threading> : serial(s) or parallel(p)" << std::endl;
        std::cout << "<num cores> : number of cores" << std::endl;
        std::cout << "***************************************************" << std::endl;

        return 0;
    }

    const int n = atoi(argv[1]);
    std::string dimension_ = argv[2];
    std::string type_ = argv[3];
    std::string precision_ = argv[4];
    std::string threading_ = argv[5];

    // Updating the number of threads
    int numThreads = 1;
    if (argc > 6) numThreads = atoi(argv[6]);

    std::cout << "n = " << n << ", dimension = " << dimension_
              << ", type = " << type_ <<  ", threading = " << threading_
              << ", precision = " << precision_
              << ", number of threads = " << numThreads
              << std::endl;

    // Updating the dimension selection
    DIMENSION dimension;
    if (dimension_ == "2d")
        dimension = DIM_2D;
    else if (dimension_ == "3d")
        dimension = DIM_3D;
    else
        std::cout << "Wrong dimension has been selected" << std::endl;

    // Updating the operation type selection.
    FFT_ARRAY_TYPE  type;
    if (type_ == "in-place" || type_ == "ip")
        type = IN_PLACE;
    else if (type_ == "out-of-place" || type_ == "op")
        type == OUT_OF_PLACE;
    else
        std::cout << "Wrong shift type has been selected" << std::endl;

    // Updating the precision
    PRECISION precision;
    if (precision_ == "half" || precision_ == "h") {
        std::cout << "Not implemented yet" << std::cout;
        // precision == HALF;
        return 0;
    } else if (precision_ == "single" || precision_ == "s") {
        precision = SINGLE_PRECISION;
    } else if (precision_ == "double" || precision_ == "d") {
        precision = DOUBLE_PRECISION;
    } else if (precision_ == "quad" || precision_ == "q") {
        std::cout << "Not implemented yet" << std::cout;
        // precision = QUAD;
        return 0;
    } else
        std::cout << "Selecte precision is not correct" << std::endl;

    // Updating the threading
    THREADING threading;
    if (threading_ == "serial" || threading_ == "s")
        threading = SERIAL;
    else if (threading_ == "parallel" || threading_ == "p")
        threading = PARALLEL;

    // Profile FFT operation
    ProfileFFT(dimension, type, precision, threading, n, numThreads);
}
