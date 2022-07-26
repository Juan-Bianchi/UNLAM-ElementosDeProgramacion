/*7.1.5 Una empresa debe registrar los pedidos recibidos de cada uno de sus 10 productos a lo largo del día. Por cada pedido se recibe:
• Código de producto (de 1 a 10)
• Cantidad de unidades solicitadas
Se puede recibir más de un pedido por producto.
La carga finaliza cuando se ingresa un producto con código igual a cero.
Al finalizar se debe emitir un listado con código y cantidad de unidades solicitadas de cada producto.*/

#include<stdio.h>
#include<string.h>


void mostrarListado(int* vec, const int cantElem);
void cargaVentas(int* vec, const int cod, const int cantProd);
int estaDentroDelRango(const int elem, const int inf, const int sup);
int validaIntEntre(const int inf, const int sup);
int validaIntMayA(const int inf);


int main()
{
    int vec[10]={0}, cod, cant;

    printf("Ingrese el codigo de producto (1 a 10 o 0 para terminar): ");
    cod = validaIntEntre(0, 10);
    while(cod!=0)
    {
        printf("Ingrese la cantidad pedida: ");
        cant = validaIntMayA(0);
        cargaVentas(vec, cod, cant);
        printf("Ingrese el codigo de producto (1 a 10 o 0 para terminar): ");
        cod = validaIntEntre(0, 10);
    }
    printf("El listado de las ventas es el siguiente: \n");

    mostrarListado(vec, 10);

    return 0;
}


void mostrarListado(int* vec, const int cantElem)
{
    int* pVec, cod = 1;

    printf("%15s%15s\n", "Codigo", "Cantidad");
    for(pVec=vec; pVec<=vec+cantElem-1; pVec++)
    {
        printf("%15d%15d\n", cod, *pVec);
        cod ++;
    }
}



void cargaVentas(int* vec, const int cod, const int cantProd)
{
    *(vec+cod-1) += cantProd;
}


int estaDentroDelRango(const int elem, const int inf, const int sup)
{
    return elem>=inf && elem<=sup;
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


int validaIntMayA(const int inf)
{
    int num;

    do
    {
        fflush(stdin);
        scanf("%d", &num);
        fflush(stdin);
        if(num<=inf)
            printf("El numero ingresado no es valido, el mismo debe ser mayor a %d. Vuelva a ingresar: ", inf);
    } while(num<=inf);

    return num;
}
