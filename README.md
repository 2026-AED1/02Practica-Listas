# Práctica 2: Listas

**AED I — Bloque I** · 2 h en clase + 1 h en casa
Algoritmia y Estructuras de Datos · Ingeniería Informática – Inteligencia Artificial

> Material de la sesión: [`transparencias.pdf`](transparencias.pdf)
> Código de partida: [`enunciado_base.py`](enunciado_base.py) (Python) · [`enunciado_base.cpp`](enunciado_base.cpp) (C++)

## Objetivos

Al terminar esta práctica deberías ser capaz de:

- Usar `list` de Python (o `std::vector` en C++) sabiendo qué cuesta cada operación.
- Implementar algoritmos sencillos sobre listas usando índices, sin recurrir a funciones de la biblioteca que ya los resuelven.
- Calcular y justificar la complejidad temporal de tus soluciones en el mejor y en el peor caso.

## Antes de empezar: tres ideas

1. Una `list` de Python se comporta como un **array dinámico**: se accede directamente a cualquier posición por su índice.
2. Que una operación sea cómoda de escribir **no significa que sea barata**. Insertar o borrar al principio obliga a desplazar el resto de elementos.
3. En los ejercicios importa tanto que el resultado sea **correcto** como poder **explicar su complejidad**.

### Coste de las operaciones básicas

| Operación | Python | C++ (`std::vector`) | Coste |
|---|---|---|---|
| Añadir al final | `lista.append(x)` | `v.push_back(x)` | O(1) amortizado |
| Acceder por posición | `lista[i]` | `v[i]` | O(1) |
| Buscar un elemento | `x in lista`, `lista.index(x)` | recorrido lineal | O(n) |
| Insertar en la posición i | `lista.insert(i, x)` | `v.insert(v.begin() + i, x)` | O(n − i) |
| Eliminar el último | `lista.pop()` | `v.pop_back()` | O(1) |
| Eliminar en la posición i | `lista.pop(i)` | `v.erase(v.begin() + i)` | O(n − i) |
| Tamaño | `len(lista)` | `v.size()` | O(1) |

**Pregunta para pensar:** ¿por qué `lista.pop()` es mucho más barato que `lista.pop(0)`?

## Reglas

- Trabaja **únicamente con listas** (`list` en Python, `std::vector` en C++).
- **No uses** `sort()`, `sorted()`, `reverse()`, `set` (ni `std::sort`, `std::reverse`, `std::set` o `std::unordered_set`): el objetivo es implementar tú el algoritmo.
- No crees estructuras auxiliares salvo que el enunciado lo permita. La lista que se devuelve como resultado sí está permitida.
- Al terminar cada ejercicio, **escribe su complejidad temporal** en el comentario que hay debajo de la función.

## Cómo trabajar

1. Descarga el repositorio («Code» → «Download ZIP») o clónalo con git.
2. Completa las funciones de `enunciado_base.py` o de `enunciado_base.cpp`.
3. Ejecuta las pruebas, que ya están escritas. Verás `OK` o `FALLA` para cada ejercicio:

   ```bash
   # Python
   python enunciado_base.py
   # C++
   g++ -std=c++17 -Wall -o practica2 enunciado_base.cpp && ./practica2
   ```

   Que todas las pruebas pasen es necesario, pero no suficiente: añade las tuyas si se te ocurren otros casos.

---

## Ejercicio 1 — Ordenación por inserción

Implementa la **ordenación por inserción** sobre una lista, modificándola **in-place**: no devuelvas una lista nueva, ordena la que recibes.

```python
def insertion_sort(lista):        # Python
```
```cpp
void insertion_sort(vector<int>& lista);   // C++
```

**Ejemplo:** `[7, 3, 5, 2, 9, 1]` queda como `[1, 2, 3, 5, 7, 9]`.

**Traza antes de programar.** Haz en papel la traza sobre `[7, 3, 5, 2]`:

```
i = 1   valor = 3   → [3, 7, 5, 2]
i = 2   valor = 5   → [3, 5, 7, 2]
i = 3   valor = 2   → [2, 3, 5, 7]
```

- ¿Qué elementos se desplazan en cada paso?
- ¿Cuántas comparaciones hay si la lista ya está ordenada?
- ¿Y si viene en orden inverso?

**Pistas:** usa índices y asignaciones, desplazando los elementos mayores una posición a la derecha hasta encontrar el hueco. Prueba la lista vacía, una lista de un elemento y una con valores repetidos.

**Responde:** ¿cuál es el mejor caso y el peor caso, y qué complejidad tiene cada uno?

---

## Ejercicio 2 — Fusionar dos listas ordenadas

Dadas dos listas **ya ordenadas**, construye una **tercera lista ordenada** con todos sus elementos, recorriéndolas **en una sola pasada**.

```python
def fusionar(a, b):               # Python: devuelve una lista nueva
```
```cpp
vector<int> fusionar(const vector<int>& a, const vector<int>& b);   // C++
```

**Ejemplos:**

| a | b | resultado |
|---|---|---|
| `[1, 4, 7]` | `[2, 3, 9]` | `[1, 2, 3, 4, 7, 9]` |
| `[]` | `[2, 5]` | `[2, 5]` |

**Pistas:**

- Usa dos índices, `i` para `a` y `j` para `b`.
- Añade al resultado con `append()` (`push_back()` en C++).
- **No** concatenes las listas para ordenarlas después.
- ¿Qué haces cuando una de las dos listas se acaba?

**Objetivo:** O(n + m), siendo n y m los tamaños de `a` y `b`. Explica por qué tu solución lo cumple y por qué concatenar y ordenar sería peor.

---

## Ejercicio 3 — Eliminar duplicados conservando el orden

Crea una **lista nueva** con la **primera aparición** de cada valor, manteniendo el orden original. La lista de entrada no se modifica.

```python
def sin_duplicados(lista):        # Python
```
```cpp
vector<int> sin_duplicados(const vector<int>& lista);   // C++
```

**Ejemplos:**

| entrada | resultado |
|---|---|
| `[3, 1, 3, 2, 1, 4]` | `[3, 1, 2, 4]` |
| `[]` | `[]` |

**Restricción:** solo puedes usar listas. Nada de `set`, `dict` ni equivalentes en C++.

**Responde:**

- ¿Cuál es el peor caso? ¿Por qué tu solución puede acabar siendo O(n²)?
- ¿Cuál es el mejor caso?
- ¿Qué estructura de datos permitiría bajar el coste a O(n)? (La veremos más adelante en la asignatura.)

---

## Para ir más allá (opcional)

1. **Contar comparaciones.** Modifica la ordenación por inserción para que devuelva el número de comparaciones. Pruébala con listas ordenadas, aleatorias y en orden inverso de tamaño 10, 100 y 1000, y compara los resultados con las fórmulas del mejor y el peor caso.
2. **Duplicados en una lista ordenada.** Si la lista ya viene ordenada, elimina los duplicados **in-place** en O(n), sin crear una lista nueva.
3. **Fusionar k listas.** Generaliza el ejercicio 2 para fusionar una lista de k listas ordenadas. ¿Qué complejidad obtienes?
4. **`pop()` frente a `pop(0)`.** Mide el tiempo que se tarda en vaciar una lista de 100 000 elementos con cada una de las dos operaciones. ¿Cuadra el resultado con la tabla de costes?

## Qué entregar

El fichero `enunciado_base.py` o `enunciado_base.cpp` con:

- las tres funciones completadas y todas las pruebas en `OK`;
- debajo de cada función, un comentario con su complejidad en el mejor y en el peor caso y una justificación breve.

---
