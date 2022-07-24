/*7.1.18 Se procesan los datos de los casi 90 alumnos de un turno de la materia Elementos de Programación. Por cada alumno se
ingresan:
• DNI (entero, mayor que cero y menor que 99.999.999).
• Nota del Parcial 1 (entero, de 0 a 10).
• Nota del Parcial 2 (entero, de 0 a 10).
• Porcentaje de asistencia (real, mayor o igual a cero).
Para finalizar, se ingresa un DNI igual a cero.
Se pide informar con las leyendas aclaratorias y/o títulos:
a. Según los parciales si promocionó, aprobó, reprobó o estuvo ausente (uno o ambos parciales igual a cero).
b. Listar los alumnos que no cumplen con la asistencia (mayor o igual a 75%).
c. Informar cuántos alumnos que promocionaron NO cumplen en la asistencia.
d. Informar los alumnos que sacaron 10 en el parcial 2.
e. Informar los alumnos con menor asistencia (puede haber varios).
f. Al finalizar, informar el promedio total de notas de cada parcial y de asistencia.*/

#include <stdio.h>
#include <locale.h>
#define TAM 90
#define VERDADERO 1
#define FALSO 0

int ValidaIntEntre(int, int);
int BusquedaSecuencialInt(int[], int, int);
float ValidaFloatEntre(float, float);
void Mostrar4VecLista(int[], int[], int[], char[], int);
void MostrarIgualAInt(int[], int[], int, int);
void MostrarMenorAFloat(int[], float[], float, int);
void MostrarIgualAFloat(int[], float[], float, int);
int SumaVecInt(int[], int);
float SumaVecFloat(float[], int);


int main()
{
    int vecDNI[TAM], vecP1[TAM], vecP2[TAM], dni, i=0, j, cont = 0, huboingreso = FALSO, promP1, promP2, pos;
    float vecPorcAs[TAM], menor, promPorc;
    char vecCond[TAM];

    setlocale(LC_ALL, "spanish");

    printf("A continuación se procederá con la carga de alumnos y notas del curso: \n");

    printf("Ingrese el DNI del alumno (entre 1 y 99.999.998 o 0 para terminar): ");
    dni = ValidaIntEntre(0, 99999998);
    while(dni && i<TAM)
    {
        huboingreso = VERDADERO;
        pos = BusquedaSecuencialInt(vecDNI, dni, i);
        if(pos==-1)
        {
            vecDNI[i] = dni;
            printf("Ingrese la nota del primer parcial (1 a 10 o 0 si está ausente): ");
            vecP1[i] = ValidaIntEntre(0, 10);
            printf("Ingrese la nota del segundo parcial (1 a 10 o 0 si está ausente): ");
            vecP2[i] = ValidaIntEntre(0, 10);
            printf("Ingrese el porcentaje de asistencia (real entre 0 y 100): ");
            vecPorcAs[i] = ValidaFloatEntre(0,100);
            if(i)
            {
                if(menor>vecPorcAs[i])
                    menor = vecPorcAs[i];
            }
            else
                menor = vecPorcAs[i];

            i++;
        }
        else
            printf("\nEse DNI ya ha sido cargado. Vuelva a proporcionar número de DNI\n");

        printf("\nIngrese el DNI del alumno (entre 1 y 99.999.998 o 0 para terminar): ");
        dni = ValidaIntEntre(0, 99999998);
    }
    if(huboingreso)
    {
        for(j=0; j<i; j++)
        {
            if(vecP1[j]==0 || vecP2[j]==0)
                vecCond[j] = 'N';
            else
            {
                if(vecP1[j]<4 || vecP2[j]<4)
                    vecCond[j] = 'R';
                else
                {
                    if(vecP1[j]>=7 && vecP2[j]>=7)
                        vecCond[j] = 'P';
                    else
                        vecCond[j] = 'A';
                }
            }
        }
        ////a/////
        printf("A continuación se informa un listado de los alumnos que según los parciales promocionaron, aprobaron, reprobaron o estuvieron ausentes: \n");
        printf("%5s%20s%15s%28s\n", "DNI", "Nota Parcial 1", "Nota Parcial 2", "Condición");
        Mostrar4VecLista(vecDNI, vecP1, vecP2, vecCond, i);
        ////b////
        printf("\nLos alumnos que no cumplen con la asistencia (menos del 75%% de asistencia) son: \n");
        printf("%10s%25s\n", "DNI", "Porcentaje de asistencia");
        MostrarMenorAFloat(vecDNI, vecPorcAs, 75, i);
        ////c////
        for(j=0; j<i; j++)
            if(vecCond[j]=='P' && vecPorcAs[j]<75)
                cont ++;
        printf("\nHay %d alumnos que promocionaron y NO cumplen en la asistencia (75%% de asistencia mínima): \n", cont);
        ////d////
        printf("\nLos alumnos que sacaron 10 en el segundo parcial son: \n");
        MostrarIgualAInt(vecDNI, vecP2, 10, i);
        ////e////
        printf("\nEl porcentaje menor de asistencia es %.2f%% y los alumnos que tienen dicho porcentaje son: \n", menor);
        MostrarIgualAFloat(vecDNI, vecPorcAs, menor, i);
        ////f////
        promP1 = SumaVecInt(vecP1, i) / i;
        promP2 = SumaVecInt(vecP2, i) / i;
        promPorc = SumaVecFloat(vecPorcAs, i) / i;
        printf("\nEl promedio de notas del primer parcial es %d\nEl promedio de notas del segundo parcial es %d\nEl promedio de porcentaje de asistencias es %.2f\n", promP1, promP2, promPorc);
    }
    else
        printf("\nNo se han registrado ingresos.\n");

    return 0;
}

