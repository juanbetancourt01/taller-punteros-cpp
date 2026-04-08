#include <iostream>

// ========== INTERCAMBIAR ==========
void intercambiar(int* a, int* b) {
int temp = *a;
*a = *b; // ← estaba mal: "a = b" en vez de "*a = *b"
*b = temp;
}

// ========== SUMA ==========
int suma(int* arr, int n) {
int total = 0;
for (int i = 0; i < n; i++) {
total += *(arr + i);
}
return total;
}

// ========== MAYOR ==========
int mayor(int* arr, int n) {
if (n <= 0) {
std::cout << "Arreglo vacio" << std::endl;
return 0;
}
int max = *arr;
for (int i = 1; i < n; i++) {
if (*(arr + i) > max) {
max = *(arr + i); // ← estaba mal: "(*arr + i)" en vez de "*(arr + i)"
}
}
return max;
}

// ========== APLICAR FUNCION ==========
int duplicar(int x) { return x * 2; }
int triplicar(int x) { return x * 3; }

void aplicar(int* arr, int n, int (*func)(int)) {
for (int i = 0; i < n; i++) {
*(arr + i) = func(*(arr + i));
}
}

// ========== VER BITS DE FLOAT ==========
void verEntero(int* p) {
std::cout << "Como entero: " << *p << std::endl; // ← faltaba el *
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

// ========== MAIN ==========
int main() {
int opcion;

do {
std::cout << "\n--- MENU ---\n";
std::cout << "1. Intercambiar dos numeros\n";
std::cout << "2. Suma de arreglo\n";
std::cout << "3. Mayor del arreglo\n";
std::cout << "4. Aplicar duplicar/triplicar\n";
std::cout << "5. Ver bits de un float\n";
std::cout << "0. Salir\n";
std::cout << "Opcion: ";
std::cin >> opcion;

if (opcion == 1) {
int x, y;
std::cout << "Ingrese dos numeros: ";
std::cin >> x >> y;
intercambiar(&x, &y);
std::cout << "Intercambiados: " << x << " " << y << std::endl;

} else if (opcion == 2) {
int n;
std::cout << "Tamano: ";
std::cin >> n;
int* arr = new int[n];
for (int i = 0; i < n; i++) {
std::cout << "Elemento " << i << ": ";
std::cin >> *(arr + i);
}
std::cout << "Suma: " << suma(arr, n) << std::endl;
delete[] arr;

} else if (opcion == 3) {
int n;
std::cout << "Tamano: ";
std::cin >> n;
int* arr = new int[n];
for (int i = 0; i < n; i++) {
std::cin >> *(arr + i);
}
std::cout << "Mayor: " << mayor(arr, n) << std::endl;
delete[] arr;

} else if (opcion == 4) {
int n, op;
std::cout << "Tamano: ";
std::cin >> n;
int* arr = new int[n];
for (int i = 0; i < n; i++) {
std::cin >> *(arr + i);
}
std::cout << "1. Duplicar 2. Triplicar: ";
std::cin >> op;
aplicar(arr, n, op == 1 ? duplicar : triplicar);
std::cout << "Resultado: ";
for (int i = 0; i < n; i++) {
std::cout << *(arr + i) << " ";
}
std::cout << std::endl;
delete[] arr;

} else if (opcion == 5) {
float num;
std::cout << "Ingrese un float: ";
std::cin >> num;
int* pInt = (int*)&num;
char* pChar = (char*)&num;
std::cout << "Direccion original: " << &num << std::endl;
verEntero(pInt);
verBytes(pChar, sizeof(float));
}

} while (opcion != 0);

return 0;
}
