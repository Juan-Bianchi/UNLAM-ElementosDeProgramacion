/*7.1.14 Una fábrica produce 14 tipos de muebles de oficina con la mano de obra de 25 operarios especializados.
Al finalizar el mes se genera una planilla donde cada registro indica:
• Día hábil del mes de fabricación (entero, de 1 a 22).
• Tipo de mueble que se fabricó (entero, de 1 a 14).
• Código del operario que fabricó el mueble (entero, de 1 a 25).
En la última información presentada, se ingresó un día hábil negativo. No hay orden alguno en los datos ingresados y un mismo
operario puede hacer más de un mueble (del mismo tipo o no) durante el mes. Determinar e informar:
a. La cantidad de cada tipo de mueble fabricado durante el mes.
b. El tipo de mueble del cual se ha fabricado la mayor cantidad. (puede haber más de uno).
c. El listado ordenado en forma ascendente por cantidad de muebles fabricados por operario (sin importar el tipo), indicando:
Código de Operario      Cantidad de muebles fabricados
        XX                          XXX
d. El día o días hábiles en los cuales no hubo producción.*/

#include <stdio.h>
#include <locale.h>
#define TAM1 14
#define TAM2 25
#define TAM3 22

int ValidaIntEntre(int, int);
int ValidaIntEntreYFin(int, int, int);
int HallarMayorInt(int[], int);
void MostrarIgualAInt(int[], int, int);
void Ordena2VecBurbMenAMay(int[], int[], int);
void MostrarVector(int[], int);
void Mostrar2VecLista(int[], int[], int);


int main()
{
    int vecContTipMueb[TAM1] = {0}, vecContMuebXOp[TAM2] = {0}, vecOp[TAM2], vecDia[TAM3] = {0}, mayor, diaH , tipoM, codOp, i;

    setlocale(LC_ALL, "spanish");

    printf("A continuación se procederá con la carga de la fabricación mensual: \n");

    printf("Ingrese el número de día (1 a 22 o menor a 0 para terminar): ");
    diaH = ValidaIntEntreYFin(1, TAM3, 0);
    while(diaH>0)
    {
        printf("Ingrese el tipo de mueble (1 a 14): ");
        tipoM = ValidaIntEntre(1, TAM1);
        printf("Ingrese el código de operario (1 a 25): ");
        codOp = ValidaIntEntre(1, TAM2);
        vecContMuebXOp[codOp-1] ++;
        vecContTipMueb[tipoM-1] ++;
        vecDia[diaH-1] ++;

        printf("Ingrese el número de día (1 a 22 o menor a 0 para terminar): ");
        diaH = ValidaIntEntreYFin(1, TAM3, 0);
    }
    printf("\nLa cantidad de cada tipo de mueble fabricado durante el mes es:\nTipo\tCantidad\n");              /////A/////
    MostrarVector(vecContTipMueb, TAM1);

    mayor = HallarMayorInt(vecContTipMueb, TAM1);                                               /////B/////
    printf("\n El/los tipo/s de mueble/s del cual se ha/han fabricado la mayor cantidad: \n");
    MostrarIgualAInt(vecContTipMueb, mayor, TAM1);
    printf("Y la cantidad fabricada es: %d\n", mayor);

    for(i=0; i<TAM2; i++)                                                                            /////C/////
        vecOp[i] = i+1;
    Ordena2VecBurbMenAMay(vecOp, vecContMuebXOp, TAM2);
    printf("\nEl listado ordenado en forma ascendente por cantidad de muebles fabricados por operario es: \n");
    printf("%18s%36s\n", "Código de Operario", "Cantidad de muebles fabricados");
    Mostrar2VecLista(vecOp, vecContMuebXOp, TAM2);

    printf("\nEl día o días hábiles en los cuales no hubo producción:\n");                      /////D/////
    MostrarIgualAInt(vecDia, 0, TAM3);

    return 0;
}

/*/////////////////////////////////////////////FUNCIONES////////////////////////////////////////////////*/

int ValidaIntEntreYFin(int inf, int sup, int cf)
{
    int num, band=0;

    do
    {
        if(band)
            printf("El valor proporcionado debe ser un entero entre %d y %d, o menor a %d para terminar. Intente nuevamente.\n", inf, sup, cf);

        scanf("%d", &num);
        band = 1;
    } while((num<inf || num>sup) && num!=cf);

    return num;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////*/

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

int HallarMayorInt(int v[], int ce)
{
    int i = 0, mayor;

    mayor = v[i];

    for(i=1; i<ce; i++)
        if(mayor<=v[i])
            mayor = v[i];

    return mayor;
}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void MostrarIgualAInt(int v[], int num, int ce)
{
    int i;

    for(i=0; i<ce; i++)
    {
        if(v[i] == num)
            printf("%d\n", i+1);
    }
}
/*////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void Ordena2VecBurbMenAMay(int vecCuen[], int vecSec[], int ce)
{
    int i = 0, j, aux, cambio;


    do
    {
        for(j=1; j<ce-i; j++)
        {
            cambio = 0;
            if(vecCuen[j-1]>vecCuen[j])
            {
                aux = vecCuen[j-1];
                vecCuen[j-1] = vecCuen[j];
                vecCuen[j] = aux;

                aux = vecSec[j-1];
                vecSec[j-1] = vecSec[j];
                vecSec[j] = aux;

                cambio = 1;
            }
        }
        i++;
    } while (cambio);
}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void MostrarVector(int v[], int ce)
{
    int i;

    for(i=0; i<ce; i++)
        printf("%d\t%d\n", i+1, v[i]);
}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void Mostrar2VecLista(int v1[], int v2[], int ce)
{
    int i;

    for(i=0; i<ce; i++)
        printf("%9d%27d\n", v1[i], v2[i]);
}
