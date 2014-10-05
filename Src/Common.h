#ifndef COMMON_H
#define COMMON_H

enum THREADING {
    SERIAL = 0,
    PARALLEL = 1
};

enum DIMENSION {
    DIM_2D = 0,
    DIM_3D = 1
};

enum DATA_FORMAT {
    CHAR = 0,
    UCHAR = 1,
    SHORT = 2,
    INT = 3,
    FLOAT = 4,
    DOUBLE = 5,
    COMPLEX_FLOAT = 6,
    COMPLEX_DOUBLE = 7
};

enum PRECISION {
    HALF_PRECISION = 0,
    SINGLE_PRECISION = 1,
    DOUBLE_PRECISION = 2,
    QUAD_PRECISION = 3
};

enum SHIFT_TYPE {
    IN_PLACE = 0,
    OUT_OF_PLACE = 1
};

typedef SHIFT_TYPE FFT_ARRAY_TYPE;

typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;

#endif // COMMON_H
