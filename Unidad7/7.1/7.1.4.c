/*7.1.4 Construir una función que reciba dos vectores enteros de igual tamaño y retorne un 1 si son guales o un 0 sino lo son.*/

#include <stdio.h>
#include <string.h>

typedef int booleano;

booleano comparaVectores(const int* vec1, const int* vec2, const int cantElem);
void mostrar(int* vect, const int cantElem);

int main()
{
    int vec1[5] = {1,2,3,4,5}, vec2[5]={1,2,3,5,5}, vec3[5]={1,2,3,4,5};
    booleano sonIguales;

    puts("Vector 1:");
    mostrar(vec1, 5);
    puts("Vector 2:");
    mostrar(vec2, 5);
    sonIguales = comparaVectores(vec1, vec2, 5);
    if(sonIguales)
        printf("Los vectores son iguales.\n\n");
    else
        printf("Los vectores no son iguales\n\n");

    puts("Vector 1:");
    mostrar(vec1, 5);
    puts("Vector 3:");
    mostrar(vec3, 5);
    sonIguales = comparaVectores(vec1, vec3, 5);
    if(sonIguales)
        printf("Los vectores son iguales.\n");
    else
        printf("Los vectores no son iguales\n");

    return 0;
}


void mostrar(int* vect, const int cantElem)
{
    int* pVect;

    for(pVect = vect; pVect<vect + cantElem; pVect ++)
        printf("%d  ", *pVect);

    printf("\n\n");
}


booleano comparaVectores(const int* vec1, const int* vec2, const int cantElem)
{
    const int* pVec1 = vec1, * pvec2 = vec2;

    while(pVec1 <= vec1 + cantElem -1 && *pVec1 == *pvec2)
    {
        pVec1 ++;
        pvec2 ++;
    }

    return pVec1 == vec1 + cantElem;
}
