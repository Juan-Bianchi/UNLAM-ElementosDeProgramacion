/*7.1.10 Realizar los siguientes vectores con 10 valores reales. Confeccionar un programa para:
a. Generar el vector VA con la información ingresada por teclado.
b. Generar el vector VB, donde cada elemento es la raíz cuadrada del respectivo elemento de VA. (para el cálculo de la raíz cuadrada utilizar la
función sqrt disponible en la biblioteca math.h). Si el número es negativo poner un 0 ya que no se puede calcular la raíz
c. Calcular el vector VC como VA+VB.
d. Copiar el vector VC en orden inverso en otro vector llamado VD.
e. Hallar el valor máximo del vector VA y en qué posición se halló (el mayor es único).
f. Hallar el valor mínimo del vector VB y en qué posiciones se hallaron (el mínimo se pude repetir).
g. Dado un valor ingresado por teclado, indicar en qué posición se encontró del vector VC.
h. Ordenar el vector VD en forma ascendente (de menor a mayo).
i. Generar un vector VE con aquellos valores negativos que se encuentran en el vector VA.
j. Mostrar el contenido de todos los vectores.
FUNCIONES:
I. Para el ingreso del vector AA, del punto a).
II. Para generar el vector CC, del punto c).
III. Para realizar la búsqueda del punto g).
IV. Para realizar el ordenamiento del punto h).
V. Para generar el vector VE del punto i).
VI. Para mostrar los valores de todos los vectores del punto j).*/

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<windows.h>
#define TAM 10

void cargarVA(float* VA, const int cantElem);
void calcularVC(const float* VA, const float* VB, float* VC, const int cantElem);
int buscaMaximo(const float* VA, float* maximo, const int cantElem);
float buscarMinimo(const float* VB, const int cantElem);
void mostrarMinimos(const float* VB, const float minimo, const int cantElem);
int buscarEnVect(const float* vect, const float elem, const int cantElem);
void ordenaBurbujeoAscend(float* vect, const int cantElem);
void obtenerOpuestosVect(const float* vect, float* vectOp, const int cantElem);
void mostrarVector(const float* vect, const int cantElem);

int main()
{
    float VA[TAM], VB[TAM], VC[TAM], VD[TAM], VE[TAM], cantElemVE=0;
    float maximo, minimo, num;
    float* pVB = VB, * pVA, * pVC, * pVD = VD, * pVE = VE;
    int porc, maxPos, pos;

    printf("Se cargara el vector VA: \n");
    cargarVA(VA, TAM);

    printf("Se generara VB:\n");
    porc = 10;
    for(pVA = VA; pVA<=VA+TAM-1; pVA++)
    {
        printf("%d%%\r", porc);
        porc += 10;
        Sleep(100);
        *pVB = sqrt(abs(*pVA));
        pVB++;
    }
    printf("\nCompleto.\n");

    printf("\nSe generara VC:\n");
    calcularVC(VA, VB, VC, TAM);

    printf("Se generara VD:\n");
    porc = 10;
    for(pVC = VC + TAM -1; pVC>= VC; pVC--)
    {
        printf("%d%%\r", porc);
        porc += 10;
        Sleep(100);
        *pVD = *pVC;
        pVD++;
    }
    printf("\nCompleto.\n");
    mostrarVector(VD, TAM);

    maxPos = buscaMaximo(VA, &maximo, TAM);
    printf("\n\nEl valor maximo del vector VA es %.2f y su posicion es %d\n\n", maximo, maxPos);

    minimo = buscarMinimo(VB, TAM);
    printf("El valor minimo del vector VB es %.2f y estas son las posiciones en las que se encuentra: \n", minimo);
    mostrarMinimos(VB, minimo, TAM);

    printf("\nIngrese un numero real: ");
    fflush(stdin);
    scanf("%f", &num);
    fflush(stdin);
    pos = buscarEnVect(VC, num, TAM);
    if(pos==-1)
        printf("El elemento no se encuentra en el vector VC\n\n");
    else
        printf("El elemento se encuentra en la posicion %d del vector VC\n\n", pos);

    ordenaBurbujeoAscend(VD, TAM);
    printf("El vector VD ordenado de manera ascendente es: \n");
    mostrarVector(VD, TAM);

    for(pVA=VA; pVA<=VA+TAM-1; pVA++)
    {
        if(*pVA<0)
        {
            *pVE = *pVA;
            cantElemVE ++;
            pVE++;
        }
    }

    printf("\n\nVector VA: ");
    mostrarVector(VA, TAM);
    printf("\n");
    printf("Vector VB: ");
    mostrarVector(VB, TAM);
    printf("\n");
    printf("Vector VC: ");
    mostrarVector(VC, TAM);
    printf("\n");
    printf("Vector VD: ");
    mostrarVector(VD,TAM);
    printf("\n");
    printf("Vector VE: ");
    mostrarVector(VE, cantElemVE);

    return 0;
}



