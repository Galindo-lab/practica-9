
/* Ejercicio 1. Solicitar al usuario ingresar un rango de valores, límite
 * inferior y superior.
 * Realizar una función que reciba un arreglo y almacene en él los números
 * primos que se encuentren dentro del rango.
 * Utilizar memoria dinámica para reservar justa la cantidad de memoria
 * para almacenar los números primos. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

void buscar_primos(int vmax,int vmin,int *primos);

int main() {

    int vmax,
        vmin,
        npri = 0;               /* numeros primos encontrados */

    int *primos = (int*) malloc( sizeof(int) );

    primos[0] = 2;

    printf("Ingrese los limites de la funcion (max min): ");
    scanf("%d %d",&vmin,&vmax);

    for(int i = vmin ; i <= vmax ; i++)
    {
        for(int j = 2 ; j < i ; j++)
        {
            if( i%j == 0 )
            {
                printf("%5d mod %5d | %4d \n",i,j,i%j);
                break;          /* Es multiplo de uno de los
                                 * numeros anteriores*/
            }
            else if (j+1 == i)  /* llego al final de los sin
                                 * encontrar un divisor */
            {
                npri++;         /* incrementar el tamaño */
                if((primos = (int*) realloc(primos, sizeof(int)*npri*2)) != NULL)
                {
                    primos[npri] = i;
                }
            }
        }
    }

    do{
        printf("%d\n",primos[npri]);
    }while(npri--);

    free(primos);

    return 0;
}
