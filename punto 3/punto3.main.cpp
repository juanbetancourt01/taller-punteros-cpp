#include <iostream>

int mayor(int* arr, int n) {
    if (n <= 0) {
        std::cout << "Arreglo vacio" << std::endl;
        return 0;
    }

    int max = *arr;

    for (int i = 1; i < n; i++) {
        if (*(arr + i) > max) {
            max = (*arr + i);
        }
    }

    return max;
}

int main() {
    int n;
    std::cin >> n;

    if (n <= 0) return 0;

    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        std::cin >> *(arr + i);
    }

    std::cout << "Mayor: " << mayor(arr, n) << std::endl;

    delete[] arr;
    return 0;
}
