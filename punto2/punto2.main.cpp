#include <iostream>

int suma(int* arr, int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += (arr + i);
    }
    return total;
}

int main() {
    int n;

    std::cout << "Tamano del arreglo: ";
    std::cin >> n;

    int arr = new int[n];

    for (int i = 0; i < n; i++) {
        std::cout << "Elemento " << i << ": ";
        std::cin >> *(arr + i);
    }

    std::cout << "Suma: " << suma(arr, n) << std::endl;

    delete[] arr;

    return 0;
}
