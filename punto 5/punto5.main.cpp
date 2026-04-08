#include <iostream>

void verEntero(int* p) {
    std::cout << "Como entero: " << p << std::endl;
    std::cout << "Direccion int: " << p << std::endl;
}

void verBytes(char* p, int size) {
    std::cout << "Bytes:\n";
    for (int i = 0; i < size; i++) {
        std::cout << (int)*(p + i) << " ";
    }
    std::cout << std::endl;
    std::cout << "Direccion char: " << (void*)p << std::endl;
}

int main() {
    float num;

    std::cout << "Ingrese un float: ";
    std::cin >> num;

    int* pInt = (int*)&num;
    char* pChar = (char*)&num;

    std::cout << "Direccion original: " << &num << std::endl;

    verEntero(pInt);
    verBytes(pChar, sizeof(float));

    return 0;
}
