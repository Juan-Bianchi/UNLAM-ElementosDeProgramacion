/*7.1.5 Una empresa debe registrar los pedidos recibidos de cada uno de sus 10 productos a lo largo del día. Por cada pedido se
recibe:
• Código de producto (de 1 a 10)
• Cantidad de unidades solicitadas
Se puede recibir más de un pedido por producto.
La carga finaliza cuando se ingresa un producto con código igual a cero.
Al finalizar se debe emitir un listado con código y cantidad de unidades solicitadas de cada producto.*/


#include <stdio.h>
#include <locale.h>

int ValidaIntEntre(int, int);
int ValidaIntMayorA(int);
void SumadorDeVector(int[], int);
void MostrarVectorComoList(int[], int);


int main()
{
    int vecProd[10] = {0}, cod, band = 0;

    setlocale(LC_ALL, "spanish");
    printf("\nPor favor, proporcione el código de producto (1 a 10 o 0 para terminar): ");
    cod = ValidaIntEntre (0, 10);
    while(cod!=0)
    {
        band = 1;
        SumadorDeVector(vecProd, cod);
        printf("\nPor favor, proporcione el código de producto (1 a 10 o 0 para terminar): ");
        cod = ValidaIntEntre (0, 10);
    }
    if(!band)
        printf("\nNo se han ingresado productos.\n");
    else
    {
        printf("\nSe proporcionará una lista con la cantidad pedida de cada producto.\n");
        MostrarVectorComoList(vecProd, 10);
    }

    return 0;

}

/*////////////////////////////////////////////////////////FUNCIONES///////////////////////////////////////////////////*/


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


void SumadorDeVector(int v[], int pos)
{
    int cant;

    printf("Ingrese la cantidad pedida (mayor a 0): ");
    cant = ValidaIntMayorA(0);
    v[pos-1] += cant;
}


void MostrarVectorComoList(int v[], int ce)
{
    int i;

    printf("\n%15s%10s\n", "Producto", "Cantidad");
    printf("%25s\n", "     --------------------");
    for(i=0; i<ce; i++)
        printf("%15d%10d\n", i+1, v[i]);
}
