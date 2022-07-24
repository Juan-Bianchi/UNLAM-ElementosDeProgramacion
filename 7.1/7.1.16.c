/*7.1.16 Una empresa textil desea realizar un informe sobre los sueldos de cada sección para lo cual dispone de los siguientes
datos:
• La fecha del día del proceso, que debe ser ingresada al comienzo del programa y controlarse que sea válida. De no serlo,
reingresarla hasta que lo sea.
• Los sueldos de cada empleado:
i. Legajo (entero, mayor a cero).
ii. Sección (carácter, desde ‘A’ hasta ‘H’).
iii. Sueldo (real, mayor a cero).
Los datos de cada empleado deben validarse y en caso de que alguno sea incorrecto, debe ignorarse los tres y reingresarse
nuevamente. El fin de datos es cuando aparece un legajo igual a cero. Se pide:
a. Emitir un informe que indique por sección, el total de sueldos de la misma, ordenado en forma descendente por total de
sueldos:
    Sueldos al: XX/XX/XXXX
Sección     Total de sueldos por sección
  H                   XXXXX,XX
  B                   XXXXX,XX
  …                   …………
TOTAL SUELDOS        XXXXXXX,XX
b. El legajo del empleado con mayor sueldo consignando legajo, sección y sueldo.*/

#include <stdio.h>
#include <ctype.h>
#define TAM 8
#include <locale.h>
#define VERDADERO 1
#define FALSO 0

int EsBisiesto(int);
int CantidadDiasDelMes(int, int);
int EsFechaValida(int, int, int);
int EsValidoIntMayorA(int, int);
int EsValidoCharEntre(char, char, char);
int EsValidoFloatMayA(float, float);
int BusquedaSecuencialChar(char[], char, int);
void Ordena2VecBurbMayAMen(char[], float[], int);
float SumaDeVectorFloat(float[], int);
void Mostrar2VecLista(char[], float[], int);


