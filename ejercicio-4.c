
/* Ejercicio 4. Crear una función que reciba un arreglo unidimensional con
 * números enteros, así como un parámetro que indique su tamaño y un
 * apuntador donde se almacenará el número de elementos no repetidos.
 * La función debe regresar la dirección a un nuevo arreglo donde se
 * encuentren los valores no repetidos. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#include "array.c"

void eliminar_repetidos(int *a, int a_size, Array *b);

int main() {
    int a[] = {1,2,2,3,3,5,3,4,4,4,4};

    Array b;
    initArray(&b, 2);
    eliminar_repetidos(a, 10, &b);

    for(int i = 0; i < b.used; i++)
    {
        printf("%d \n",b.array[i]);
    }


    freeArray(&b);

    return 0;
}

void eliminar_repetidos(int *a, int a_size, Array *b)
{
    insertArray(b, a[0]);
    for(int i = 0 ; i < a_size; i++)
    {
        for(int j = 0; j < b->used;j++)
        {
            if( b->array[j] == a[i] )
            {
                break;
            }
            else if( j+1 >= b->used )
            {
                insertArray(b,a[i]);
            }
        }

    }

}
