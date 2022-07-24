/*7.1.9 Se debe ingresar los códigos de 15 productos de una empresa (números de 3 dígitos). Luego se ingresan las ventas
realizadas durante el día. Por cada venta se ingresa código de vendedor, código de artículo y cantidad.
Los vendedores son 5 y están codificados en forma correlativa de 1001 a 1005. Se puede recibir más de una venta de un mismo
vendedor y artículo. El ingreso de datos finaliza con código de vendedor igual a 0. Se desea:
a. Mostrar un listado ordenado de mayor a menor por cantidad de unidades vendidas.
CANT UNIDADES       CÓDIGO
    XXX               XXX
    XXX               XXX
b. Indicar el/los vendedores que realizaron menor cantidad de ventas (no de unidades).*/


#include <stdio.h>
#include <locale.h>
#define TAM1 15
#define TAM2 5


int ValidaIntEntre(int, int);
int ValidaIntMayorA(int);
void MostrarVectorComoList(int[], int);
int BusquedaSecuencial(int[], int, int);
void Ordena2VecBurbMayAMen(int[], int[], int);
void Mostrar2VecLista(int[], int[], int);
void MostrarMenorInt(int[], int[], int);


int main()
{
    int vecCod[TAM1], vecCant[TAM1] = {0}, vecVend[TAM2]={1001, 1002, 1003, 1004, 1005}, vecSumVent[TAM2]= {0}, codV, codA, cant, i, pos, band, pos1;

    setlocale(LC_ALL, "spanish");

    printf("A continuación se deben proporcionar los 15 códigos que corresponderan a los productos (100 a 999): \n");
    for(i=0; i<TAM1; i++)
    {
        printf("Ingrese un código de producto (100 a 999): ");
        band = 0;
        do
        {
            if(band)
                printf("\nNo se pueden ingresar códigos de productos repetidos. Intente nuevamente.\n");
            codV = ValidaIntEntre(100, 999);
            pos = BusquedaSecuencial(vecCod, codV, i);
            band = 1;
        } while (pos!=-1);
        vecCod[i] = codV;
    }
    printf("%15s\n%15s\n", "Código", "------");
    MostrarVectorComoList(vecCod, TAM1);

    printf("\nSe procederá con la carga de las ventas: \n");
    printf("Ingrese el código de vendedor (1001 a 1005 o 0 para terminar): ");
    scanf("%d", &codV);
    while(codV!=0)
    {
        pos = BusquedaSecuencial(vecVend, codV, TAM2);
        if(pos==-1)
            printf("\nEl código de vendedor es inexistente.\n");
        else
        {
            printf("\nIngrese el código de artículo: ");
            scanf("%d", &codA);
            pos1 = BusquedaSecuencial(vecCod, codA, TAM1);
            if(pos1 == -1)
                printf("\nEl código de artículo es inexistente.\n");
            else
            {
                printf("\nIngrese la cantidad vendida: ");
                cant = ValidaIntMayorA(0);
                vecCant[pos1] += cant;
                vecSumVent[pos] ++;
            }
        }
        printf("Ingrese el código de vendedor (1001 a 1005 o 0 para terminar): ");
        scanf("%d", &codV);
    }
    Ordena2VecBurbMayAMen(vecCod, vecCant, TAM1);
    printf("\nEl listado ordenado de mayor a menor por cantidad de unidades vendidas es: \n");
    printf("%20s%15s\n", "CANT UNIDADES", "CÓDIGO");
    Mostrar2VecLista(vecCod, vecCant, TAM1);
    printf("Los vendedores que hicieron la menor cantidad de ventas son: \n");
    MostrarMenorInt(vecVend, vecSumVent, TAM2);

    return 0;
}


/*///////////////////////////////////////////FUNCIONES////////////////////////////////////////////////////////*/

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

/////////////////////////////////////////////////////////////////////////////////////////////////////////

int ValidaIntMayorA(int inf)
{
    int num, band=0;

    do
    {
        if(band)
            printf("El valor proporcionado debe ser mayor a %d. Intente nuevamente.\n", inf);

        scanf("%d", &num);
        band = 1;
    } while(num<inf);

    return num;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////

void MostrarVectorComoList(int v[], int ce)
{
    int i;

    for(i=0; i<ce; i++)
        printf("%15d\n", v[i]);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Ordena2VecBurbMayAMen(int vec1[], int vec2[], int ce)
{
    int i = 0, j, aux, cambio;


    do
    {
        for(j=1; j<ce-i; j++)
        {
            cambio = 0;
            if(vec2[j]>vec2[j-1])
            {
                aux = vec2[j-1];
                vec2[j-1] = vec2[j];
                vec2[j] = aux;

                aux = vec1[j-1];
                vec1[j-1] = vec1[j];
                vec1[j] = aux;

                cambio = 1;
            }
        }
        i++;
    } while (cambio);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Mostrar2VecLista(int v1[], int v2[], int ce)
{
    int i;

    for(i=0; i<ce; i++)
        printf("%15d%20d\n", v2[i], v1[i]);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

void MostrarMenorInt(int v1[], int v2[], int ce)
{
    int i = 0, menor, codMenor;

    menor = v2[i];
    codMenor = v1[i];

    for(i=1; i<ce; i++)
        if(menor>=v2[i])
            menor = v2[i];

    for(i=0; i<ce; i++)
        if(v2[i] == menor)
            printf("\t%d", v1[i]);
}
