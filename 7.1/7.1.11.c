/*7.1.11 Confeccionar un programa para:
a. Generar los vectores necesarios para guardar la información ingresada por teclado. Se ingresa los datos de 300 artículos
diferentes. De cada artículo se ingresa los siguientes datos:
• Código de artículo (int, entre 1 y 500).
• Clase de artículo (char, ‘A’ o ‘B’ o ‘C’ o ‘D’).
• Número de depósito donde se encuentra el artículo (int, entre 1 y 100).
• Stock (int, entre o y 2000).
• Punto de reposición (int, entre 500 y 1000).
b. Generar e informar el vector VB, que contenga los códigos de artículos de aquellos que hayan quedado con el saldo igual a
cero.
c. Generar e informar el vector VC, que contengo a los códigos de artículos de aquellos que hayan quedado con saldo por debajo
del punto de reposición.
d. Generar e informar el vector VD, que contengo los códigos de artículos de aquellos que están en los depósitos entre el 15 y
50.
Informar el/los códigos de el/los artículos que tienen el stock más alto. (puede haber varios artículos que tienen la misma
cantidad de stock).
FUNCIONES:
I. Para generar los vectores del punto a).
II. Para generar el vector VB.
III. Para generar el vector VC.
IV. Para generar el vector VD.*/

#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#define TAM 300

int ValidaIntEntre(int, int);
char ValidaCharEntre(char, char);
int BusquedaSecuencial(int[], int, int);
void GeneraVectorIntFor(int[], int[], int[], int[], int[], int);
int GeneraVB(int[], int[], int[], int);
int GeneraVC(int[], int[], int[], int[], int);
int GeneraVD(int[], int[], int[], int);
void MostrarVectorComoList(int[], int);
void MostrarMayorInt(int[], int[], int);

int main()
{
    int vecCodArt[TAM], vecClaseArt[TAM], vecDep[TAM], vecStock[TAM], vecPuntRep[TAM], VB[TAM], VC[TAM], VD[TAM], cantB, cantC, cantD;

    setlocale(LC_ALL, "spanish");

    printf("Se procederá a la carga de la base de datos de los artículos: \n");
    GeneraVectorIntFor(vecCodArt, vecClaseArt, vecDep, vecStock,vecPuntRep, TAM);
    cantB = GeneraVB(vecCodArt, vecStock, VB, TAM);
    printf("\nEl vector VB, que contiene los códigos de artículos de aquellos que quedaron con el saldo igual a cero, es: \n");
    printf("Código\n------\n");
    MostrarVectorComoList(VB, cantB);
    cantC = GeneraVC(vecCodArt, vecPuntRep, vecStock, VC, TAM);
    printf("\nEl vector VC, que contiene a los códigos de artículos de aquellos que quedaron con saldo por debajo del punto de reposición, es: \n");
    printf("Código\n------\n");
    MostrarVectorComoList(VC, cantC);
    cantD = GeneraVD(vecCodArt, vecDep, VD, TAM);
    printf("\nEl vector VD, que contiene los códigos de artículos de aquellos que están en los depósitos entre el 15 y 50, es: \n");
    printf("Código\n------\n");
    MostrarVectorComoList(VD, cantD);
    printf("\nLos códigos de los articulos que tienen mayor stock son: ");
    MostrarMayorInt(vecCodArt, vecStock, TAM);

    return 0;
}

/*//////////////////////////////////////////////////FUNCIONES//////////////////////////////////////////////*/

int ValidaIntEntre(int inf, int sup)
{
    int num, band=0;

    do
    {
        if(band)
            printf("El valor proporcionado debe ser un entero entre %d y %d. Intente nuevamente.\n", inf, sup);

        scanf("%d", &num);
        band = 1;
    } while(num<inf || num>sup);

    return num;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////*/

char ValidaCharEntre(char inf, char sup)
{
    int band=0;
    char letra;

    do
    {
        if(band)
            printf("El valor proporcionado debe ser una letra entre %c y %c. Intente nuevamente.\n", inf, sup);
        getchar();
        scanf("%c", &letra);
        letra = toupper(letra);
        band = 1;
    } while(letra<inf || letra>sup);

    return letra;
}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int BusquedaSecuencial(int v[], int num, int ce)
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

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void GeneraVectorIntFor(int vc[], int vcl[], int vd[], int vs[], int vpr[], int ce)
{
    int i, cod, pos;

    for(i=0; i<ce; i++)
    {
        do
        {
            printf("Ingrese código de artículo (1 a 500): ");
            cod = ValidaIntEntre(1, 500);
            pos = BusquedaSecuencial(vc, cod, i);
            if(pos!=-1)
                printf("\nEl código ingresado ya ha sido cargado. No se permiten códigos duplicados. Vuelva a intentarlo.\n");
        } while (pos!=-1);
        vc[i] = cod;
        printf("Ingrese la clase de artículo (A a D): ");
        vcl[i] = ValidaCharEntre('A', 'D');
        printf("Ingrese el número de deposito (1 a 100): ");
        vd[i] = ValidaIntEntre(1, 100);
        printf("Ingrese el stock del artículo (0 a 2000): ");
        vs[i] = ValidaIntEntre(0, 2000);
        printf("Ingrese la cantidad para el punto de reposición (500 a 1000): ");
        vpr[i] = ValidaIntEntre(500, 1000);
        printf("\nArtículo cargado, quedan %d por cargar.\n\n", ce-i-1);
    }
}

/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int GeneraVB(int vc[], int vs[], int vb[], int ce)
{
    int i, j=0;

    for(i=0; i<ce; i++)
    {
        if(vs[i] == 0)
        {
            vb[j] = vc[i];
            j++;
        }
    }
    return j;
}

/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int GeneraVC(int vcod[], int vpr[], int vs[], int vc[], int ce)
{
    int i, j=0;

    for(i=0; i<ce; i++)
    {
        if(vpr[i] > vs[i])
        {
            vc[j] = vcod[i];
            j++;
        }
    }
    return j;
}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int GeneraVD(int vc[], int vdep[], int vd[], int ce)
{
    int i, j=0;

    for(i=0; i<ce; i++)
    {
        if(vdep[i]>=15 && vdep[i]<=50)
        {
            vd[j] = vc[i];
            j++;
        }
    }
    return j;
}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void MostrarVectorComoList(int v[], int ce)
{
    int i;

    for(i=0; i<ce; i++)
        printf("%4d\n", v[i]);
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void MostrarMayorInt(int v1[], int v2[], int ce)
{
    int i = 0, mayor, codMayor;

    mayor = v2[i];
    codMayor = v1[i];

    for(i=1; i<ce; i++)
        if(mayor<=v2[i])
            mayor = v2[i];

    printf("\nMayor = %d\nCódigo", mayor);

    for(i=0; i<ce; i++)
        if(v2[i] == mayor)
            printf("\t%d", v1[i]);
}

