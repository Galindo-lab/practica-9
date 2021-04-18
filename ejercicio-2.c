
/* Ejercicio 2. Realizar una función que evalúe un polinomio a través de
 * sus coeficientes pasados en un arreglo unidimensional como parámetro.
 * El programa debe de solicitar al usuario el grado del polinomio que se
 * desea capturar. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#include "array.c"

float horner(Array *coef, float x);

int main() {

    int
        coef_size = 0,
        captura;

    float
        num_eval;

    Array eq;

    printf("Cuantos coeficientes desea ingresar: ");
    scanf("%d", &coef_size);

    initArray(&eq, coef_size);  /* inicializar arreglo */

    while(coef_size--)          /* ingresar coeficientes */
    {
        printf("Coeficeinte del expoente %3d: ",coef_size);
        scanf("%d", &captura);
        insertArray(&eq,captura);
    }

    printf("Numero a evaluar:");
    scanf("%f",&num_eval);

    horner(&eq, num_eval);      /* evalua el numero
                                 * ingresado*/

    freeArray(&eq);             /* libera la memoria */

    return 0;
}

float horner(Array *coef , float x) /* metodo de horner*/
{
    float result = 0;
    for(int i=0;i < coef->used;i++)
    {
        result = result * x + (float)coef->array[i];
    }

    printf("%.2f\n",result);

    return 0;
}
