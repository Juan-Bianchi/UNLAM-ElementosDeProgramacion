/*7.1.2 Realizar una función que reciba por parámetro dos vectores enteros de 5 elementos cada uno y genere un vector de 10
posiciones con el contenido de ambos vectores uno a continuación del otro.*/

#include <stdio.h>
#include <locale.h>

void CargaVectorForEnt (int[], int);
void ConcatenarVector(int[], int[], int[], int, int, int);
void MostrarVectorEnt (int[], int);

int main()
{
    int vec1[5], vec2[5], vecT[10];

    setlocale(LC_ALL, "spanish");

    printf("Se ingresará el primer vector de 5 números enteros: \n");
    CargaVectorForEnt(vec1, 5);
    printf("Se ingresará el segundo vector de 5 números enteros: \n");
    CargaVectorForEnt(vec2, 5);
    ConcatenarVector(vec1, vec2, vecT, 5, 5, 10);
    printf("\nEl vector concatenado es: \n");
    MostrarVectorEnt(vecT, 10);

    return 0;
}



/*///////////////////////////////////////////////////FUNCIONES///////////////////////////////////////////////////*/


void CargaVectorForEnt (int v[], int ce)
{
    int i;

    for(i=0; i<ce; i++)
    {
        printf("Posición %d: ", i+1);
        scanf("%d", &v[i]);
    }
}

void ConcatenarVector (int v1[], int v2[], int vT[], int ce1, int ce2, int ceT)
{
    int i = 0, j = 0;

    while (i < ce1 && i < ceT)
    {
       vT[i] = v1[i];
       i++;
    }

    while (j < ce2 && i+j < ceT)
    {
        vT[i+j] = v2[j];
        j++;
    }

}


void MostrarVectorEnt (int v[], int ce)
{
    int i;

    for(i=0; i<ce; i++)
        printf("\t%d", v[i]);
}
