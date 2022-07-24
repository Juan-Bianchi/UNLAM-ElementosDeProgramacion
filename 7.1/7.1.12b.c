/*7.1.12 Dados los legajos y sueldos de los empleados de una empresa (máximo 100 empleados). Se pide determinar el/los
empleados/as de máximo sueldo. El fin de carga de sueldos está dado por un legajo igual a cero.
a. Los números de legajo son números correlativos de 1 a 100.
b. Realizar el mismo ejercicio considerando que los números de legajos son números NO correlativos de 4 cifras.*/

#include <stdio.h>
#include <locale.h>
#define TAM 100

int ValidaIntEntreYFin(int, int, int);
float ValidaFloatMayA(int);
int BusquedaSecuencial(int[], int, int);
void MostrarMayorFloat(int[], float[], int);


int main()
{
    int vecLeg[TAM], maxLeg, i=0, leg, pos;
    float vecSuel[TAM], max;

    setlocale(LC_ALL, "spanish");

    printf("A continuación se procederá a la carga de los empleados: \n");
    printf("\nIngrese número de legajo (de 1000 a 9999 o 0 para terminar): ");
    leg = ValidaIntEntreYFin(1000, 9999, 0);
    while(leg!=0 && i<TAM)
    {
        pos = BusquedaSecuencial(vecLeg, leg, i);
        if(pos!=-1)
            printf("\nEl legajo proporcionado ya ha sido ingresado. No puede haber duplicados. Vuelva a intentarlo.\n");
        else
        {
            vecLeg[i] = leg;
            printf("\nIngrese el sueldo del empleado: ");
            vecSuel[i] = ValidaFloatMayA(0);
            i++;
        }
        printf("\nIngrese número de legajo (de 1000 a 9999 o 0 para terminar): ");
        leg = ValidaIntEntreYFin(1000, 9999, 0);
    }
    printf("\nLos empleados de máximo sueldo son: \n");
    MostrarMayorFloat(vecLeg, vecSuel, i);

    return 0;
}

/*/////////////////////////////////////////////FUNCIONES////////////////////////////////////////////////*/

int ValidaIntEntreYFin(int inf, int sup, int cf)
{
    int num, band=0;

    do
    {
        if(band)
            printf("El valor proporcionado debe ser un entero entre %d y %d, o %d para terminar. Intente nuevamente.\n", inf, sup, cf);

        scanf("%d", &num);
        band = 1;
    } while((num<inf || num>sup) && num!=cf);

    return num;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////*/

float ValidaFloatMayA(int inf)
{
    float num;
    int band = 0;

    do
    {
        if(band)
            printf("El valor proporcionado debe ser mayor a %d. Intente nuevamente.\n", inf);

        scanf("%f", &num);
        band = 1;
    } while(num<inf);

    return num;
}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void MostrarMayorFloat(int v1[], float v2[], int ce)
{
    int i = 0, codMayor;
    float mayor;

    mayor = v2[i];
    codMayor = v1[i];

    for(i=1; i<ce; i++)
        if(mayor<=v2[i])
            mayor = v2[i];

    printf("\nMayor = %.2f\nLegajo", mayor);

    for(i=0; i<ce; i++)
        if(v2[i] == mayor)
            printf("\t%d", v1[i]);
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
