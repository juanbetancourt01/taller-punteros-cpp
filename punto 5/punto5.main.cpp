#include <iostream>

void llenar(int matriz, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            std::cout << "Elemento [" << i << "][" << j << "]: ";
            std::cin >> ((matriz + i) + j);
        }
    }
}

void sumaFilas(int matriz, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        int suma = 0;
        for (int j = 0; j < columnas; j++) {
            suma += ((matriz + i) + j);
        }
        std::cout << "Suma fila " << i << ": " << suma << std::endl;
    }
}

int main() {
    int filas, columnas;

    std::cout << "Filas: ";
    std::cin >> filas;
    std::cout << "Columnas: ";
    std::cin >> columnas;

    int** matriz = new int*[filas];

    for (int i = 0; i < filas; i++) {
        (matriz + i) = new int[columnas];
    }

    llenar(matriz, filas, columnas);
    sumaFilas(matriz, filas, columnas);

    // Liberar memoria
    for (int i = 0; i < filas; i++) {
        delete[](matriz + i);
    }
    delete[] matriz;

    return 0;
}
