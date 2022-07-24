/*7.1.10 Realizar los siguientes vectores con 10 valores reales. Confeccionar un programa para:
a. Generar el vector VA con la información ingresada por teclado.
b. Generar el vector VB, donde cada elemento es la raíz cuadrada del respectivo elemento de VA. (para el cálculo de la raíz
cuadrada utilizar la función sqrt disponible en la biblioteca math.h). Si el número es negativo poner un 0 ya que no se puede
calcular la raíz.
c. Calcular el vector VC como VA+VB.
d. Copiar el vector VC en orden inverso en otro vector llamado VD.
e. Hallar el valor máximo del vector VA y en qué posición se halló (el mayor es único).
f. Hallar el valor mínimo del vector VB y en qué posiciones se hallaron (el mínimo se pude repetir).
g. Dado un valor ingresado por teclado, indicar en qué posición se encontró del vector VC.
h. Ordenar el vector VD en forma ascendente (de menor a mayo).
i. Generar un vector VE con aquellos valores negativos que se encuentran en el vector VA.
j. Mostrar el contenido de todos los vectores.
FUNCIONES:
I. Para el ingreso del vector VA, del punto a).
II. Para generar el vector VC, del punto c).
III. Para realizar la búsqueda del punto g).
IV. Para realizar el ordenamiento del punto h).
V. Para generar el vector VE del punto i).
VI. Para mostrar los valores de todos los vectores del punto j).*/

#include <stdio.h>
#include <locale.h>
#include <math.h>
#define TAM 10

void CargaVectorForFloat(float[], int);
void Suma2Vectores(float[], float[], float[], int);
int BusquedaSecuencial(float[], float, int);
void OrdenaVecBurbMenAMay(float[], int);
int GeneraVecNeg(float[], float[], int);
void MostrarTodosVec(float[], float[], float[], float[], float[], int, int);

int main()
{
    float VA[TAM], VB[TAM], VC[TAM], VD[TAM], VE[TAM], max, min, raiz, num;
    int pos, posmax = 0, posmin = 0, i, cant;

    setlocale(LC_ALL, "spanish");

    printf("A continuación se procederá a la carga del vector VA: \n");
    CargaVectorForFloat(VA, TAM);                                           ///a///

    for(i=0; i<TAM; i++)                                                    ///b///
    {
        if(VA[i]<0)
            VB[i] = 0;
        else
            VB[i] = sqrt(VA[i]);
    }

    Suma2Vectores(VA, VB, VC, TAM);                                         ///c///

    for(i=0; i<TAM; i++)                                                    ///d///
        VD[9-i] = VA[i];

    max = VA[0];                                                            ///e///
    for(i=1; i<TAM; i++)
    {
        if(max<VA[i])
        {
            max = VA[i];
            posmax = i;
        }
    }
    printf("\nEl máximo del vector VA es %.2f y se encuentra en la posición %d.\n", max, posmax+1);

    min = VB[0];                                                             ///f///
    for(i=1;i<TAM;i++)
    {
        if(min>VB[i])
        {
            min = VB[i];
            posmin = i;
        }
    }
    printf("\nEl mínimo del vector VB es %.2f y las posiciones en que se encuentra son: ", min);
    for(i=0; i<TAM; i++)
    {
        if(min == VB[i])
            printf("%d, ", i+1);
    }

    printf("\n\nIngrese un número real por teclado que será buscado en el vector VC: ");        ///g///
    scanf("%f", &num);
    pos = BusquedaSecuencial(VC, num, TAM);
    if(pos==-1)
        printf("\nEl número proporcionado no ha sido encontrado.\n");
    else
        printf("\nEl número está en la posición %d\n", pos+1);

    OrdenaVecBurbMenAMay(VD, TAM);                                                              ///h///

    cant = GeneraVecNeg(VA, VE, TAM);                                                           ///i///

    MostrarTodosVec(VA, VB, VC, VD, VE, TAM, cant);                                             ///j///

    return 0;
}


/*////////////////////////////////////////////////FUNCIONES////////////////////////////////////////////*/


void CargaVectorForFloat(float v[], int ce)
{
    int i;

    for(i=0; i<ce; i++)
    {
        printf("Ingrese un número real: ");
        scanf("%f", &v[i]);
    }
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////*/

void Suma2Vectores(float v1[], float v2[], float v3[], int ce)
{
    int i;

    for(i=0; i<ce; i++)
        v3[i] = v1[i] + v2[i];
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////*/

int BusquedaSecuencial(float v[], float num, int ce)
{
    int pos = -1, i=0;

    while(i<ce && pos == -1)
    {
        if(num == v[i])
            pos = i;
        else
            i++;
    }
    return pos;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////*/

void OrdenaVecBurbMenAMay(float v[], int ce)
{
    int i = 0, j, cambio;
    float aux;

    do
    {
        for(j=1; j<ce-i; j++)
        {
            cambio = 0;
            if(v[j-1]>v[j])
            {
                aux = v[j-1];
                v[j-1] = v[j];
                v[j] = aux;

                cambio = 1;
            }
        }
        i++;
    } while (cambio);
}

/*//////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int GeneraVecNeg(float v1[], float v2[], int ce)
{
    int cant=0, i;

    for(i=0; i<ce; i++)
    {
        if(v1[i] < 0)
        {
            v2[cant] = v1[i];
            cant++;
        }
    }
    return cant;
}

/*//////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void MostrarTodosVec(float va[], float vb[], float vc[], float vd[], float ve[], int ce, int ceN)
{
    int i;

    printf("\nVector VA: [  ");
    for(i=0; i<ce; i++)
        printf("%.2f  ", va[i]);
    printf("]\n");

    printf("\nVector VB: [  ");
    for(i=0; i<ce; i++)
        printf("%.2f   ", vb[i]);
    printf("]\n");

    printf("\nVector VC: [  ");
    for(i=0; i<ce; i++)
        printf("%.2f   ", vc[i]);
    printf("]\n");

    printf("\nVector VD: [  ");
    for(i=0; i<ce; i++)
        printf("%.2f   ", vd[i]);
    printf("]\n");

    printf("\nVector VE: [  ");
    for(i=0; i<ceN; i++)
        printf("%.2f   ", vd[i]);
    printf("]\n");
}
