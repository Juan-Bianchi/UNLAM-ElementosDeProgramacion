/*7.1.7 Se ingresan DNI, código de sector (1 a 5) y sueldo de los empleados de una empresa. Se sabe que como máximo la empresa
tiene 100 empleados. Se desea:
a. Cargar los datos de los empleados mediante la función CargaEmpleados. La carga finaliza con un empleado con DNI 99.
b. Generar un vector con la cantidad de empleados en cada sector mediante la función CuentaPorSector y mostrarlo en forma de
listado.
c. Determinar el importe total a pagar de sueldos mediante la función TotalAPagar.
d. Volver a mostrar el listado de cantidad de empleados por sector, pero esta vez ordenado de menor a mayor por cantidad de
empleados en cada sector.*/


#include <stdio.h>
#include <locale.h>


int ValidaIntMayorAYFin(int, int);
int ValidaIntEntre(int, int);
float ValidaFloatMayA(float);
int CargaEmpleados(int[], int[], float[], int);
void CuentaPorSector(int[], int[], int);
void MostrarVectorInt(int[], int);
float TotalAPagar(float[], int);
void Ordena2VecBurbMenAMay(int[], int[], int);
void Mostrar2VecLista(int[], int[], int);

int main()
{
    int vecDNI[100], vecSec[100], cant, vecCuenta[5]={0}, vecNumSec[5] = {1, 2, 3, 4, 5};
    float vecSuel[100] = {0}, total;

    setlocale(LC_ALL, "spanish");

    printf("\nA continuación se cargaran los empleados de la empresa: \n");
    cant = CargaEmpleados(vecDNI, vecSec, vecSuel, 100);
    if(cant == 0)
        printf("No se han ingresado empleados.\n");
    else
    {
        CuentaPorSector(vecSec, vecCuenta, cant);
        printf("\nLa cantidad de empleados por sector es la siguiente: \n");
        MostrarVectorInt(vecCuenta, 5);
        total = TotalAPagar(vecSuel, cant);
        printf("\nEl total a pagar de sueldos por la empresa es $ %.2f\n", total);
        Ordena2VecBurbMenAMay(vecCuenta, vecNumSec, 5);
        printf("\nEl total de empleados por sector ordenado de menor a mayor es: \n");
        Mostrar2VecLista(vecCuenta, vecNumSec, 5);

    }
    return 0;
}


/*/////////////////////////////////////////////////FUNCIONES///////////////////////////////////////////////*/

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


int ValidaIntMayorAYFin(int inf, int fin)
{
    int num, band=0;

    do
    {
        if(band)
            printf("El valor proporcionado debe ser mayor a %d o %d para terminar. Intente nuevamente.\n", inf, fin);

        scanf("%d", &num);
        band = 1;
    } while(num<inf && num!=fin);

    return num;
}


float ValidaFloatMayA(float inf)
{
    float num;
    int band = 0;

    do
    {
        if(band)
            printf("El valor proporcionado debe ser mayor a %.0f. Intente nuevamente.\n", inf);

        scanf("%f", &num);
        band = 1;
    } while(num<inf);

    return num;
}




int CargaEmpleados(int vDNI[], int vSec[], float vSuel[], int ce)
{
    int cant = 0, dni, sec;
    float suel;

    printf("Ingrese el DNI del empleado (Mayor a 10.000.000 o 99 para terminar): ");
    dni = ValidaIntMayorAYFin(10000000, 99);
    while(dni!=99 && cant<ce)
    {
        printf("Ingrese el sector del empleado (1 a 5): ");
        sec = ValidaIntEntre(1, 5);
        printf("Ingrese el sueldo del empleado: ");
        suel = ValidaFloatMayA(0);
        vDNI[cant] = dni;
        vSec[cant] = sec;
        vSuel[cant] = suel;
        cant ++;
        printf("Ingrese el DNI del empleado (Mayor a 10.000.000 o 99 para terminar): ");
        dni = ValidaIntMayorAYFin(10000000, 99);
    }
    return cant;
}


void CuentaPorSector(int vecSec[], int vecCuen[], int ceSec)
{
    int i;

    for(i=0; i<ceSec; i++)
        vecCuen[vecSec[i]-1] ++;
}


void MostrarVectorInt(int vec[], int ce)
{
    int i;

    printf("%15s%15s\n", "Sector", "Cantidad");
    for(i=0; i<ce; i++)
        printf("%15d%15d\n", i+1, vec[i]);
}


void Mostrar2VecLista(int vecCuen[], int vecSec[], int ce)
{
    int i;

    printf("%15s%15s\n", "Sector", "Cantidad");
    for(i=0; i<ce; i++)
        printf("%15d%15d\n", vecSec[i], vecCuen[i]);
}


float TotalAPagar(float vecSuel[], int ce)
{
    float total = 0;
    int i;

    for(i=0; i<ce; i++)
        total += vecSuel[i];

    return total;
}


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
