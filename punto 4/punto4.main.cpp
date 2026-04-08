#include <iostream>

int duplicar(int x) {
    return x * 2;
}

int triplicar(int x) {
    return x * 3;
}

void aplicar(int* arr, int n, int (*func)(int)) {
    for (int i = 0; i < n; i++) {
        (arr + i) = func((arr + i));
    }
}

int main() {
    int n;
    std::cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        std::cin >> (arr + i);
    }

    aplicar(arr, n, duplicar);

    std::cout << "Resultado:\n";
    for (int i = 0; i < n; i++) {
        std::cout <<(arr + i) << " ";
    }

    delete[] arr;
    return 0;
}
