/*7.1.3 Realizar una funci�n que reciba por par�metro dos vectores enteros de 5 elementos cada uno y genere un vector de 10
posiciones con el contenido de ambos vectores intercalados.*/

#include <stdio.h>
#include <locale.h>

void CargaVectorForEnt (int[], int);
void IntercalarVector(int[], int[], int[], int, int, int);
void MostrarVectorEnt (int[], int);


int main()
{
    int vec1[5], vec2[5], vecT[10];

    setlocale(LC_ALL, "spanish");

    printf("Se ingresar� el primer vector de 5 n�meros enteros: \n");
    CargaVectorForEnt(vec1, 5);
    printf("Se ingresar� el segundo vector de 5 n�meros enteros: \n");
    CargaVectorForEnt(vec2, 5);
    IntercalarVector(vec1, vec2, vecT, 5, 5, 10);
    printf("\nEl vector intercalado es: \n");
    MostrarVectorEnt(vecT, 10);

    return 0;
}



/*///////////////////////////////////////////////////FUNCIONES///////////////////////////////////////////////////*/


void CargaVectorForEnt (int v[], int ce)
{
    int i;

    for(i=0; i<ce; i++)
    {
        printf("Posici�n %d: ", i+1);
        scanf("%d", &v[i]);
    }
}

void IntercalarVector (int v1[], int v2[], int vT[], int ce1, int ce2, int ceT)
{
    int i = 0, j = 0, k = 0;

    while (k < ceT && i+j <ceT)
    {
        if(k % 2 == 0)
        {
           vT[k] = v1[i];
           i++;
        }
        else
        {
            vT[k] = v2[j];
            j++;
        }
        k++;
    }
}


void MostrarVectorEnt (int v[], int ce)
{
    int i;

    for(i=0; i<ce; i++)
        printf("\t%d", v[i]);
}
