
#include <stdlib.h>
#include <stdio.h>

typedef struct {
     int *array;
     int used;
     int size;
} Array ;

void initArray(Array *a, int initialSize)
{
     a->array = (int*) malloc( initialSize * sizeof(int) );
     a->used = 0;
     a->size = initialSize;
}

void insertArray(Array *a, int element)
{
     if(a->used == a->size)
     {
          a->size *= 2;
          a->array = realloc( a->array, a->size * sizeof(int) );
     }

     a->array[a->used++] = element;
}

void freeArray(Array *a)
{
     free(a->array);
     a->array = NULL;
     a->used = a->size = 0;
}
