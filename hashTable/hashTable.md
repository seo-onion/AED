# Hash Table
Estructura de datos que, al igual que los _arrays_, utiliza indices para almacenar datos, sin embargo, las hash table utilizan la _keys_ para asignar un índice a un par ordenado conformado por: 

|    ||
|-            |-|
|key |value|



## Hash function
Es la función encargada de convertir cada _key_ en un índice en el cual se almacenará el par **(key, value)**.

## Colisiones
En muchos casos la _hash function_ puede asignar el mismo índice a dos pares **(key, value)** distintos, en ese caso existen diversas formas de abortar la problemática.

- Open addressing:
    Almacenamos el par **(key, value)** en algún indice cercano al dado por la _hash function_. 
- Chaining: 
    En lugar de almacenar un par **(key, value)**, almacenamos una _linked list_, la cual irá almacenando los pares **(key, value)** conforme la _hash function_ vaya asignando indices iguales a diferentes _keys_.

## Time Complexity

|Access|Search|Insertion|Deletion|Access|Search|insertion|Deletion|
|-|-|-|-|-|-|-|-|
|N/A|O(1)|O(1)|O(1)|N/A|O(N)|O(N)|O(N)|

## Factor de carga
Es una medida que indica que tan llena está la tabla

``` bash
a = m / n
# m elementos
# n capacidad maxima
```

- Si el factor de carga es muy alto (cerca de 1) → más colisiones → peor rendimiento.

- Si el factor de carga es bajo (mucho menor a 1) → menos colisiones → mejor rendimiento, pero más espacio desperdiciado.

#### Chaining tolera factores de carga mayores.

#### Open addressing necesita que α < 1 (no puede haber más elementos que posiciones).