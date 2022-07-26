/*7.1.3 Realizar una función que reciba por parámetro dos vectores enteros de 5 elementos cada uno y genere un vector de 10 posiciones con el
contenido de ambos vectores intercalados.*/

#include<stdio.h>

void mergeVectIntercalado(int* vec1, int* vec2, int* vec3, int cantElem1Y2);
void mostrar(int* vect, const int cantElem);

int main()
{
    int vec1[5] = {1,2,3,4,5}, vec2[5] = {6,7,8,9,10}, vec3[10];

    mergeVectIntercalado(vec1, vec2, vec3, 5);
    printf("El vector fusionado intercalado es: ");
    mostrar(vec3, 10);

    return 0;
}



void mostrar(int* vect, const int cantElem)
{
    int* pVect;

    for(pVect = vect; pVect<vect + cantElem; pVect ++)
        printf("%d  ", *pVect);

    printf("\n\n");
}


void mergeVectIntercalado(int* vec1, int* vec2, int* vec3, int cantElem1Y2)
{
    int* pvec1 = vec1, * pvec2, * pvec3 = vec3;

    for(pvec2 = vec2; pvec2<= vec2 + cantElem1Y2 - 1; pvec2 ++)
    {
        *pvec3 = *pvec1;
        pvec1 ++;
        pvec3 ++;
        *pvec3 = *pvec2;
        pvec3 ++;
    }
}

