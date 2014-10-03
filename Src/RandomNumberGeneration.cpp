#include "RandomNumberGeneration.h"
#include <stdlib.h>
#include <iostream>
#include <typeinfo>

#define MIN_CHAR        -127
#define MAX_CHAR        127
#define MIN_UCHAR       0
#define MAX_UCHAR       255
#define MIN_SHORT       -32768
#define MAX_SHORT       32767
#define MIN_USHORT      0
#define MAX_USHORT      65535
#define MIN_INT         -2147483648
#define MAX_INT         2147483647
#define MAX_UINT        4294967295

template <class T>
T RNG(T dummy) {
    if (typeid(dummy) == typeid(char)) {
        return static_cast<char>(MIN_CHAR + static_cast <float> (rand()) /
                                 (static_cast <float> (RAND_MAX / (MAX_CHAR - (MIN_CHAR)))));
    } else if (typeid(dummy) == typeid(unsigned char)) {
        return static_cast<unsigned char>(static_cast <float> (rand()) /
                                          (static_cast <float> (RAND_MAX / (MAX_UCHAR))));
    } else if (typeid(dummy) == typeid(short)) {
        return static_cast<short>(MIN_SHORT + static_cast <float> (rand()) /
                                  (static_cast <float> (RAND_MAX / (MAX_SHORT - (MIN_SHORT)))));
    } else if (typeid(dummy) == typeid(unsigned short)) {
        return static_cast<unsigned short>(static_cast <float> (rand()) /
                                           (static_cast <float> (RAND_MAX / (MAX_USHORT))));
    } else if (typeid(dummy) == typeid(int)) {
        return static_cast<int>(MIN_INT + static_cast <float> (rand()) /
                                (static_cast <float> (RAND_MAX / (MAX_INT - (MIN_INT)))));
    } else if (typeid(dummy) == typeid(unsigned int)) {
        return static_cast<unsigned int>(static_cast <float> (rand()) /
                                (static_cast <float> (RAND_MAX / (MAX_UINT))));
    } else if (typeid(dummy) == typeid(float)) {
        return (static_cast <float> (rand()) / (static_cast <float> (RAND_MAX)));
    } else if (typeid(dummy) == typeid(double)) {
        return ((rand()) / (static_cast <double> (RAND_MAX)));
    } else {
        std::cout << "RNG is not implemented for this type" << std::endl;
    }
}

template char RNG(char);
template unsigned char RNG(unsigned char);
template short RNG(short);
template unsigned short RNG(unsigned short);
template int RNG(int);
template unsigned int RNG(unsigned int);
template float RNG(float);
template double RNG(double);


