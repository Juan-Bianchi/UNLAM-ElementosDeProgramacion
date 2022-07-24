/*7.1.6 Ídem ejercicio anterior, pero con código de productos no correlativos de 4 dígitos. Los códigos deben solicitarse al
iniciar el programa mediante la función IngresaCodigos. Luego de la carga determinar:
a. El / los productos del cual se solicitaron mayor cantidad de unidades.
b. El / los productos del cual se solicitaron menos cantidad de unidades.*/

#include <stdio.h>
#include <locale.h>

int BusquedaSecuencial(int[], int, int);
int ValidaIntMayorA(int);
int ValidaIntEntre(int, int);
void IngresaCodigos(int[], int, int, int);
void SumadorDeVector(int[], int);
void MostrarVectorComoList1(int[], int);
void MostrarVectorComoList(int[], int[], int);
void MostrarMayorInt(int[], int[], int);
void MostrarMenorInt(int[], int[], int);


int main()
{
    int vecProd[10] = {0} , vecCant[10] = {0}, cod, pos, band = 0, mayor, menor;

    setlocale(LC_ALL, "spanish");
    printf("A continuación deberá proporcionar los códigos de 10 productos para procesar la cantidad vendida de los mismos: \n");
    IngresaCodigos(vecProd, 1000, 9999, 10);
    MostrarVectorComoList1(vecProd, 10);
    printf("\nPor favor, proporcione el código de producto (0 para terminar): ");
    scanf("%d", &cod);

    while(cod!=0)
    {
        band = 1;
        pos = BusquedaSecuencial(vecProd, cod, 10);
        if(pos==-1)
            printf("El código proporcionado no ha sido encontrado. Vuelva a intentarlo\n");
        else
        {
            SumadorDeVector(vecCant, pos);
            MostrarVectorComoList1(vecProd, 10);
            printf("\nPor favor, proporcione el código de producto (0 para terminar): ");
            scanf("%d", &cod);
        }
    }
    if(!band)
        printf("\nNo se han ingresado productos.\n");
    else
    {
        printf("\nSe proporcionará una lista con la cantidad pedida de cada producto.\n");
        MostrarVectorComoList(vecProd, vecCant, 10);
        MostrarMayorInt(vecProd, vecCant, 10);
        MostrarMenorInt(vecProd, vecCant, 10);
    }
    return 0;

}

/*////////////////////////////////////////////////////////FUNCIONES///////////////////////////////////////////////////*/


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
    v[pos] += cant;
}


void MostrarVectorComoList(int v1[], int v2[] ,int ce)
{
    int i;

    printf("\n%15s%10s\n", "Producto", "Cantidad");
    printf("%25s\n", "     --------------------");
    for(i=0; i<ce; i++)
        printf("%15d%10d\n", v1[i], v2[i]);
}


void MostrarVectorComoList1(int v[],int ce)
{
    int i;

    printf("\n%19s\n", "Códigos habilidatos:");
    printf("%19s\n", "-------------------");
    for(i=0; i<ce; i++)
        printf("%15d\n", v[i]);
}


void IngresaCodigos(int v[], int inf, int sup, int ce)
{
    int i, cod, pos, band;

    for(i=0; i<ce; i++)
    {
        do
        {
            printf("Ingrese un código de 4 digitos (entre 1000 y 9999): \n");
            cod = ValidaIntEntre(inf, sup);
            pos = BusquedaSecuencial(v, cod, ce);
            if(pos!=-1)
                printf("El código ya se encuentra cargado, vuelva a ingresar un código entre 1000 y 9999 que no se haya ingresado.\n");
        } while (pos!=-1);
        v[i] = cod;
    }
}



void MostrarMayorInt(int vP[], int vC[], int ce)
{
    int i = 0, mayor, codMayor;

    mayor = vC[i];
    codMayor = vP[i];

    for(i=1; i<ce; i++)
        if(mayor<=vC[i])
            mayor = vC[i];

    printf("\nLos códigos de los productos que más cantidad se vendió es: \n");

    for(i=0; i<ce; i++)
        if(vC[i] == mayor)
            printf("\t%d", vP[i]);
}


void MostrarMenorInt(int vP[], int vC[], int ce)
{
    int i = 0, menor, codMenor;

    menor = vC[i];
    codMenor = vP[i];

    for(i=1; i<ce; i++)
        if(menor>=vC[i])
            menor = vC[i];

    printf("\nLos códigos de los productos que menos cantidad se vendió es: \n");

    for(i=0; i<ce; i++)
        if(vC[i] == menor)
            printf("\t%d", vP[i]);
}
