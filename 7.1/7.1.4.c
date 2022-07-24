/*7.1.4 Construir una función que reciba dos vectores enteros de igual tamaño y retorne un 1 si son guales o un 0 sino lo son.*/

#include <stdio.h>
#include <locale.h>

int EsIgualVector(int[], int[], int, int);
void CargaVectorForEnt(int[], int);


int main()
{
    int vec1[5], vec2[5], igual;

    setlocale(LC_ALL, "spanish");

    printf("Se ingresará el primer array de 5 números enteros: \n");
    CargaVectorForEnt(vec1, 5);
    printf("Se ingreseará el segundo array de 5 números enteros: \n");
    CargaVectorForEnt(vec2, 5);
    igual = EsIgualVector(vec1, vec2, 5, 5);
    if(igual)
        printf("\nLos dos vectores son IGUALES.\n");
    else
        printf("\nLos dos vectores NO son iguales.\n");

    return 0;
}


/*/////////////////////////////////////////////////////////FUNCIONES/////////////////////////////////////////////////*/

void CargaVectorForEnt (int v[], int ce)
{
    int i;

    for(i=0; i<ce; i++)
    {
        printf("Posición %d: ", i+1);
        scanf("%d", &v[i]);
    }
}


int EsIgualVector(int v1[], int v2[], int ce1, int ce2)
{
    int igual, i = 0;

    if(ce1 != ce2)
        igual = 0;
    else
    {
        while(i < ce1 && v1[i] == v2[i])
            i++;

        if(i==ce1)
            igual = 1;
        else
            igual = 0;
    }

    return igual;
}
