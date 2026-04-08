#include <iostream>

void intercambiar(int* a, int* b) {
    int temp = *a;
    a =b;
    *b = temp;
}

int main() {
    int x, y;

    std::cout << "Ingrese dos numeros: ";
    std::cin >> x >> y;

    intercambiar(&x, &y);

    std::cout << "Valores intercambiados: " << x << " " << y << std::endl;

    return 0;
}
