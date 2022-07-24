/*7.2.2 Ingresar una matriz de 2x3 por teclado. Calcular la matriz transpuesta.*/

#include <stdio.h>
#include <locale.h>
#define FILAS 2
#define COLUMNAS 3

void TransponerMatrizFloat(float[][COLUMNAS], float[][FILAS], int, int);
void CargaMatrizFloat(float[][COLUMNAS], int, int);
void MostrarMatrizFloat(float[][COLUMNAS], int, int);
void MostrarMatrizTransFloat(float[][FILAS], int, int);


int main()
{
    int i , j;
    float mat[FILAS][COLUMNAS], matTRan[COLUMNAS][FILAS];

    setlocale(LC_ALL, "spanish");

    CargaMatrizFloat(mat, FILAS, COLUMNAS);
    MostrarMatrizFloat(mat, FILAS, COLUMNAS);

    printf("A continuación se procederá a trasponer e informar la matriz: \n");
    TransponerMatrizFloat(mat, matTRan, FILAS, COLUMNAS);
    MostrarMatrizTransFloat(matTRan, COLUMNAS, FILAS);

    return 0;
}

/*///////////////////////////////////////////////////////////FUNCIONES////////////////////////////////////////////*/

void CargaMatrizFloat(float m[][COLUMNAS], int cf, int cc)
{
     int i, j;

     for(i=0; i<cf; i++)
     {
         for(j=0; j<cc; j++)
        {
            printf("Ingrese el valor [%d %d] de la matríz: ", i, j);
            scanf("%f", &m[i][j]);
        }
     }
}

/*////////////////////////////////////////////////////////////////////////////////////////////////*/

void MostrarMatrizFloat(float m[][COLUMNAS], int cf, int cc)
{
    int i, j;

    for(i=0; i<cf; i++)
    {
        for(j=0; j<cc; j++)
            printf("%.2f\t", m[i][j]);

        printf("\n");
    }
}

/*////////////////////////////////////////////////////////////////////////////////////////////////*/

void TransponerMatrizFloat(float m1[][COLUMNAS], float m2[][FILAS], int cf, int cc)
{
    int i, j;

    for(i=0; i<cf; i++)
        for(j=0; j<cc; j++)
            m2[j][i] = m1[i][j];
}


/*////////////////////////////////////////////////////////////////////////////////////////////////*/

void MostrarMatrizTransFloat(float m[][FILAS], int cf, int cc)
{
    int i, j;

    for(i=0; i<cf; i++)
    {
        for(j=0; j<cc; j++)
            printf("%.2f\t", m[i][j]);

        printf("\n");
    }
}

/*////////////////////////////////////////////////////////////////////////////////////////////////*/
