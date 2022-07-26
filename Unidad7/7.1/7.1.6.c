/*7.1.6 Ídem ejercicio anterior, pero con código de productos no correlativos de 4 dígitos. Los códigos deben solicitarse al iniciar el programa
mediante la función IngresaCodigos. Luego de la carga determinar:
a. El / los productos del cual se solicitaron mayor cantidad de unidades.
b. El / los productos del cual se solicitaron menos cantidad de unidades.*/


#include<stdio.h>
#include<string.h>


void mostrarListado(int* vec, const int cantElem);
void mostraVentas(const int* vecCod, const int* vecCant, const int cantElem);
void cargaCodigos(int* vec, const int cantElem, const int inf, const int sup);
int buscarEnVector(int* vec, const int cantElem, const int elem);
void buscarMaximoYMinimo(const int* vecCod, const int* vecCant, const int cantElem, int* max, int* min, int* posMin, int* posMax);
void cargaVentas(int* vec, const int pos, const int cantProd);
int estaDentroDelRango(const int elem, const int inf, const int sup);
int validaIntEntre(const int inf, const int sup);
int validaIntMayA(const int inf);


int main()
{
    int vecCod[10]={0}, vecCant[10]={0}, pos, cant, cod, menor, mayor, menorPos, mayorPos;

    printf("Se procedera al ingreso de los codigos: ");
    cargaCodigos(vecCod, 10, 1000, 9999);
    mostrarListado(vecCod, 10);

    printf("A continuacion se procedera a la carga de las ventas: ");
    printf("Ingrese el codigo de producto (0 para terminar): ");
    fflush(stdin);
    scanf("%d", &cod);
    fflush(stdin);
    while(cod!=0)
    {
        pos = buscarEnVector(vecCod, 10, cod);
        if(pos==-1)
            printf("El codigo ingresado no es valido. Vuelva a ingresar.\n");
        else
        {
            printf("Ingrese la cantidad pedida: ");
            cant = validaIntMayA(0);
            cargaVentas(vecCant, pos, cant);
        }
        printf("Ingrese el codigo de producto (0 para terminar): ");
        fflush(stdin);
        scanf("%d", &cod);
        fflush(stdin);
    }
    buscarMaximoYMinimo(vecCod, vecCant, 10, &mayor, &menor, &menorPos, &mayorPos);
    printf("El listado de las ventas es el siguiente: \n");
    mostraVentas(vecCod, vecCant, 10);

    printf("La menor cantidad vendida es %d y el codigo de articulo es %d\n", menor, menorPos);
    printf("La mayor cantidad vendida es %d y el codigo de articulo es %d\n", mayor, mayorPos);

    return 0;
}


void mostrarListado(int* vec, const int cantElem)
{
    int* pVec, cod = 1;

    printf("Codigo\n");
    for(pVec=vec; pVec<=vec+cantElem-1; pVec++)
        printf("%d\n", *pVec);
}



void cargaVentas(int* vec, const int pos, const int cantProd)
{
    *(vec+pos) += cantProd;
}

void cargaCodigos(int* vec, const int cantElem, const int inf, const int sup)
{
    int* pVec;

    for(pVec=vec; pVec<=vec+cantElem-1; pVec++)
    {
        printf("Ingrese el codigo de articulo (entre 1000 y 9999): ");
        *pVec = validaIntEntre(inf, sup);
    }
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

int buscarEnVector(int* vec, const int cantElem, const int elem)
{
    int* pVec = vec, pos = 0;

    while(elem != *pVec && pVec<= vec + cantElem-1)
    {
        pVec ++;
        pos ++;
    }
    if(pVec == vec + cantElem)
        return -1;

    return pos;
}

void mostraVentas(const int* vecCod, const int* vecCant, const int cantElem)
{
    const int* pVecCod, * pVecCant = vecCant;

    printf("%10s%10s\n\n", "Codigo", "Cantidad");
    for(pVecCod = vecCod; pVecCod<=vecCod + cantElem -1; pVecCod++)
    {
        printf("%10d%10d\n", *pVecCod, *pVecCant);
        pVecCant ++;
    }
}

void buscarMaximoYMinimo(const int* vecCod, const int* vecCant, const int cantElem, int* max, int* min, int* posMin, int* posMax)
{
    const int* pVecCod, * pVecCant = vecCant;

    *max = *vecCant;
    *posMax = *vecCod;
    *min = *vecCant;
    *posMin = *vecCod;

    for(pVecCod = vecCod; pVecCod <= vecCod + cantElem; pVecCod ++)
    {
        if(*pVecCant>*max)
        {
            *max = *pVecCant;
            *posMax = *pVecCod;
        }
        if(*pVecCant<*min)
        {
            *min = *pVecCant;
            *posMin = *pVecCod;
        }
        pVecCant ++;
    }
}
