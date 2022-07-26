/*7.1.7 Se ingresan DNI, código de sector (1 a 5) y sueldo de los empleados de una empresa. Se sabe que como máximo la empresa tiene 100 empleados.
Se desea:
a. Cargar los datos de los empleados mediante la función CargaEmpleados. La carga finaliza con un empleado con DNI 99.
b. Generar un vector con la cantidad de empleados en cada sector mediante la función CuentaPorSector y mostrarlo en forma de listado.
c. Determinar el importe total a pagar de sueldos mediante la función TotalAPagar.
d. Volver a mostrar el listado de cantidad de empleados por sector, pero esta vez ordenado de menor a mayor por cantidad de empleados en cada
sector.*/

#include<stdio.h>
#include<string.h>
#define TAM 100


int estaDentroDelRango(const int num, const int inf, const int sup);
int validaIntEntre(const int inf, const int sup);
int validaIntMayAYCondFin(const int inf, const int condF);
float validaFloatMayA(const float inf);
int cargaEmpleados(int* vecDni, int* vecSec, float* vecSuel, const int cantElem);
void cuentaPorSector(int* vecCuentPorSect, const int* vecSec, const int cantSec, const int cantEmp);
void mostrarCuentaPorSector(const int* vecCuentPorSect, const int* vecOrden, const int cantElem);
float totalAPagar(float* vecSuel, const int cantElem);
void ordenaVectBurbujeoAs(int* vecCuentPorSect, int* vecOrden, const int cantElem);




int main()
{
    int vecDni[TAM]={0}, vecSec[TAM]={0}, cantEmp, vecCuentaPorSector[5]={0}, vecOrden[5]={1,2,3,4,5};
    float vecSuel[TAM]={0}, total;

    printf("A continuacion se procedera con la carga de los empleados: \n\n");
    cantEmp = cargaEmpleados(vecDni, vecSec, vecSuel, TAM);
    if(cantEmp)
    {
        cuentaPorSector(vecCuentaPorSector, vecSec, 5, cantEmp);
        printf("El listado de la cantidad de empleados por sector es: \n");
        mostrarCuentaPorSector(vecCuentaPorSector, vecOrden, 5);
        total = totalAPagar(vecSuel, cantEmp);
        printf("\nEl importe total de sueldos es $%.2f\n\n", total);
        ordenaVectBurbujeoAs(vecCuentaPorSector, vecOrden, 5);
        printf("El listado de cuenta por sector ordenado de menor a mayor por cantidad de empleados es: \n");
        mostrarCuentaPorSector(vecCuentaPorSector, vecOrden, 5);
    }
    else
        printf("No se han ingresado empleados.\n");

    return 0;
}


int validaIntMayAYCondFin(const int inf, const int condF)
{
    int num;

    do
    {
        fflush(stdin);
        scanf("%d", &num);
        fflush(stdin);
        if(num<=inf && num!=condF)
            printf("El numero ingresado no es valido. El mismo debe ser mayor a %d o %d para terminar. Vuelva a ingresar: ", inf, condF);
    } while(num<=inf && num!=condF);
}

int cargaEmpleados(int* vecDni, int* vecSec, float* vecSuel, const int cantElem)
{
    int dni, contEmp = 0;
    int* pVecDni = vecDni, * pVecSec = vecSec;
    float* pVecSuel = vecSuel;

    printf("Ingrese el DNI del empleado (mayor a 10.000.000 o 99 para terminar): ");
    dni = validaIntMayAYCondFin(10000000, 99);
    while(dni!=99 && pVecDni <= vecDni + cantElem -1)
    {
        *pVecDni = dni;
        printf("Ingrese el sector del empleado (1 a 5): ");
        *pVecSec = validaIntEntre(1,5);
        printf("Ingrese el sueldo del empleado (mayor a 0): ");
        *pVecSuel = validaFloatMayA(0);
        pVecDni ++;
        pVecSec ++;
        pVecSuel ++;
        contEmp ++;
        printf("Ingrese el DNI del empleado (mayor a 10.000.000 o 99 para terminar): ");
        dni = validaIntMayAYCondFin(10000000, 99);
    }
    return contEmp;
}


void cuentaPorSector(int* vecCuentPorSect, const int* vecSec, const int cantSec, const int cantEmp)
{
    const int* pVecSec;

    for(pVecSec = vecSec; pVecSec <= vecSec + cantEmp -1 ; pVecSec ++)
    {
        *(vecCuentPorSect+(*pVecSec)-1) += 1;
    }
}


void mostrarCuentaPorSector(const int* vecCuentPorSect, const int* vecOrden, const int cantElem)
{
    const int* pVecCuentPorSect;

    printf("%10s%10s\n", "Sector", "Cantidad");
    for(pVecCuentPorSect = vecCuentPorSect; pVecCuentPorSect<= vecCuentPorSect + cantElem -1; pVecCuentPorSect ++)
    {
        printf("%10d%10d\n", *vecOrden, *pVecCuentPorSect);
        vecOrden ++;
    }
}


float totalAPagar(float* vecSuel, const int cantElem)
{
    float total = 0, * pVecSuel;

    for(pVecSuel = vecSuel; pVecSuel <= vecSuel + cantElem - 1; pVecSuel ++)
        total += *pVecSuel;

    return total;
}



void ordenaVectBurbujeoAs(int* vecCuentPorSect, int* vecOrden, const int cantElem)
{
    int aux;
    int* pVec, * cota = vecCuentPorSect + cantElem -2, * desordenado, *pVecO;

    do
    {
        pVecO = vecOrden;
        desordenado = vecCuentPorSect;
        for(pVec = vecCuentPorSect; pVec < cota; pVec ++)
        {
            if(*pVec > *(pVec + 1))
            {
                aux = *pVec;
                *pVec = *(pVec+1);
                *(pVec+1) = aux;

                aux = *pVecO;
                *pVecO = *(pVecO+1);
                *(pVecO+1) = aux;

                 desordenado = pVec;
            }
            pVecO ++;
        }
        cota = desordenado;
    } while (desordenado != vecCuentPorSect);
}


int estaDentroDelRango(const int num, const int inf, const int sup)
{
    return num>=inf && num<=sup;
}


int validaIntEntre(const int inf, const int sup)
{
    int num, esValido;

    do
    {
        fflush(stdin);
        scanf("%d", &num);
        fflush(stdin);
        esValido = estaDentroDelRango(num, inf, sup);
        if(!esValido)
            printf("El numero ingresado no es valido, el mismo debe estar entre %d y %d. Vuelva a ingresar: ", inf, sup);
    } while(!esValido);

    return num;
}


float validaFloatMayA(const float inf)
{
    float num;

    do
    {
        fflush(stdin);
        scanf("%f", &num);
        fflush(stdin);
        if(num<=inf)
            printf("El numero ingresado no es valido, el mismo debe ser mayor a %.2f. Vuelva a ingresar: ", inf);
    } while(num<=inf);

    return num;
}
