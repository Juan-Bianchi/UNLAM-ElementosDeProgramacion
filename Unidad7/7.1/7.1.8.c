/*7.1.8 Se ingresan DNI y nota de un parcial de los alumnos de un curso. El ingreso de datos finaliza con un DNI negativo. Se sabe que como máximo
pueden presentarse a rendir 60 alumnos. Mostrar:
a. Listado de alumnos con su correspondiente DNI y la nota obtenida (en forma de listado)
b. La máxima nota obtenida y el DNI de los alumnos que la obtuvieron.*/


#include<stdio.h>
#include<string.h>
#define TAM 60

int estaDentroDelRango(const int num, const int inf, const int sup);
int validaIntEntre(const int inf, const int sup);
int validaIntMayAYCondFin(const int inf, const int condF);
int cargaAlumnos(int* vecDni, int* vecNotas, const int cantElem);
void mostrarListadoAlumnos(const int* vecDni, const int* vecNotas, const int tamElem);
int buscarMayor(const int* vecNotas, const int tamElem);
void mostrarMaximos(const int* vecDni, const int* vecNotas, const int tamElem, const int may);

int main()
{
    int vecDni[TAM], vecNotas[TAM], may, cantAlum;

    printf("A continuacion se procedera con la carga de los alumnos: \n");
    cantAlum = cargaAlumnos(vecDni, vecNotas, TAM);

    printf("El listado de alumnos con su correspondiente nota de parcial es: \n");
    mostrarListadoAlumnos(vecDni, vecNotas, cantAlum);

    may = buscarMayor(vecNotas, cantAlum);
    printf("\nLa maxima nota obtenida es %d y los alumnos que la obtuvieron son: \n", may);
    mostrarMaximos(vecDni, vecNotas, cantAlum, may);

    return 0;
}


int validaIntMayAYCondFin(const int inf, const int condF)
{
    int num;

    do
    {
        fflush(stdin);
        scanf("%d", &num);
        fflush(stdin);
        if(num<=inf && num>condF)
            printf("El numero ingresado no es valido. El mismo debe ser mayor a %d o menor a %d para terminar. Vuelva a ingresar: ", inf, condF);
    } while(num<=inf && num>condF);

    return num;
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

int cargaAlumnos(int* vecDni, int* vecNotas, const int cantElem)
{
    int dni, cantAl=0;
    int* pVecDni = vecDni, * pVecNot = vecNotas;

    printf("Ingrese el DNI del alumno (mayor a 10.000.000 o negativo para terminar): ");
    dni = validaIntMayAYCondFin(10000000, -1);
    while(dni>-1 && pVecDni<=vecDni+cantElem-1)
    {
        cantAl ++;
        *pVecDni = dni;
        printf("Ingrese la nota (1 a 10): ");
        *pVecNot = validaIntEntre(1, 10);
        pVecDni ++;
        pVecNot ++;
        printf("Ingrese el DNI del alumno (mayor a 10.000.000 o negativo para terminar): ");
        dni = validaIntMayAYCondFin(10000000, 0);
    }

    return cantAl;
}


void mostrarListadoAlumnos(const int* vecDni, const int* vecNotas, const int cantElem)
{
    const int* pVecDni, * pVecNot = vecNotas;

    printf("%-10s%10s\n", "DNI", "Nota");
    for(pVecDni = vecDni; pVecDni<=vecDni+cantElem-1; pVecDni++)
    {
        printf("%-10d%10d\n", *pVecDni, *pVecNot);
        pVecNot ++;
    }
}


int buscarMayor(const int* vecNotas, const int cantElem)
{
    const int* pvec = vecNotas;
    int mayor = *pvec;

    for(pvec = vecNotas+1; pvec<=vecNotas+cantElem-1; pvec++)
    {
        if(*pvec>mayor)
            mayor = *pvec;
    }
    return mayor;
}


void mostrarMaximos(const int* vecDni, const int* vecNotas, const int cantElem, const int may)
{
    const int* pVecDni, * pVecNot = vecNotas;

    printf("%-10s%10s\n", "DNI", "Nota");
    for(pVecDni = vecDni; pVecDni<=vecDni+cantElem-1; pVecDni++)
    {
        if(*pVecNot == may)
            printf("%-10d%10d\n", *pVecDni, *pVecNot);
        pVecNot ++;
    }
}