/*//////////////////////////////////////////////////////FUNCIONES//////////////////////////////////////////////*/

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

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////*/


int BusquedaSecuencialInt(int v[], int num, int ce)
{
    int i = 0, pos = -1;

    while(i<ce && pos == -1)
    {
        if(v[i]== num)
            pos = i;
        else
            i++;
    }
    return pos;
}

/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

float ValidaFloatEntre(float inf, float sup)
{
    int band=0;
    float num;

    do
    {
        if(band)
            printf("El valor proporcionado debe ser un entero entre %d y %d. Intente nuevamente.\n", inf, sup);

        scanf("%f", &num);
        band = 1;
    } while(num<inf || num>sup);

    return num;
}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void Mostrar4VecLista(int v1[], int v2[], int v3[], char v5[], int ce)
{
    int i;

    for(i=0; i<ce; i++)
    {
        printf("%9d%9d%15d", v1[i], v2[i], v3[i]);
        if(v5[i]=='N')
            printf("%70s\n", "Ausente(alguno de los parciales ausente)");
        if(v5[i]=='A')
            printf("%70s\n", "Aprobado(ambos parciales más de 4 y alguno menos de 7)");
        if(v5[i]=='R')
            printf("%70s\n", "Reprobado(alguno de los parciales menos de 4 y ningún 0)");
        if(v5[i]=='P')
            printf("%70s\n", "Promocionado(ambos parciales más de 7)");
    }
}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void MostrarIgualAInt(int v1[], int v2[], int num, int ce)
{
    int i;

    for(i=0; i<ce; i++)
    {
        if(v2[i] == num)
            printf("%d\n", v1[i]);
    }
}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void MostrarIgualAFloat(int v1[], float v2[], float num, int ce)
{
    int i;

    for(i=0; i<ce; i++)
    {
        if(v2[i] == num)
            printf("%d\n", v1[i]);
    }
}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void MostrarMenorAFloat(int v1[], float v2[], float num, int ce)
{
    int i;

    for(i=0; i<ce; i++)
    {
        if(v2[i] < num)
            printf("%10d%25.2f\n", v1[i], v2[i]);
    }
}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void MostrarMayorA(int v1[], int v2[], int num, int ce)
{
    int i;

    for(i=0; i<ce; i++)
    {
        if(v2[i] > num)
            printf("%d\n", v1[i]);
    }
}

/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int SumaVecInt(int v[], int ce)
{
    int i, suma = 0;

    for(i=0; i<ce; i++)
        suma += v[i];

    return suma;
}

/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

float SumaVecFloat(float v[], int ce)
{
    float suma = 0;
    int i;

    for(i=0; i<ce; i++)
        suma += v[i];

    return suma;
}

/*//////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
