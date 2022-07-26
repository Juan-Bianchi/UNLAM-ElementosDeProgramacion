/*7.1.1 Ingresar un vector de 10 unidades reales mediante una función llamada CARGA. Luego mediante una segunda función llamada
INVERTIR, generar un segundo vector del mismo tamaño con los elementos ubicados en el orden inverso al del vector original. Mostrar el
vector invertido con una función llamada MOSTRAR.*/


#include<stdio.h>


void carga(float* vect, const int cantElem);
void invertir(float* vect, float* vecInv, const int cantElem);
void mostrar(float* vect, const int cantElem);

int main()
{
    float vect[10], vectInv[10];

    printf("A continuacion se procedera con la carga de los elementos del vector: \n");
    carga(vect, 10);
    printf("\n\n");
    printf("El vector cargado es: ");
    mostrar(vect, 10);
    invertir(vect, vectInv, 10);
    printf("\n\n");
    printf("El vector invertido es: ");
    mostrar(vectInv, 10);

    return 0;
}


void carga(float* vect, const int cantElem)
{
    float* pVect;

    for(pVect = vect; pVect<vect + cantElem; pVect ++)
    {
        printf("Ingrese un numero real: ");
        fflush(stdin);
        scanf("%f", pVect);
        fflush(stdin);
    }
}


void invertir(float* vect, float* vecInv, const int cantElem)
{
    float* pVect, * pVectInv = vecInv;

    for(pVect = vect + cantElem - 1; pVect >= vect; pVect -- )
    {
        *pVectInv = *pVect;
        pVectInv ++;
    }
}



void mostrar(float* vect, const int cantElem)
{
    float* pVect;

    for(pVect = vect; pVect<vect + cantElem; pVect ++)
        printf("%.2f  ", *pVect);

    printf("\n\n");
}
