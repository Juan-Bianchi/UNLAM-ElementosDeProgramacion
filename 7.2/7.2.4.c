/*7.2.4 Ingresar una matriz de 5x4 por teclado. Realizar una función que genere un vector con la suma por columna de dicha matriz.*/

#include <stdio.h>
#include <locale.h>
#define FILAS 5
#define COLUMNAS 4

void CargaMatrizInt(int[][COLUMNAS], int, int);
void VecSumaColMatInt(int[][COLUMNAS], int[], int, int);
void MostrarMatrizInt(int[][COLUMNAS], int, int);
void MostrarVector(int[], int);

int main()
{
    int mat[FILAS][COLUMNAS], vec[FILAS]={0};

    setlocale(LC_ALL, "spanish");

    CargaMatrizInt(mat, FILAS, COLUMNAS);
    MostrarMatrizInt(mat, FILAS, COLUMNAS);
    VecSumaColMatInt(mat, vec, FILAS, COLUMNAS);
    printf("\nLa suma de las columnas de la matriz expresadas en el vector es: \n");
    MostrarVector(vec, COLUMNAS);

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

void VecSumaColMatInt(int m[][COLUMNAS], int v[], int cf, int cc)
{
    int i, j;

    for(j=0; j<cc; j++)
        for(i=0; i<cf; i++)
            v[j] += m[i][j];
}

/*//////////////////////////////////////////////////////////////////////////////////////////////////*/

void MostrarVector(int v[], int ce)
{
    int i;

    for(i=0; i<ce; i++)
        printf("Columna %d\t%d\n", i+1, v[i]);
}

