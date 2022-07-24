/*7.1.17 En un negocio trabajan 12 vendedores. Cada vez que se realiza una venta durante el día, se emite una factura donde se
indican los siguientes datos:
• Número de Factura (entero, mayor que cero).
• Código de vendedor (entero).
• Importe de la venta (real, mayor que cero).
La información termina con un número de Factura igual a cero. Al principio del ingreso, se debe solicitar la fecha del día de
procesamiento. Se pide informar con las leyendas aclaratorias:
• Importe total por facturación por cada vendedor y Cantidad de facturas emitidas por vendedor, ordenando de forma descendente
por importe, con el siguiente formato:
            Venta del Día: XX/XX/XXXX
Nro. de Vendedor    Importe vendido   Cantidad de facturas emitidas
      xx                XXXXX,XX                xx
      xx                XXXXX,XX                xx
       …                  …………                  …
      xx                XXXXX, XX               xx
    TOTAL              XXXXXXX,XX               xxx

Desarrollar 2 programas:
a. Con código de vendedor numérico correlativo de 1 a 12.
b. Con código de vendedor numérico de 3 cifras, no correlativos.*/


#include <stdio.h>
#include <locale.h>
#define TAM 12
#define VERDADERO 1
#define FALSO 0

int EsBisiesto(int);
int CantidadDiasDelMes(int, int);
int EsFechaValida(int, int, int);
int BusquedaSecuencialInt(int[], int, int);
int ValidaIntMayorA(int);
float ValidaFloatMayA(float);
int ValidaIntEntre(int, int);
void Ordena3VecBurbDescFloat(int[], float[], int[], int);
void Mostrar3VecLista(int[], float[], int[], int);
int SumaVecInt(int[], int);
float SumaVecFloat(float[], int);


int main()
{
    int vecContXVend[TAM] = {0}, vecVend[TAM], dia, mes, anio, numF, codV, impV, totalCantFac, fechaVal, pos, i=0;
    float vecSumaXVend[TAM] = {0}, totalImp;

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

    printf("\nA continuación se procederá con la carga de la base de datos de los vendedores: \n");
    for(i=0; i<TAM; i++)
    {
        do
        {
            printf("Ingrese el código del vendedor (100 a 999): ");
            codV = ValidaIntEntre(100, 999);
            pos = BusquedaSecuencialInt(vecVend, codV, i);
            if(pos!=-1)
                printf("¡No se admiten cargas duplicadas! Vuelva a ingresar el código de vendedor.\n");
            else
                vecVend[i] = codV;
        } while (pos!=-1);

    }
    printf("\nA continuación se procederá con la carga de las ventas: \n");
    printf("\nIngrese el número de factura (0 para terminar): ");
    numF = ValidaIntMayorA(-1);
    while(numF)
    {
        printf("Ingrese el código de vendedor (100 a 999): ");
        codV = ValidaIntEntre(100, 999);
        pos = BusquedaSecuencialInt(vecVend, codV, TAM);
        if(pos!=-1)
        {
            printf("Ingrese el importe de venta (mayor a 0): ");
            impV = ValidaFloatMayA(0);
            vecContXVend[pos] ++;
            vecSumaXVend[pos] += impV;
        }
        else
            printf("El código de vendedor %d no se encuentra ingresado. Vuelva a realizar la carga de esta venta desde 0.\n", codV);

        printf("\nIngrese el número de factura (0 para terminar): ");
        numF = ValidaIntMayorA(-1);
    }

    Ordena3VecBurbDescFloat(vecVend, vecSumaXVend, vecContXVend, TAM);
    printf("\nEl importe total por facturación por cada vendedor y Cantidad de facturas emitidas por vendedor, ordenando de forma descendente por importe es: \n");
    printf("Venta del Día: %d/%d/%d\n", dia, mes, anio);
    printf("%16s%19s%32s\n", "Nro. de Vendedor", "Importe vendido", "Cantidad de facturas emitidas");
    Mostrar3VecLista(vecVend, vecSumaXVend, vecContXVend, TAM);
    totalImp = SumaVecFloat(vecSumaXVend, TAM);
    totalCantFac = SumaVecInt(vecContXVend, TAM);
    printf("%16s     $%12.2f%16d\n", "TOTAL", totalImp, totalCantFac);

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

/*///////////////////////////////////////////////////////////////////////////////////////////////////////*/

float ValidaFloatMayA(float inf)
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

void InicializaVecInt(int v[], int ce)
{
    int i;

    for(i=0; i<ce; i++)
    {
        v[i] = i+1;
    }
}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void Ordena3VecBurbDescFloat(int v1[], float v2[], int v3[], int ce)
{
    int i = 0, j, aux1, aux2, huboCambio;
    float aux3;

    do
    {
        huboCambio = 0;
        for(j=1; j<ce-i; j++)
        {
            if(v2[j-1]<v2[j])
            {
                aux3 = v2[j];
                v2[j] = v2[j-1];
                v2[j-1] = aux3;

                aux1 = v1[j];
                v1[j] = v1[j-1];
                v1[j-1] = aux1;

                aux2 = v3[j];
                v3[j] = v3[j-1];
                v3[j-1] = aux2;

                huboCambio = 1;
            }
        }
        i ++;
    } while(huboCambio);
}

/*//////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void Mostrar3VecLista(int v1[], float v2[], int v3[], int ce)
{
    int i;

    for(i=0; i<ce; i++)
        printf("%16d        $%9.2f%16d\n", v1[i], v2[i], v3[i]);
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

/*//////////////////////////////////////////////////////////////////////////////////////////////////////////*/

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
