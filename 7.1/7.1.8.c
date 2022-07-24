/*7.1.8 Se ingresan DNI y nota de un parcial de los alumnos de un curso. El ingreso de datos finaliza con un DNI negativo. Se sabe
que como máximo pueden presentarse a rendir 60 alumnos. Mostrar:
a. Listado de alumnos con su correspondiente DNI y la nota obtenida (en forma de listado)
b. La máxima nota obtenida y el DNI de los alumnos que la obtuvieron.*/


#include <stdio.h>
#include <locale.h>
#define TAM 60

int ValidaIntEntre(int, int);
int ValidaIntEntre2(int, int);
void Mostrar2VecLista(int[], int[], int);
void MostrarMayorInt(int[], int[], int);

int main()
{
    int dni, nota, vecDNI[TAM], vecNota[TAM], cant = 0;

    setlocale(LC_ALL, "spanish");

    printf("A continuación se cargaran los DNI de los alumnos: \n");
    printf("Ingrese el número de DNI (número negativo para terminar): ");
    dni = ValidaIntEntre2(0, 10000000);
    while(dni>0 && cant<TAM)
    {
        printf("Ingrese la nota del alumno (1 a 10): ");
        nota = ValidaIntEntre(1,10);
        vecDNI[cant] = dni;
        vecNota[cant] = nota;
        cant++;
        printf("Ingrese el número de DNI (número negativo para terminar): ");
        dni = ValidaIntEntre2(0, 10000000);
    }
    printf("\nListado de alumnos con sus respectivas notas: \n");
    Mostrar2VecLista(vecDNI, vecNota, cant);
    MostrarMayorInt(vecDNI, vecNota, cant);

    return 0;
}

/*//////////////////////////////////////////////////////////////FUNCIONES///////////////////////////////////////////////*/

int ValidaIntEntre(int inf, int sup)
{
    int num, band=0;

    do
    {
        if(band)
            printf("El valor proporcionado debe ser un entero mayor %d y menor a %d. Intente nuevamente.\n", inf, sup);

        scanf("%d", &num);
        band = 1;
    } while(num<inf || num>sup);

    return num;
}


int ValidaIntEntre2(int inf, int sup)
{
    int num, band=0;

    do
    {
        if(band)
            printf("El valor proporcionado debe ser un entero mayor a %d o menor a %d para terminar. Intente nuevamente.\n", sup, inf);

        scanf("%d", &num);
        band = 1;
    } while(num>=inf && num<sup);

    return num;
}


void Mostrar2VecLista(int vec1[], int vec2[], int ce)
{
    int i;

    printf("%15s%15s\n", "DNI", "Nota");
    printf("%30s\n", "----------------------");
    for(i=0; i<ce; i++)
        printf("%15d%15d\n", vec1[i], vec2[i]);
}


void MostrarMayorInt(int v1[], int v2[], int ce)
{
    int i = 0, mayor, codMayor;

    mayor = v2[i];
    codMayor = v1[i];

    for(i=1; i<ce; i++)
        if(mayor<=v2[i])
            mayor = v2[i];

    printf("\nLa nota más alta fue %d y los DNI de los alumnos que obtuvieron esas notas son: \n", mayor);

    for(i=0; i<ce; i++)
        if(v2[i] == mayor)
            printf("---%d", v1[i]);
}
