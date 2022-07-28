/*7.1.9 Se debe ingresar los códigos de 15 productos de una empresa (números de 3 dígitos). Luego se ingresan las ventas realizadas durante el
día. Por cada venta se ingresa código de vendedor, código de artículo y cantidad.
Los vendedores son 5 y están codificados en forma correlativa de 1001 a 1005. Se puede recibir más de una venta de un mismo vendedor y artículo.
El ingreso de datos finaliza con código de vendedor igual a 0. Se desea:
a. Mostrar un listado ordenado de mayor a menor por cantidad de unidades vendidas.
CANT UNIDADES   CÓDIGO
   XXX           XXX
   XXX           XXX
b. Indicar el/los vendedores que realizaron menor cantidad de ventas (no de unidades).*/

#include<stdio.h>
#include<string.h>

#define TAM1 15
#define TAM2 5

int estaDentroDelRango(const int num, const int inf, const int sup);
int validaIntEntre(const int inf, const int sup);
int validaIntEntreYConFin(const int inf, const int sup, const int condF);
int validaIntMayA(const int inf);
int buscaElementoEnVector(const int* vecProd, const int elem, const int cantElem);
void cargaProductosSinRep(int* vecProd, const int cantElem);
void cargaVentas(int* vecProd, int* vecVend, int* vecCant, int* vecCantVent, const int cantElem1, const int cantElem2);
void ordenaBurbujeoAscend(int* vecProd, int* vecCant, const int cantElem);
void mostrarListado(int* vecProd, int* vecCant, const int cantElem);
int buscarMenor(const int* vecCantVent, const int cantElem);
void mostrarMinimos(const int* vecCantVent, const int* vecVend, const int cantElem, const int men);


int main()
{
    int vecCantVent[TAM2]={0}, vecProd[TAM1], vecVend[TAM2]={1001, 1002, 1003, 1004, 1005}, vecCant[TAM1]={0}, menor;


    printf("A continuacion se procedera con la carga de los codigos de los productos: \n");
    cargaProductosSinRep(vecProd, 15);

    printf("Ahora se ingresaran las ventas de los productos: \n");
    cargaVentas(vecProd, vecVend, vecCant, vecCantVent, TAM1, TAM2);

    ordenaBurbujeoAscend(vecProd, vecCant, TAM1);
    printf("El listado ordenado de mayor a menor por cantidad de unidades vendidas es: \n");
    mostrarListado(vecProd, vecCant, TAM1);

    menor = buscarMenor(vecCantVent, TAM2);
    printf("La menor cantidad vendidad fue %d y estos fueron los vendedores que vendieron esa cantidad: \n", menor);
    mostrarMinimos(vecCantVent, vecVend, TAM2, menor);

    return 0;
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


int validaIntEntreYConFin(const int inf, const int sup, const int condF);


int validaIntMayA(const int inf)
{
    int num;

    do
    {
        fflush(stdin);
        scanf("%d", &num);
        fflush(stdin);
        if(num<=inf)
            printf("EL numero ingresado no es valido. El mismo debe ser mayor a %d. Vuelva a ingresar: ", inf);
    } while(num<=inf);

    return num;
}


int buscaElementoEnVector(const int* vec, const int elem, const int cantElem)
{
    const int* pVec = vec;
    int pos = 0;

    while(pVec<=vec+cantElem-1 && *pVec != elem)
    {
        pVec ++;
        pos ++;
    }

    return (*pVec == elem)? pos: -1;
}


void cargaProductosSinRep(int* vecProd, const int cantElem)
{
    int cod, cont = 0;
    int* pVecProd = vecProd;


    while(pVecProd<=vecProd+cantElem-1)
    {
        printf("Ingrese el codigo de producto (entre 100 y 999, no puede haber duplicados): ");
        cod = validaIntEntre(100, 999);
        if(buscaElementoEnVector(vecProd, cod, cont)==-1)
        {
            *pVecProd = cod;
            pVecProd ++;
            cont ++;
        }
        else
            printf("El codigo ingresado ya ha sido ingresado. No es valido.\n");
    }
}


void cargaVentas(int* vecProd, int* vecVend, int* vecCant, int* vecCantVent, const int cantElem1, const int cantElem2)
{
    int cod, prod, posVend, posProd;

    printf("Ingrese el codigo de vendedor (1001 a 1005 o 0 para terminar): ");
    fflush(stdin);
    scanf("%d", &cod);
    fflush(stdin);
    while(cod!=0)
    {
        posVend = buscaElementoEnVector(vecVend, cod, cantElem2);
        if(posVend!=-1)
        {
            printf("Ingrese el codigo de producto: ");
            prod = validaIntEntre(100, 999);
            posProd = buscaElementoEnVector(vecProd, prod, cantElem1);
            if(posProd!=-1)
            {
                printf("Ingrese la cantidad vendida: ");
                *(vecCant+posProd) = validaIntMayA(0);
                *(vecCantVent+posVend) += *(vecCant+posProd);
            }
            else
                printf("El codigo de producto no es correcto. Se volver a a ingresar toda la operacion.\n");
        }
        else
            printf("El codigo de vendedor no es correcto. Se volver a ingresar toda la operacion.\n");

        printf("Ingrese el codigo de vendedor (1001 a 1005 o 0 para terminar): ");
        fflush(stdin);
        scanf("%d", &cod);
        fflush(stdin);
    }
}



void ordenaBurbujeoAscend(int* vecProd, int* vecCant, const int cantElem)
{
    int aux, * cota = vecCant + cantElem -  2, * desordenado, * pVecCant, * pVecProd;

    do
    {
        desordenado = vecCant;
        pVecProd = vecProd;

        for(pVecCant = vecCant; pVecCant<cota; pVecCant++)
        {
            if(*pVecCant>*(pVecCant+1))
            {
                aux = *pVecCant;
                *pVecCant = *(pVecCant+1);
                *(pVecCant+1) = aux;

                aux = *pVecProd;
                *pVecProd = *(pVecProd+1);
                *(pVecProd+1) = aux;

                desordenado = pVecCant;
            }
            pVecProd ++;
        }
        cota = desordenado;
    } while (desordenado!=vecCant);
}



void mostrarListado(int* vecProd, int* vecCant, const int cantElem)
{
    int* pVecProd, * pVecCant = vecCant;

    printf("%-15s%10s\n", "CANT UNIDADES", "CODIGOS");

    for(pVecProd = vecProd; pVecProd<=vecProd+cantElem-1; pVecProd ++)
    {
        printf("%-15d%10d\n", *pVecCant, *pVecProd);
        pVecCant ++;
    }
}


int buscarMenor(const int* vec, const int cantElem)
{
    const int* pVec = vec;
    int menor = *pVec;

    for(pVec = vec+1; pVec<=vec+cantElem-1; pVec++)
    {
        if(menor>*pVec)
            menor = *pVec;
    }
    return menor;
}


void mostrarMinimos(const int* vecCantVent, const int* vecVend, const int cantElem, const int menor)
{
    const int* pVec;
    int pos = 0;

    for(pVec=vecCantVent; pVec<=vecCantVent+cantElem-1; pVec++)
    {
        if(*pVec==menor)
            printf("%d\n", *(vecVend+pos));
        pos++;
    }
}