int main()
{
    int dia, mes, anio, hayingreso, leg, legMax, fechaVal, legVal, secVal, suelVal, band, pos;
    float vecSumaSec[TAM], sueldo, suelMax, total;
    char seccion, secMax, vecSec[TAM] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

    setlocale(LC_ALL, "spanish");

    printf("Ingrese la fecha actual (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &dia, &mes, &anio);
    fechaVal = EsFechaValida(dia, mes, anio);
    while(!fechaVal)
    {
        printf("\nLa fecha ingresada no es válida. Vuelva a ingresarla\n");
        printf("Ingrese la fecha actual (dd/mm/aa): ");
        scanf("%d/%d/%d", &dia, &mes, &anio);
        fechaVal = EsFechaValida(dia, mes, anio);
    }

    printf("\nA continuación se procederá al ingreso de los sueldos de los empleados: \n");
    do
    {
        printf("\nIngrese el número de legajo del empleado (0 para terminar): ");
        fflush(stdin);
        scanf("%d", &leg);
        printf("Ingrese la sección en la que se desempeña el empleado (A a H): ");
        fflush(stdin);
        scanf("%c", &seccion);
        seccion = toupper(seccion);
        printf("Ingrese el sueldo del empleado (mayor a 0): ");
        fflush(stdin);
        scanf("%f", &sueldo);
        legVal = EsValidoIntMayorA(leg, -1);
        secVal = EsValidoCharEntre(seccion, 'A', 'H');
        suelVal = EsValidoFloatMayA(sueldo, 0);
        if(!legVal)
            printf("El legajo proporcionado no es válido. Debe volver a ingresarlo.\n");
        if(!secVal)
            printf("El sector proporcionado no es válido. Debe volver a ingresarlo.\n");
        if(!suelVal)
            printf("El sueldo proporcionado no es válido. Debe volver a ingresarlo.\n");
    } while(!legVal || !secVal || !suelVal);
    suelMax = sueldo;
    secMax = seccion;
    legMax = leg;

    while(leg)
    {
       hayingreso = 1;
       if(sueldo>suelMax)
       {
           suelMax = sueldo;
           secMax = seccion;
           legMax = leg;
       }
       pos = BusquedaSecuencialChar(vecSec, seccion, TAM);
       vecSumaSec[pos] += sueldo;
       do
        {
            printf("\nIngrese el número de legajo del empleado (0 para terminar): ");
            fflush(stdin);
            scanf("%d", &leg);
            printf("Ingrese la sección en la que se desempeña el empleado (A a H): ");
            fflush(stdin);
            scanf("%c", &seccion);
            seccion = toupper(seccion);
            printf("Ingrese el sueldo del empleado (mayor a 0): ");
            fflush(stdin);
            scanf("%f", &sueldo);
            legVal = EsValidoIntMayorA(leg, -1);
            secVal = EsValidoCharEntre(seccion, 'A', 'H');
            suelVal = EsValidoFloatMayA(sueldo, 0);
            if(!legVal)
                printf("El legajo proporcionado no es válido. Debe volver a ingresarlo.\n");
            if(!secVal)
                printf("El sector proporcionado no es válido. Debe volver a ingresarlo.\n");
            if(!suelVal)
                printf("El sueldo proporcionado no es válido. Debe volver a ingresarlo.\n");
        } while(!legVal || !secVal || !suelVal);
    }

if(hayingreso)
{
    printf("El informe que indica por sección, el total de sueldos de la misma, ordenado en forma descendente por total de sueldos es:");
    printf("\n%7s%34s", "Sección", "Total de sueldos por sección\n");
    Ordena2VecBurbMayAMen(vecSec, vecSumaSec, TAM);                                         /////a/////
    Mostrar2VecLista(vecSec, vecSumaSec, TAM);
    total = SumaDeVectorFloat(vecSumaSec, TAM);
    printf("%13s         $%9.2f\n", "TOTAL SUELDOS", total);
                                                                                            /////b/////
    printf("\nEl empleado con legajo %d de la sección %c tiene el sueldo máximo de la empresa, y el mismo es $%.2f.\n", legMax, secMax, suelMax);
}
else
    printf("\nNo se registraron ingresos.\n");

return 0;
}

/*//////////////////////////////////////////////////////FUNCIONES//////////////////////////////////////////////*/

int EsBisiesto(int anio)
{
    return (anio % 400 == 0 || (anio % 4 == 0 && anio % 100 != 0));
}

/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int CantidadDiasDelMes(int mes, int anio)
{
    int Esbis;
    static int vecd[12] ={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    Esbis = EsBisiesto(anio);
    if(Esbis)
        return 29;

    return vecd[mes-1];
}

/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int EsFechaValida(int dia, int mes, int anio)
{
    int cantDias;

    cantDias = CantidadDiasDelMes(mes, anio);
    return (anio>=1582 && mes>=1 && mes<=12 && dia>=1 && dia<=cantDias)? VERDADERO: FALSO;
}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int EsValidoIntMayorA(int num, int cond)
{
    return (num>=cond)? VERDADERO: FALSO;
}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int EsValidoCharEntre(char letra, char inf, char sup)
{
    return (letra>=inf && letra<=sup)? VERDADERO: FALSO;
}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int EsValidoFloatMayA(float num, float cond)
{
   return (num>=cond)? VERDADERO: FALSO;
}

/*//////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int BusquedaSecuencialChar(char v[], char letra, int ce)
{
    int i = 0, pos = -1;

    while(i<ce && pos == -1)
    {
        if(v[i]==letra)
            pos = i;
        else
            i++;
    }
    return pos;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void Ordena2VecBurbMayAMen(char v1[], float v2[], int ce)
{
    float auxS;
    char auxL;
    int i, j = 0, huboCambio = 1;


    do
    {
        huboCambio = 0;
        for(i=1; i<ce-j; i++)
        {
            if(v2[i-1]<v2[i])
            {
                auxS = v2[i];
                v2[i] = v2[i-1];
                v2[i-1] = auxS;

                auxL = v1[i];
                v1[i] = v1[i-1];
                v1[i-1] = auxL;

                huboCambio = 1;
            }
        }
        j++;
    } while(huboCambio);
}

/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

float SumaDeVectorFloat(float v[], int ce)
{
    float suma = 0;
    int i;

    for(i=0; i<ce; i++)
        suma += v[i];

    return suma;
}

/*//////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void Mostrar2VecLista(char v1[], float v2[], int ce)
{
    int i;

    for(i=0; i<ce; i++)
        printf("%3c            $%13.2f\n", v1[i], v2[i]);
}


