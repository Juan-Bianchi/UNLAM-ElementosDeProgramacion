/*7.2.6 Se solicita modificar el programa anterior para que además de la butaca y fila ingrese la cantidad de butacas de la
reserva. En dicho caso se deberá verificar si existen a partir de la butaca ingresada la cantidad suficiente de butacas
disponibles consecutivas (tomar siempre hacia la derecha del seleccionado). Si están disponibles reservar todas las butacas, sino
mostrar un mensaje de error.*/

#include <stdio.h>
#include <locale.h>
#define FILAS 12
#define COLUMNAS 9
#define VERDADERO 1
#define FALSO 0

int ValidaIntEntre(int, int);
void InicializaMatrizChar(char[][COLUMNAS], char, int, int);
int BusquedaSecuencialInt(int[], int, int);
void MostrarMatrizChar(char[][COLUMNAS], int, int);
int ContarEnMatrizChar(char[][COLUMNAS], char, int, int);
int HallarMayorInt(int[], int);
void MostrarIgualAInt(int[], int, int);
void OrdenaBurbuja2MayAMen(int[], int[], int);
void Mostrar2VecLista(int[], int[], int);


int main()
{
    int vecFilOcup[FILAS] = {0}, VecSumaFilaMat[FILAS] = {0}, vecSumaBut[COLUMNAS] = {0}, vecButacas[COLUMNAS] ={8, 6, 4, 2, 1, 3, 5, 7, 9}, fila, butaca, pos, contAR=0, mayor, i, cant, butreserv;
    char matSala[FILAS][COLUMNAS];

    setlocale(LC_ALL, "spanish");

    InicializaMatrizChar(matSala, 'D', FILAS, COLUMNAS);
    printf("A continuación se procederá a la reserva de asientos en la sala: \n");
    printf("\nIngrese el número de fila a reservar (1 a 12 o 0 para terminar): ");
    fila = ValidaIntEntre(0, FILAS);
    while(fila!=0)
    {
        printf("Ingrese el número de butaca (1 a 9): ");
        butaca = ValidaIntEntre(1, 9);
        printf("Ingrese la cantidad de butacas a reservar (las mismas se reservaran a la derecha de la butaca elegida): ");
        pos = BusquedaSecuencialInt(vecButacas, butaca, COLUMNAS);
        cant = ValidaIntEntre(1, 9-pos);
        i = pos;
        butreserv = FALSO;
        while(i<pos+cant && !butreserv)
        {
            if(matSala[fila-1][i] == 'R')
            {
                butreserv = VERDADERO;
                printf("\nHay una butaca reservada, deberá volver a elegir.\n");
            }
            i++;
        }
        if(!butreserv)
        {
            for(i=pos; i<pos+cant; i++)
            {
                matSala[fila-1][i] = 'R';
                vecFilOcup[fila-1] = VERDADERO;
                vecSumaBut[i] ++;
                VecSumaFilaMat[fila-1] ++;
            }
            printf("F\n /\t8\t6\t4\t2\t1\t3\t5\t7\t9\n  B\n");
            printf("--------------------------------------------------------------------------\n");
            MostrarMatrizChar(matSala, FILAS, COLUMNAS);
        }
        printf("\nIngrese el número de fila a reservar (1 a 12 o 0 para terminar): ");
        fila = ValidaIntEntre(0, FILAS);
    }
    printf("F\n /\t8\t6\t4\t2\t1\t3\t5\t7\t9\n  B\n");
    printf("--------------------------------------------------------------------------\n");
    MostrarMatrizChar(matSala, FILAS, COLUMNAS);

    ////a////
    contAR = ContarEnMatrizChar(matSala, 'R', FILAS, COLUMNAS);
    printf("\nLa cantidad de asientos reservados es %d y la cantidad de asientos disponibles es %d.\n", contAR, FILAS * COLUMNAS - contAR);

    ////b////
    printf("\nLos números de filas que quedaron vacias son: \n");
    for(i=0; i<FILAS; i++)
        if(!vecFilOcup[i])
            printf("Fila %d\n", i+1);

    ////c////
    mayor = HallarMayorInt(VecSumaFilaMat, FILAS);
    printf("\nLa/s fila/s con mayor cantidad de butacas vendidas es/son: \n");
    MostrarIgualAInt(VecSumaFilaMat, mayor, FILAS);

    ////d////
    OrdenaBurbuja2MayAMen(vecButacas, vecSumaBut, COLUMNAS);
    printf("\nEl listado con la cantidad de personas que se sentaron en los mismos números de butacas en todo el cine ordenado de mayor a menor es:\nButaca\tCantidad\n");
    Mostrar2VecLista(vecButacas, vecSumaBut, COLUMNAS);

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

void InicializaMatrizChar(char m[][COLUMNAS], char l, int cf, int cc)
{
    int i, j;

    for(i=0; i<cf; i++)
        for(j=0; j<cc; j++)
            m[i][j] = 'D';
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

void MostrarMatrizChar(char m[][COLUMNAS], int cf, int cc)
{
    int i, j;

    for(i=0; i<cf; i++)
    {
        printf("%d\t", i+1);
        for(j=0; j<cc; j++)
            printf("%c\t", m[i][j]);

        printf("\n");
    }
}

/*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int ContarEnMatrizChar(char m[][COLUMNAS], char l, int cf, int cc)
{
    int i, j, cont=0;

    for(i=0; i<cf; i++)
        for(j=0; j<cc; j++)
            if(m[i][j]==l)
                cont ++;

    return cont;
}

/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

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

void MostrarIgualAInt(int v2[], int num, int ce)
{
    int i;

    for(i=0; i<ce; i++)
    {
        if(v2[i] == num)
            printf("%d\n", i+1);
    }
}
/*////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void OrdenaBurbuja2MayAMen(int v1[], int v2[], int ce)
{
    int aux, i=0 , j, huboCambio;

    do
    {
        huboCambio = 0;
        for(j=1; j<ce-i; j++)
        {
            if(v2[j-1]<v2[j])
            {
                aux = v2[j-1];
                v2[j-1] = v2[j];
                v2[j] = aux;

                aux = v1[j-1];
                v1[j-1] = v1[j];
                v1[j] = aux;

                huboCambio = 1;
            }
        }
        i++;
    } while(huboCambio);
}

/*//////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void Mostrar2VecLista(int v1[], int v2[], int ce)
{
    int i;

    for(i=0; i<ce; i++)
        printf("%d\t%d\n", v1[i], v2[i]);
}
