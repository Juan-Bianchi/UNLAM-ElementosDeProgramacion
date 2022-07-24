/*7.2.3 Ingresar una matriz de 5x4 por teclado. Realizar una función que genere un vector con la suma por fila de dicha matriz.*/

#include <stdio.h>
#include <locale.h>
#define FILAS 5
#define COLUMNAS 4

void CargaMatrizInt(int[][COLUMNAS], int, int);
void VecSumaFilaMatInt(int[][COLUMNAS], int[], int, int);
void MostrarMatrizInt(int[][COLUMNAS], int, int);
void MostrarVector(int[], int);

int main()
{
    int mat[FILAS][COLUMNAS], vec[FILAS] = {0};

    setlocale(LC_ALL, "spanish");

    CargaMatrizInt(mat, FILAS, COLUMNAS);
    printf("\n");
    MostrarMatrizInt(mat, FILAS, COLUMNAS);

    printf("\nLa suma de las filas de la matríz expresadas en el vectos son: \n");
    VecSumaFilaMatInt(mat, vec, FILAS, COLUMNAS);
    MostrarVector(vec, FILAS);

    return 0;
}

/*/////////////////////////////////////////////FUNCIONES////////////////////////////////////////*/

void CargaMatrizInt(int m[][COLUMNAS], int cf, int cc)
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

void MostrarMatrizInt(int m[][COLUMNAS], int cf, int cc)
{
    int i, j;

    for(i=0; i<cf; i++)
    {
        for(j=0; j<cc; j++)
            printf("%d\t", m[i][j]);

        printf("\n");
    }
}

/*/////////////////////////////////////////////////////////////////////////////////////////////////*/

void VecSumaFilaMatInt(int m[][COLUMNAS], int v[], int cf, int cc)
{
    int i, j;

    for(i=0; i<cf; i++)
        for(j=0; j<cc; j++)
            v[i] += m[i][j];
}

/*//////////////////////////////////////////////////////////////////////////////////////////////////*/

void MostrarVector(int v[], int ce)
{
    int i;

    for(i=0; i<ce; i++)
        printf("Fila %d\t%d\n", i+1, v[i]);
}
