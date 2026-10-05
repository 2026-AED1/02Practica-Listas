"""
Práctica 2: Listas en Python — Código base
AED I · Bloque I

Completa las tres funciones. Reglas:
  - Trabaja únicamente con list de Python.
  - No uses sort(), sorted(), reverse() ni set.
  - Al terminar cada ejercicio, escribe en el comentario su complejidad temporal.

Para comprobar tu solución, ejecuta este fichero:
    python enunciado_base.py
(o, si tienes pytest instalado:  pytest enunciado_base.py)
"""


# ---------------------------------------------------------------------------
# Ejercicio 1 - Ordenación por inserción (in-place)
# ---------------------------------------------------------------------------
def insertion_sort(lista):
    """Ordena 'lista' de menor a mayor modificándola in-place. No devuelve nada."""
    # completa
    pass

# Complejidad -> mejor caso: ...   peor caso: ...


# ---------------------------------------------------------------------------
# Ejercicio 2 - Fusionar dos listas ordenadas en una sola pasada
# ---------------------------------------------------------------------------
def fusionar(a, b):
    """Devuelve una lista NUEVA y ordenada con los elementos de a y b (ya ordenadas)."""
    # completa
    pass

# Complejidad -> ...


# ---------------------------------------------------------------------------
# Ejercicio 3 - Eliminar duplicados conservando el orden
# ---------------------------------------------------------------------------
def sin_duplicados(lista):
    """Devuelve una lista NUEVA con la primera aparición de cada valor. Sin set."""
    # completa
    pass

# Complejidad -> peor caso: ...   ¿por qué?


# ---------------------------------------------------------------------------
# Pruebas (no hace falta modificarlas)
# ---------------------------------------------------------------------------
def test_ejercicio1():
    datos = [7, 3, 5, 2, 9, 1]
    insertion_sort(datos)
    assert datos == [1, 2, 3, 5, 7, 9]
    vacia = []
    insertion_sort(vacia)
    assert vacia == []
    uno = [42]
    insertion_sort(uno)
    assert uno == [42]
    repetidos = [2, 2, 1, 2]
    insertion_sort(repetidos)
    assert repetidos == [1, 2, 2, 2]
    inversa = [4, 3, 2, 1]
    insertion_sort(inversa)
    assert inversa == [1, 2, 3, 4]


def test_ejercicio2():
    assert fusionar([1, 4, 7], [2, 3, 9]) == [1, 2, 3, 4, 7, 9]
    assert fusionar([], [2, 5]) == [2, 5]
    assert fusionar([2, 5], []) == [2, 5]
    assert fusionar([], []) == []
    assert fusionar([1, 1, 3], [1, 2]) == [1, 1, 1, 2, 3]


def test_ejercicio3():
    assert sin_duplicados([3, 1, 3, 2, 1, 4]) == [3, 1, 2, 4]
    assert sin_duplicados([]) == []
    assert sin_duplicados([5, 5, 5]) == [5]
    original = [3, 1, 3]
    sin_duplicados(original)
    assert original == [3, 1, 3], "No modifiques la lista de entrada"


if __name__ == "__main__":
    for prueba in (test_ejercicio1, test_ejercicio2, test_ejercicio3):
        try:
            prueba()
            print(f"OK    {prueba.__name__}")
        except AssertionError as e:
            print(f"FALLA {prueba.__name__} {e}")
