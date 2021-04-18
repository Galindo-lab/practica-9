
/* Ejercicio 2. Realizar una función que evalúe un polinomio a través de
 * sus coeficientes pasados en un arreglo unidimensional como parámetro.
 * El programa debe de solicitar al usuario el grado del polinomio que se
 * desea capturar. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

typedef struct {
    int **matrix;
    int width;
    int height;
} Matrix;

void initMatrix(Matrix *m, int width, int height)
{
    m->matrix = (int**) calloc ( sizeof(int*), width );

    for(int i = 0; i < height; i++)
    {
        m->matrix[i] = (int*) calloc (sizeof(int), height);
    }

    m->width = width;
    m->height = height;
}

void setMatrix(Matrix *m, int x, int y, int v)
{
    m->matrix[x][y] = v;
}

void inputMatrix(Matrix *mx)
{
    int capura = 0;
    for(int i = 0; i<mx->width ;i++)
    {
        for(int j = 0; j<mx->height;j++){
            printf("[%3d][%3d]:",i,j);
            scanf("%d", &capura);
            setMatrix(mx, i, j, capura);
        }
    }
}

void displayMatrix(Matrix *mx)
{
    printf("[\n");
    for(int i = 0; i<mx->width ;i++)
    {
        for(int j = 0; j<mx->height;j++){
            printf("%7d", mx->matrix[i][j] );
        }
        printf("\n");
    }
    printf("]\n");
}

int main() {
    int
        size;

    Matrix
        mx_1,
        mx_2,
        mx_r;

    printf("[size]: ");
    scanf("%d",&size);

    initMatrix(&mx_1, size, size);
    initMatrix(&mx_2, size, size);
    initMatrix(&mx_r, size, size);

    printf("matriz 1:\n");
    inputMatrix(&mx_1);

    printf("matriz 2:\n");
    inputMatrix(&mx_2);

    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            for (int inner = 0; inner < size; inner++) {
                mx_r.matrix[row][col] += mx_1.matrix[row][inner] * mx_2.matrix[inner][col];
            }
        }
    }


    displayMatrix(&mx_1);
    displayMatrix(&mx_2);
    displayMatrix(&mx_r);

    return 0;
}
