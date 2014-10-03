#include <typeinfo>
#include <iostream>

template <typename T>
void TypeTest(T dummy) {
    if (typeid(dummy) == typeid(char)) {
        std::cout << "char" << std::endl;
    }
    else if (typeid(dummy) == typeid(unsigned char)) {
        std::cout << "unsigned char" << std::endl;
    }
    else if (typeid(dummy) == typeid(short)) {
        std::cout << "short" << std::endl;
    }
    else if (typeid(dummy) == typeid(unsigned short)) {
        std::cout << "unsigned short" << std::endl;
    }
    else if (typeid(dummy) == typeid(int)) {
        std::cout << "int" << std::endl;
    }
    else if (typeid(dummy) == typeid(unsigned int)) {
        std::cout << "unsigned int" << std::endl;
    }
    else if (typeid(dummy) == typeid(float)) {
        std::cout << "float" << std::endl;
    } else {
        std::cout << "Wrong type" << std::endl;
    }
}

template void TypeTest(char);
template void TypeTest(unsigned char);
template void TypeTest(short);
template void TypeTest(int);
template void TypeTest(float);

int main() {

    TypeTest <char>(char(0));
    TypeTest <unsigned char>(char(0));
    TypeTest <short>(short(0));
    TypeTest <unsigned short>(short(0));
    TypeTest <int>(int(0));
    TypeTest <unsigned int>(int(0));
    TypeTest <float>(float(0));
    return 0;
}
