/*7.1.12 Dados los legajos y sueldos de los empleados de una empresa (máximo 100 empleados). Se pide determinar el/los
empleados/as de máximo sueldo. El fin de carga de sueldos está dado por un legajo igual a cero.
a. Los números de legajo son números correlativos de 1 a 100.
b. Realizar el mismo ejercicio considerando que los números de legajos son números NO correlativos de 4 cifras.*/

#include <stdio.h>
#include <locale.h>
#define TAM 100

int ValidaIntCorrYFin(int, int);
float ValidaFloatMayA(int);
void MostrarMayorFloat(int[], float[], int);


int main()
{
    int vecLeg[TAM], maxLeg, i=0, leg;
    float vecSuel[TAM], max;

    setlocale(LC_ALL, "spanish");

    printf("A continuación se procederá a la carga de los empleados: \n");
    printf("\nIngrese número de legajo (Correlativo de 1 a 100 o 0 para terminar): ");
    leg = ValidaIntCorrYFin(i, 0);
    while(leg!=0 && i<TAM)
    {
        vecLeg[i] = leg;
        printf("\nIngrese el sueldo del empleado: ");
        vecSuel[i] = ValidaFloatMayA(0);
        i++;
        printf("\nIngrese número de legajo (Correlativo de 1 a 100 o 0 para terminar): ");
        leg = ValidaIntCorrYFin(i, 0);
    }
    printf("\nLos empleados de máximo sueldo son: \n");
    MostrarMayorFloat(vecLeg, vecSuel, i);

    return 0;
}

/*/////////////////////////////////////////////FUNCIONES////////////////////////////////////////////////*/

int ValidaIntCorrYFin(int n, int cf)
{
    int num, band=0;

    do
    {
        if(band)
            printf("El valor proporcionado debe ser correlativo a %d o %d para terminar. Intente nuevamente.\n", n, cf);

        scanf("%d", &num);
        band = 1;
    } while(num!=n+1 && num!=cf);

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

