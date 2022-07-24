/*7.1.15 La empresa TODOMODA desea controlar las ventas de sus productos. La empresa vende 200 productos diferentes. La
información de los productos se ingresa por teclado. Cada producto contiene:
• Código de producto (int, 301 y 900).
• Unidades en stock. (int, mayor o igual a 0).
Luego ingresar la información de las ventas diarias, también por teclado. Los datos ingresados son (este lote de datos finaliza
con un código de producto igual a 0):
• Código de producto (int, 301 y 900).
• Cantidad de unidades vendidas (int, 1 y 150).
Se piden procesar las ventas diarias y luego determinar:
a. Informar el stock de cada código de producto, indicando el código de producto y el stock del mismo.
b. Informar el código del producto que tiene el stock más alto.
c. Informar el código del producto de aquellos que hayan superado el stock promedio.
FUNCIONES:
I. Para controlar los datos ingresados por teclado (la función debe controlar un solo dato).
II. Para informar el punto a).*/

#include <stdio.h>
#include <locale.h>
#define TAM 5

int ValidaIntEntre(int, int);
int ValidaIntMayorA(int);
int ValidaIntEntreYFin(int, int, int);
void Mostrar2VecLista(int[], int[], int);
int BusquedaSecuencial(int[], int, int);
int HallarMayorInt(int[], int);
void MostrarIgualAInt(int[], int[], int, int);
int SumaVecInt(int[], int);
void MostrarMayorA(int[], int[], int, int);


int main()
{
    int vecP[TAM], vecStock[TAM] = {0}, codP, stock, i=0, coP, cant, mayor, prom, suma, pos, stockInval, nuevoStock;

    setlocale(LC_ALL, "spanish");

    printf("A continuación se procederá con la carga de los productos: \n");
    while(i<TAM)
    {
        printf("\nIngrese el código de producto (entre 301 y 900): ");
        codP = ValidaIntEntre(301, 900);
        pos = BusquedaSecuencial(vecP, codP, i);
        if(pos!=-1)
            printf("\nEl código proporcionado ya ha sido ingresado, no se permiten duplicados, por favor vuelva a ingresar el código: ");
        else
        {
            printf("\nIngrese el stock del producto (mayor a 0): ");
            vecStock[i] = ValidaIntMayorA(0);
            vecP[i] = codP;
            i++;
        }
    }
    printf("\nLISTADO DE PRODUCTOS Y STOCK: \n%Código\tStock\n");
    Mostrar2VecLista(vecP, vecStock, TAM);

    printf("\n\nA continuación se procederá con la carga de las ventas: \n");
    printf("Ingrese el código de producto (entre 301 y 900): ");
    coP = ValidaIntEntreYFin(301, 900, 0);
    while(coP)
    {
        pos = BusquedaSecuencial(vecP, coP, TAM);
        if(pos==-1)
            printf("\nEl código de producto ingresado no está cargado en la base de datos. Vuelva a intentarlo: \n");
        else
        {
            printf("\nIngrese la cantidad vendida: ");
            stockInval = 0;
            do
            {
                if(stockInval)
                    printf("¡El stock no puede ser negativo!. Vuelva a ingresar la cantidad vendida.\n");
                cant = ValidaIntEntre(1, 150);
                nuevoStock = vecStock[pos] - cant;
                stockInval = 1;
            } while (nuevoStock<0);
            vecStock[pos] -= cant;
        }
        printf("Ingrese el código de producto (entre 301 y 900): ");
        coP = ValidaIntEntreYFin(301, 900, 0);
    }

    printf("\nLISTADO DE PRODUCTOS Y STOCK: \n%Código\tStock\n");                       //////a//////
    Mostrar2VecLista(vecP, vecStock, TAM);

    if(i)
    {
        mayor = HallarMayorInt(vecStock, TAM);                                          //////b//////
        printf("\nEl stock más alto es %d y los códigos que tienen dicho stock son:  \n", mayor);
        MostrarIgualAInt(vecP, vecStock, mayor, TAM);

        suma = SumaVecInt(vecStock, TAM);                                               //////c/////
        prom = suma / i;
        printf("\nEl stock promedio es %d y los códigos de los productos que lo superan son: \n", prom);
        MostrarMayorA(vecP, vecStock, prom, TAM);
    }
    else
        printf("\nNo se ha ingresado ninguna venta.\n");

    return 0;
}

/*/////////////////////////////////////////////FUNCIONES////////////////////////////////////////////////*/


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

/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

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

int SumaVecInt(int v[], int ce)
{
    int i, suma = 0;

    for(i=0; i<ce; i++)
        suma += v[i];

    return suma;
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

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void Mostrar2VecLista(int v1[], int v2[], int ce)
{
    int i;

    for(i=0; i<ce; i++)
        printf("%d\t%d\n", v1[i], v2[i]);
}