void cargarVA(float* VA, const int cantElem)
{
    float* pVA;

    for(pVA=VA; pVA<=VA+cantElem-1; pVA++)
    {
        printf("Ingrese un numero real: ");
        fflush(stdin);
        scanf("%f", pVA);
        fflush(stdin);
    }
}


void calcularVC(const float* VA, const float* VB, float* VC, const int cantElem)
{
    const float* pVA = VA, * pVB = VB;
    float* pVC;

    for(pVC=VC; pVC<=VC+cantElem-1; pVC++)
    {
        *pVC = *pVA + *pVB;
        pVA ++;
        pVB ++;
    }
}



int buscaMaximo(const float* VA, float* maximo, const int cantElem)
{
    const float* pVA = VA;
    int pos = 1, maxPos;

    *maximo = *pVA;

    for(pVA=VA+1; pVA<=VA+cantElem-1; pVA++)
    {
        pos++;
        if(*pVA>*maximo)
        {
            *maximo = *pVA;
            maxPos = pos;
        }
    }

    return maxPos;
}



float buscarMinimo(const float* VB, const int cantElem)
{
    const float* pVB = VB;
    float minimo;

    minimo = *pVB;

    for(pVB=VB+1; pVB<=VB+cantElem-1; pVB++)
    {
        if(*pVB<minimo)
            minimo = *pVB;
    }
    return minimo;
}



void mostrarMinimos(const float* VB, const float minimo, const int cantElem)
{
    const float* pVB;
    int pos = 1;

    for(pVB =VB; pVB<=VB+cantElem-1; pVB++)
    {
        if(*pVB == minimo)
            printf("%d  ", pos);
        pos++;
    }
    printf("\n");
}



int buscarEnVect(const float* vect, const float elem, const int cantElem)
{
    const float* pVect = vect;
    int pos = 1;

    while(pVect<=vect+cantElem-1 && *pVect!=elem)
    {
        pVect++;
        pos++;
    }

    return(*pVect==elem)? pos: -1;
}



void ordenaBurbujeoAscend(float* vect, const int cantElem)
{
    float* pVect, * desordenado,* cota = vect+cantElem-1, aux;

    do
    {
        desordenado = vect;
        for(pVect=vect; pVect<cota; pVect++)
        {
            if(*pVect>*(pVect+1))
            {
                aux= *pVect;
                *pVect = *(pVect+1);
                *(pVect+1) = aux;

                desordenado = pVect;
            }
        }
        cota = desordenado;
    } while(desordenado!=vect);
}



void obtenerOpuestosVect(const float* vect, float* vectOp, const int cantElem)
{
    const float* pVect;
    float* pVectOp = vectOp;

    for(pVect=vect; pVect<=vect+cantElem-1; pVect++)
    {
        *pVectOp = *pVect * -1;
        pVectOp++;
    }
}


void mostrarVector(const float* vect, const int cantElem)
{
    const float* pVect;

    for(pVect=vect; pVect<=vect+cantElem-1; pVect++)
        printf("%.2f   ", *pVect);

    printf("\n");
}
