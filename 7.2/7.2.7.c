/*7.2.7 Una empresa desea registrar las ventas realizadas de cada uno de sus 20 productos a lo largo del año. Los productos
están identificados por un código numérico correlativo del 1 al 20. Como primera información se ingresa el precio unitario de
cada uno de los productos. Luego por cada venta se ingresa:
• Código de producto
• Día de venta
• Mes de venta
• Cantidad de unidades vendidas
El ingreso de datos finaliza con un código de producto igual a 0. Informar:
a. El detalle de unidades vendidas de cada producto en cada uno de los 12 meses.
b. El producto con el cual se obtuvo la mayor recaudación.
c. El trimestre de menor recaudación del año.*/


#include <stdio.h>
#include <locale.h>
#define FILAS 20
#define COLUMNAS 12
#define VERDADERO 1
#define FALSO 0

int ValidaIntEntre(int, int);
float ValidaFloatMayorA(float);
void CargaVectorFloat(float[], int);
int EsBisiesto(int);
int CantidadDiasDelMes(int, int);
int EsFechaValida(int, int, int);
int ValidaIntMayorA(int);
void MostrarMatrizInt(int[][COLUMNAS], int, int);
float HallarMayorFloat(float[], int);
float HallarMenorFloat(float[], int);
void MostrarIgualAFloat(float[], float, int);


int main()
{
    int matCantVend[FILAS][COLUMNAS] = {{0}}, codP, dia, mes, anio, cant, codMay, trimMEn, fechaVal, huboCarga = FALSO, i;
    float vecPrU[FILAS], vecVentTot[FILAS] = {0}, vecRecXTrim[4] = {0}, precioU, mayor, menor;

    setlocale(LC_ALL, "spanish");

    printf("Ingrese el año de venta (2000 a 2022): ");
    anio = ValidaIntEntre(2000, 2022);

    printf("\nA continuación se procederá a la carga de los precios unitarios de los productos: \n");
    CargaVectorFloat(vecPrU, FILAS);

    printf("\nAhora procederemos a la carga de las ventas: \n");
    printf("\nIngrese el código de producto (1 a 20 o 0 para terminar): ");
    codP = ValidaIntEntre(0,20);
    while(codP)
    {
        huboCarga = VERDADERO;
        do
        {
            printf("\nIngrese el mes de venta (1 a 12): ");
            scanf("%d", &mes);
            printf("\nIngrese el dia de venta: ");
            scanf("%d", &dia);
            fechaVal = EsFechaValida(dia, mes, anio);
            if(!fechaVal)
                printf("\nLa fecha ingresada es erronea. Vuelva a ingresar.\n");
            else
                printf("\nFecha de venta: %d/%d/%d\n", dia, mes, anio);
        } while (!fechaVal);
        printf("\nIngrese la cantidad de unidades vendidas (mayor a 0): ");
        cant = ValidaIntMayorA(0);
        matCantVend[codP-1][mes-1] += cant;
        vecVentTot[codP-1] = vecPrU[codP-1] * cant;
        if(mes<=2)
                vecRecXTrim[0] += (cant * vecPrU[codP-1]);
            else
            {
                if(i<=5)
                    vecRecXTrim[1] += vecVentTot[i];
                else
                {
                    if(i<=8)
                        vecRecXTrim[2] += vecVentTot[i];
                    else
                        vecRecXTrim[3] += vecVentTot[i];
                }
            }

        printf("\nIngrese el código de producto (1 a 20 o 0 para terminar): ");
        codP = ValidaIntEntre(0,20);
    }
    if(huboCarga)
    {
        ////a////
        printf("\nEl detalle de unidades vendidas de cada producto en cada uno de los 12 meses es: \n");
        printf("CP/MES\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\t11\t12\n");
        printf("----------------------------------------------------------------------------------------------------\n");
        MostrarMatrizInt(matCantVend, FILAS, COLUMNAS);

        ////b////
        mayor= HallarMayorFloat(vecVentTot, FILAS);
        printf("\nLa mayor recaudación fue %.2f y el o los productos que obtuvieron la misma es/son: \n", mayor);
        MostrarIgualAFloat(vecVentTot, mayor, FILAS);

        ////c////
        menor = HallarMenorFloat(vecRecXTrim, 4);
        printf("%f\n", menor);
        printf("\nLa menor recaudación trimestral fue %.2f y se dio en los trimestres: \n", menor);
        MostrarIgualAFloat(vecRecXTrim, menor, 4);
    }
    else
        printf("\nNo se ha realizado ninguna carga.\n");

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

float ValidaFloatMayorA(float inf)
{
    int band=0;
    float num;

    do
    {
        if(band)
            printf("El valor proporcionado debe ser mayor a %d. Intente nuevamente.\n", inf);

        scanf("%f", &num);
        band = 1;
    } while(num<inf);

    return num;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////*/

void CargaVectorFloat(float v[], int ce)
{
    int i;
    float precio;

    for(i=0; i<ce; i++)
    {
        printf("Ingrese el precio unitario del producto %d (mayor a 0): ", i+1);
        precio = ValidaFloatMayorA(0);
        v[i] = precio;
    }
}

/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

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

void MostrarMatrizInt(int m[][COLUMNAS], int cf, int cc)
{
    int i, j;

    for(i=0; i<cf; i++)
    {
        printf("%d\t", i+1);
        for(j=0; j<cc; j++)
            printf("%d\t", m[i][j]);

        printf("\n");
    }
}

/*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

float HallarMayorFloat(float v[], int ce)
{
    int i = 0;
    float mayor;

    mayor = v[i];

    for(i=1; i<ce; i++)
        if(mayor<=v[i])
            mayor = v[i];

    return mayor;
}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

float HallarMenorFloat(float v[], int ce)
{
    int i = 0;
    float menor;

    menor = v[i];

    for(i=1; i<ce; i++)
        if(menor>v[i])
            menor = v[i];

    return menor;
}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void MostrarIgualAFloat(float v[], float num, int ce)
{
    int i;

    for(i=0; i<ce; i++)
    {
        if(v[i] == num)
            printf("%d\n", i+1);
    }
}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
