/*7.2.1 Ingresar una matriz de 3x3 por teclado y un número entero. Realizar el producto de la matriz por la constante*/

#include <stdio.h>
#include <locale.h>
#define TAM1 3
#define TAM2 3
#define CONSTANTE 6

void CargaMatrizInt(int[][TAM2], int, int);
void MostrarMatrizInt(int[][TAM2], int, int);

int main()
{
    int mat[TAM1][TAM2], i, j;

    setlocale(LC_ALL, "spanish");

    CargaMatrizInt(mat, TAM1, TAM2);
    for(i=0; i<TAM1; i++)
    {
        for(j=0; j<TAM2; j++)
            mat[i][j] *= CONSTANTE;
    }
    MostrarMatrizInt(mat, TAM1, TAM2);

    return 0;
}

/*////////////////////////////////////////////FUNCIONES////////////////////////////////////////////*/

void CargaMatrizInt(int m[][TAM2], int cf, int cc)
{
     int i, j;

     for(i=0; i<cf; i++)
     {
         for(j=0; j<cc; j++)
        {
            printf("Ingrese el valor [%d %d] de la matríz: ", i, j);
            scanf("%d", &m[i][j]);
        }
     }
}

/*////////////////////////////////////////////////////////////////////////////////////////////////*/

void MostrarMatrizInt(int m[][TAM2], int cf, int cc)
{
    int i, j;

    for(i=0; i<cf; i++)
    {
        for(j=0; j<cc; j++)
            printf("%d\t", m[i][j]);

        printf("\n");
    }
}

