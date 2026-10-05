// Práctica 2: Listas — Código base en C++ (AED I, Bloque I)
//
// Completa las tres funciones. Reglas:
//   - Trabaja únicamente con std::vector.
//   - No uses std::sort, std::reverse, std::set ni std::unordered_set.
//   - Al terminar cada ejercicio, escribe en el comentario su complejidad temporal.
//
// Compilar y ejecutar:
//   g++ -std=c++17 -Wall -o practica2 enunciado_base.cpp && ./practica2

#include <cstddef>
#include <functional>
#include <iostream>
#include <vector>

using std::vector;

// ---------------------------------------------------------------------------
// Ejercicio 1 - Ordenación por inserción (in-place)
// ---------------------------------------------------------------------------
void insertion_sort(vector<int>& lista) {
    // completa
}
// Complejidad -> mejor caso: ...   peor caso: ...

// ---------------------------------------------------------------------------
// Ejercicio 2 - Fusionar dos listas ordenadas en una sola pasada
// ---------------------------------------------------------------------------
vector<int> fusionar(const vector<int>& a, const vector<int>& b) {
    vector<int> resultado;
    // completa
    return resultado;
}
// Complejidad -> ...

// ---------------------------------------------------------------------------
// Ejercicio 3 - Eliminar duplicados conservando el orden (sin set)
// ---------------------------------------------------------------------------
vector<int> sin_duplicados(const vector<int>& lista) {
    vector<int> resultado;
    // completa
    return resultado;
}
// Complejidad -> peor caso: ...   ¿por qué?

// ---------------------------------------------------------------------------
// Pruebas (no hace falta modificarlas)
// ---------------------------------------------------------------------------
bool test_ejercicio1() {
    vector<int> datos{7, 3, 5, 2, 9, 1};
    insertion_sort(datos);
    if (datos != vector<int>{1, 2, 3, 5, 7, 9}) return false;
    vector<int> vacia{};
    insertion_sort(vacia);
    if (!vacia.empty()) return false;
    vector<int> uno{42};
    insertion_sort(uno);
    if (uno != vector<int>{42}) return false;
    vector<int> repetidos{2, 2, 1, 2};
    insertion_sort(repetidos);
    if (repetidos != vector<int>{1, 2, 2, 2}) return false;
    vector<int> inversa{4, 3, 2, 1};
    insertion_sort(inversa);
    return inversa == vector<int>{1, 2, 3, 4};
}

bool test_ejercicio2() {
    return fusionar({1, 4, 7}, {2, 3, 9}) == vector<int>{1, 2, 3, 4, 7, 9}
        && fusionar({}, {2, 5}) == vector<int>{2, 5}
        && fusionar({2, 5}, {}) == vector<int>{2, 5}
        && fusionar({}, {}).empty()
        && fusionar({1, 1, 3}, {1, 2}) == vector<int>{1, 1, 1, 2, 3};
}

bool test_ejercicio3() {
    return sin_duplicados({3, 1, 3, 2, 1, 4}) == vector<int>{3, 1, 2, 4}
        && sin_duplicados({}).empty()
        && sin_duplicados({5, 5, 5}) == vector<int>{5};
}

int main() {
    struct Prueba { const char* nombre; std::function<bool()> f; };
    Prueba pruebas[] = {{"test_ejercicio1", test_ejercicio1},
                        {"test_ejercicio2", test_ejercicio2},
                        {"test_ejercicio3", test_ejercicio3}};
    for (const auto& p : pruebas) {
        std::cout << (p.f() ? "OK    " : "FALLA ") << p.nombre << "\n";
    }
    return 0;
}
