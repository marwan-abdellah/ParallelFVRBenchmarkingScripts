#include <iostream>
#include <cstdlib>
#include <sys/time.h>
#include <cmath>
#include <math.h>
#include <string>
#include <vector>
#include <stdlib.h>

#include "RandomNumberGeneration.h"
#include "FFTShift2D_InPlace.h"
#include "FFTShift2D_OutofPlace.h"
#include "FFTShift3D_InPlace.h"
#include "FFTShift3D_OutofPlace.h"

typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;

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


    if (dimension == "2d") {
        if (threading == "serial" || threading == "s") {
            if (type == "in-place" || type == "ip") {
                if (datatype == "char") {
                    char c = FFTShift2D_IN_PLACE_SERIAL <char> (n);
                } else if (datatype == "uchar") {
                    uchar uc = FFTShift2D_IN_PLACE_SERIAL <uchar> (n);
                } else if (datatype == "short") {
                    short s = FFTShift2D_IN_PLACE_SERIAL <short> (n);
                } else if (datatype == "half") {

                } else if (datatype == "int") {
                    int i = FFTShift2D_IN_PLACE_SERIAL <int> (n);
                } else if (datatype == "float") {
                    float f = FFTShift2D_IN_PLACE_SERIAL <float> (n);
                } else if (datatype == "double") {
                    double d = FFTShift2D_IN_PLACE_SERIAL <double> (n);
                } else if (datatype == "complex-half") {

                } else if (datatype == "complex-float") {

                } else if (datatype == "complex-double") {

                } else {
                    std::cout << "Wrong data type" << std::endl;
                }
            } else if (type == "out-of-place" || type == "op") {
                if (datatype == "char") {
                    char c = FFTShift2D_OUT_OF_PLACE_SERIAL <char> (n);
                } else if (datatype == "uchar") {
                    uchar uc = FFTShift2D_OUT_OF_PLACE_SERIAL <uchar> (n);
                } else if (datatype == "short") {
                    short s = FFTShift2D_OUT_OF_PLACE_SERIAL <short> (n);
                } else if (datatype == "half") {

                } else if (datatype == "int") {
                    int i = FFTShift2D_OUT_OF_PLACE_SERIAL <int> (n);
                } else if (datatype == "float") {
                    float f = FFTShift2D_OUT_OF_PLACE_SERIAL <float> (n);
                } else if (datatype == "double") {
                    double d = FFTShift2D_OUT_OF_PLACE_SERIAL <double> (n);
                } else if (datatype == "complex-half") {

                } else if (datatype == "complex-float") {

                } else if (datatype == "complex-double") {

                } else {
                    std::cout << "Wrong data type" << std::endl;
                }

            } else {
                std::cout << "The operation was not specified correctly" << std::endl;
            }

        } else if (threading == "parallel" || threading == "p") {
            if (type == "in-place" || type == "ip") {
                if (datatype == "char") {
                    char c = FFTShift2D_IN_PLACE_PARALLEL <char> (n);
                } else if (datatype == "uchar") {
                    uchar uc = FFTShift2D_IN_PLACE_PARALLEL <uchar> (n);
                } else if (datatype == "short") {
                    short s = FFTShift2D_IN_PLACE_PARALLEL <short> (n);
                } else if (datatype == "half") {

                } else if (datatype == "int") {
                    int i = FFTShift2D_IN_PLACE_PARALLEL <char> (n);
                } else if (datatype == "float") {
                    float f = FFTShift2D_IN_PLACE_PARALLEL <float> (n);
                } else if (datatype == "double") {
                    double d = FFTShift2D_IN_PLACE_PARALLEL <double> (n);
                } else if (datatype == "complex-half") {

                } else if (datatype == "complex-float") {

                } else if (datatype == "complex-double") {

                } else {
                    std::cout << "Wrong data type" << std::endl;
                }

            } else if (type == "out-of-place" || type == "op") {
                if (datatype == "char") {
                    char c = FFTShift2D_OUT_OF_PLACE_PARALLEL <char> (n);
                } else if (datatype == "uchar") {
                    uchar uc = FFTShift2D_OUT_OF_PLACE_PARALLEL <uchar> (n);
                } else if (datatype == "short") {
                    short s = FFTShift2D_OUT_OF_PLACE_PARALLEL <short> (n);
                } else if (datatype == "half") {

                } else if (datatype == "int") {
                    int i = FFTShift2D_OUT_OF_PLACE_PARALLEL <int> (n);
                } else if (datatype == "float") {
                    float f = FFTShift2D_OUT_OF_PLACE_PARALLEL <float> (n);
                } else if (datatype == "double") {
                    double d = FFTShift2D_OUT_OF_PLACE_PARALLEL <double> (n);
                } else if (datatype == "complex-half") {

                } else if (datatype == "complex-float") {

                } else if (datatype == "complex-double") {

                } else {
                    std::cout << "Wrong data type" << std::endl;
                }

            } else {
                std::cout << "The operation was not specified correctly" << std::endl;
            }

        } else {
            std::cout << "The operation was not specified correctly" << std::endl;
        }

    } else if (dimension == "3d") {
        if (threading == "serial" || threading == "s") {
            if (type == "in-place" || type == "ip") {
                if (datatype == "char") {
                    char c = FFTShift3D_IN_PLACE_SERIAL <char> (n);
                } else if (datatype == "uchar") {
                    uchar uc = FFTShift3D_IN_PLACE_SERIAL <uchar> (n);
                } else if (datatype == "short") {
                    short s = FFTShift3D_IN_PLACE_SERIAL <short> (n);
                } else if (datatype == "half") {

                } else if (datatype == "int") {
                    int i = FFTShift3D_IN_PLACE_SERIAL <int> (n);
                } else if (datatype == "float") {
                    float f = FFTShift3D_IN_PLACE_SERIAL <float> (n);
                } else if (datatype == "double") {
                    double d = FFTShift3D_IN_PLACE_SERIAL <double> (n);
                } else if (datatype == "complex-half") {

                } else if (datatype == "complex-float") {

                } else if (datatype == "complex-double") {

                } else {
                    std::cout << "Wrong data type" << std::endl;
                }

            } else if (type == "out-of-place" || type == "op") {
                if (datatype == "char") {
                    char c = FFTShift3D_OUT_OF_PLACE_SERIAL <char> (n);
                } else if (datatype == "uchar") {
                    uchar uc = FFTShift3D_OUT_OF_PLACE_SERIAL <uchar> (n);
                } else if (datatype == "short") {
                    short s = FFTShift3D_OUT_OF_PLACE_SERIAL <short> (n);
                } else if (datatype == "half") {

                } else if (datatype == "int") {
                    int i = FFTShift3D_OUT_OF_PLACE_SERIAL <int> (n);
                } else if (datatype == "float") {
                    float f = FFTShift3D_OUT_OF_PLACE_SERIAL <float> (n);
                } else if (datatype == "double") {
                    double d = FFTShift3D_OUT_OF_PLACE_SERIAL <double> (n);
                } else if (datatype == "complex-half") {

                } else if (datatype == "complex-float") {

                } else if (datatype == "complex-double") {

                } else {
                    std::cout << "Wrong data type" << std::endl;
                }

            } else {
                std::cout << "The operation was not specified correctly" << std::endl;
            }

        } else if (threading == "parallel" || threading == "p") {
            if (type == "in-place" || type == "ip") {
                if (datatype == "char") {
                    char c = FFTShift3D_IN_PLACE_PARALLEL <char> (n);
                } else if (datatype == "uchar") {
                    uchar uc = FFTShift3D_IN_PLACE_PARALLEL <uchar> (n);
                } else if (datatype == "short") {
                    short s = FFTShift3D_IN_PLACE_PARALLEL <short> (n);
                } else if (datatype == "half") {

                } else if (datatype == "int") {
                    int i = FFTShift3D_IN_PLACE_PARALLEL <int> (n);
                } else if (datatype == "float") {
                    float f = FFTShift3D_IN_PLACE_PARALLEL <float> (n);
                } else if (datatype == "double") {
                    double d = FFTShift3D_IN_PLACE_PARALLEL <double> (n);
                } else if (datatype == "complex-half") {

                } else if (datatype == "complex-float") {

                } else if (datatype == "complex-double") {

                } else {
                    std::cout << "Wrong data type" << std::endl;
                }

            } else if (type == "out-of-place" || type == "op") {
                if (datatype == "char") {
                    char c = FFTShift3D_OUT_OF_PLACE_PARALLEL <char> (n);
                } else if (datatype == "uchar") {
                    uchar uc = FFTShift3D_OUT_OF_PLACE_PARALLEL <uchar> (n);
                } else if (datatype == "short") {
                    short s = FFTShift3D_OUT_OF_PLACE_PARALLEL <short> (n);
                } else if (datatype == "half") {

                } else if (datatype == "int") {
                    int i = FFTShift3D_OUT_OF_PLACE_PARALLEL <int> (n);
                } else if (datatype == "float") {
                    float f = FFTShift3D_OUT_OF_PLACE_PARALLEL <float> (n);
                } else if (datatype == "double") {
                    double d = FFTShift3D_OUT_OF_PLACE_PARALLEL <double> (n);
                } else if (datatype == "complex-half") {

                } else if (datatype == "complex-float") {

                } else if (datatype == "complex-double") {

                } else {
                    std::cout << "Wrong data type" << std::endl;
                }

            } else {
                std::cout << "The operation was not specified correctly" << std::endl;
            }

        } else {
            std::cout << "The operation was not specified correctly" << std::endl;
        }

    } else {
        std::cout << "The operation was not specified correctly" << std::endl;
    }

    return 0;

}
