/*7.2.8 Un consorcio desea controlar la cobranza de las expensas en un edificio de 5 pisos donde existen 15 departamentos en
cada piso. El valor de las expensas es de $ 1000. Para registrar la cobranza se ingresa el número de piso (1 a 5) y el
número de departamento (correlativo de 1 a 15 en cada piso). El ingreso finaliza con un piso igual a 99.
Al finalizar mostrar el dinero total recaudado y una tabla con una X indicando aquellos departamentos deudores de la
siguiente manera:
                                    TOTAL RECAUDADO
                                DEPARTAMENTOS DEUDORES

                    PISO        DPTO 1      DPTO2…      DPTO 15
                    PISO 1        X
                    PISO 2                    X             X
                    PISO 3        X
                    PISO 4                    X             X
                    PISO 5        X           X
*/


#include <stdio.h>
#define FILAS 5
#define COLUMNAS 15
#define TODO_OK 0
#define VERDADERO 1
#define FALSO 0

typedef int booleano;


int ValidaIntEntre(int, int);
int ValidaIntEntreYCondFin(int, int, int);
void InicializaMatrizChar(char[][COLUMNAS], int ,int);
void MostrarMatrizChar(char[][COLUMNAS], int, int);


int main()
{
    float expTot = 0, exp = 1000;
    int cantDep = 0, dep, piso;
    char vecEdif[FILAS][COLUMNAS];

    InicializaMatrizChar(vecEdif, FILAS, COLUMNAS);
    printf("A continuación se proporcionara la informacion del pago de expensas: \n\n");
    printf("Ingrese el numero de piso (1 a 5 o 99 para terminar): ");
    piso = ValidaIntEntreYCondFin(1, 5, 99);
    while(dep!= 99)
    {
        printf("\nIngrese el numero de departamento (1 a 15): ");
        dep = ValidaIntEntre(1, 15);
        vecEdif[piso-1][dep-1] = ' ';
        expTot += exp;
        printf("%80s%.0f\n\n%85s\n\n%s%15s%9s%9s%9s%9s%9s%9s%9s%9s%9s%9s%9s%9s%9s%9s\n", "TOTAL RECAUDADO: $",expTot, "DEPARTAMENTOS DEUDORES", "PISO", "DPTO 1","DPTO 2", "DPTO 3", "DPTO 4", "DPTO 5", "DPTO 6", "DPTO 7", "DPTO 8", "DPTO 9", "DPTO 10", "DPTO 11", "DPTO 12", "DPTO 13", "DPTO 14", "DPTO 15");
        MostrarMatrizChar(vecEdif, FILAS, COLUMNAS);

        printf("\n\nIngrese el numero de piso (1 a 5 o 99 para terminar): ");
        piso = ValidaIntEntreYCondFin(1, 5, 99);
    }
    printf("%80s%.0f\n\n%85s\n\n%10s%9s%9s%9s%9s%9s%9s%9s%9s%9s%9s%9s%9s%9s%9s%9s\n", "TOTAL RECAUDADO",expTot, "DEPARTAMENTOS DEUDORES", "PISO", "DPTO 1","DPTO 2", "DPTO 3", "DPTO 4", "DPTO 5", "DPTO 6", "DPTO 7", "DPTO 8", "DPTO 9", "DPTO 10", "DPTO 11", "DPTO 12", "DPTO 13", "DPTO 14", "DPTO 15");
    MostrarMatrizChar(vecEdif, FILAS, COLUMNAS);

    return TODO_OK;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int ValidaIntEntre(int min, int max)
{
    booleano hayError = FALSO;
    int valor;

    do
    {
        if(hayError)
            printf("\nError en el ingreso. El dato debe estar entre %d y %d. Vuelva a ingresar: ", min, max);
        scanf("%d", &valor);
        hayError = VERDADERO;
    } while(valor < min || valor > max);

    return valor;
}

/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

int ValidaIntEntreYCondFin(int min, int max, int condFin)
{
    booleano hayError = FALSO;
    int valor;

    do
    {
        if(hayError)
            printf("\nError en el ingreso. El dato debe estar entre %d y %d o %d para terminar. Vuelva a ingresar: ", min, max, condFin);
        scanf("%d", &valor);
        hayError = VERDADERO;
    } while((valor < min || valor > max) && valor!=condFin);

    return valor;
}

/*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void InicializaMatrizChar(char mat[][COLUMNAS], int f, int c)
{
    int i, j;

    for(i=0; i<f; i++)
        for(j=0; j<c; j++)
            mat[i][j] = 'X';
}

/*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void MostrarMatrizChar(char mat[][COLUMNAS], int f, int c)
{
    int i, j;

    for(i=0; i<f; i++)
    {
        printf("PISO %d", i+1);
        for(j=0; j<c; j++)
            printf("%9c", mat[i][j]);
        printf("\n");
    }
}
