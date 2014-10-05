#include <iostream>
#include <cstdlib>
#include <sys/time.h>
#include <cmath>
#include <math.h>
#include <string>
#include <vector>
#include <stdlib.h>

#include "Common.h"
#include "FFTShiftProfiler.h"


/**
 * @brief main Profiles the FFTShift operations in the FVR pipeline.
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char** argv) {

    if (argc < 4) {
        std::cout << "run <n> <dimension> <type> <datatype> <threading> <num cores>" << std::endl;
        std::cout << "***************************************************" << std::endl;
        std::cout << "<n> : number of elements in the array in 1d" << std::endl;
        std::cout << "<dimension> : 2d or 3d" << std::endl;
        std::cout << "<type> : in-place(ip) or out-of-place (op)" << std::endl;
        std::cout << "<datatype> : char or uchar or short or ushort or int or float or double" << std::endl;
        std::cout << "<threading> : serial(s) or parallel(p)" << std::endl;
        std::cout << "<num cores> : number of cores" << std::endl;
        std::cout << "***************************************************" << std::endl;

        return 0;
    }

    const int n = atoi(argv[1]);
    std::string dimension = argv[2];
    std::string type = argv[3];
    std::string datatype = argv[4];
    std::string threading = argv[5];

    std::cout << "n = " << n << ", dimension = " << dimension
              << ", type = " << type << ", datatype = " << datatype
              << ", threading = " << threading
              << std::endl;

    // Updating the dimension selection
    DIMENSION dim;
    if (dimension == "2d")
        dim = DIM_2D;
    else if (dimension == "3d")
        dim = DIM_3D;
    else
        std::cout << "Wrong dimension has been selected" << std::endl;

    // Updating the operation type selection.
    SHIFT_TYPE  shiftType;
    if (type == "in-place" || type == "ip")
        shiftType = IN_PLACE;
    else if (type == "out-of-place" || type == "op")
        shiftType == OUT_OF_PLACE;
    else
        std::cout << "Wrong shift type has been selected" << std::endl;

    // Updating the format
    DATA_FORMAT format;
    if (datatype == "char")
        format = CHAR;
    else if (datatype == "uchar")
        format = UCHAR;
    else if (datatype == "short")
        format = SHORT;
    else if (datatype == "int")
        format = INT;
    else if (datatype == "float")
        format = FLOAT;
    else if (datatype == "double")
        format = DOUBLE;
    else
        std::cout << "Wrong data type was selcted" << std::endl;

    // Updating the threading
    THREADING thread;
    if (threading == "serial" || threading == "s")
        thread = SERIAL;
    else if (threading == "parallel" || threading == "p")
        thread = PARALLEL;

    // Profile FFTShift operation
    ProfileFFTShift (dim, format, shiftType, thread, n);

    return 0;

}
