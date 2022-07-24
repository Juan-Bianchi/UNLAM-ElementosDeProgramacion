/*7.1.1 Ingresar un vector de 10 unidades reales mediante una funci�n llamada CARGA. Luego mediante una segunda funci�n llamada
INVERTIR, generar un segundo vector del mismo tama�o con los elementos ubicados en el orden inverso al del vector original.
Mostrar el vector invertido con una funci�n llamada MOSTRAR.*/

#include <stdio.h>
#include <locale.h>

void CargaVectorFor (float[], int);
void InvertirVector (float[], float[], int);
void MostrarVector (float[], int);


int main()
{
    int cant;
    float vec[10], vecIn[10];
    setlocale(LC_ALL, "spanish");
    printf("Ingrese diez valores reales: \n");
    CargaVectorFor(vec, 10);
    printf("Los valores ingresados son: \n");
    MostrarVector(vec, 10);
    InvertirVector(vec, vecIn, 10);
    printf("\nLos valores invertidos son: \n");
    MostrarVector(vecIn, 10);

    return 0;
}


/*///////////////////////////////////////////////////FUNCIONES///////////////////////////////////////////////////*/


void CargaVectorFor (float v[], int ce)
{
    int i;

    for(i=0; i<ce; i++)
    {
        printf("Posici�n %d: ", i+1);
        scanf("%f", &v[i]);
    }
}


void InvertirVector (float v[], float vI[], int ce)
{
    int i;

    for(i=0; i<ce; i++)
        vI[ce-i-1] = v[i];
}


void MostrarVector (float v[], int ce)
{
    int i;

    for(i=0; i<ce; i++)
        printf("\t%.2f", v[i]);
}
