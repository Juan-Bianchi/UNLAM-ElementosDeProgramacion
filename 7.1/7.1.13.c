/*7.1.13 Para una carrera de autom�viles, se toman los tiempos de clasificaci�n (real, mayor que 0 en segundos y cent�simos de
segundo) de como m�ximo 60 autos de carrera inscriptos para la competencia.
Los autos se identifican con n�meros correlativos del 1 al 60, quedando sin informaci�n aquellos que no participan de la presente
carrera.
Cuando ya no hay m�s tiempos de clasificaci�n para cargar, se ingresa un auto con n�mero negativo.
Se solicita determinar:
a. El n�mero de auto que clasific� en primer lugar.
b. El n�mero de auto que obtuvo el peor tiempo de clasificaci�n.
c. La cantidad de autos que superaron el promedio de tiempo de clasificaci�n.
d. El o los n�meros de autos que no participan de la carrera actual.*/


#include <stdio.h>
#include <locale.h>
#define TAM 60

int ValidaIntCorrYFin(int, int);
float ValidaFloatMayA(int);
float HallarMenorFloat(float[], int);
float HallarMAyorFloat(float[], int);
void MostrarIgualAFloat(int[], float[], float, int);


int main()
{
    float vecTiempos[TAM], prom, suma = 0, menor, mayor;
    int vecAutos[TAM], cont = 0, num, i, cont1 = 0;

    setlocale(LC_ALL, "spanish");

    printf("A continuaci�n se proceder� a la carga de los automoviles y sus respectivos tiempos de clasificaci�n: \n");
    printf("Ingrese el n�mero de automovil (n�meros correlativos de 1 a 60 o negativo para terminar): ");
    num = ValidaIntCorrYFin(cont, 0);
    while(num>-1)
    {
        vecAutos[cont] = num;
        printf("Ingrese el tiempo de clasificaci�n (real, mayor que 0 en segundos y cent�simos de segundo): ");
        vecTiempos[cont] = ValidaFloatMayA(0);
        suma += vecTiempos[cont];
        cont++;
        printf("Ingrese el n�mero de automovil (n�meros correlativos de 1 a 60 o negativo para terminar): ");
        num = ValidaIntCorrYFin(cont, 0);
    }
    if(cont)
    {
        menor = HallarMenorFloat(vecTiempos, cont);
        printf("\nEl mejor tiempo de clasificaci�n es %.4f y el los veh�culos que lograron el mismo son: \n", menor);
        MostrarIgualAFloat(vecAutos, vecTiempos, menor, cont);

        mayor = HallarMAyorFloat(vecTiempos, cont);
        printf("\nEl peor tiempo de clasificaci�n es %.4f y el los veh�culos que lograron el mismo son: \n", mayor);
        MostrarIgualAFloat(vecAutos, vecTiempos, mayor, cont);

        prom = suma / cont;
        for(i=0; i<cont; i++)
            if(vecTiempos[i] > prom)
                cont1 ++;
        printf("La cantidad de autos que superaron el promedio de tiempo de clasificaci�n es: %d\n", cont1);


        printf("\nEl/los autos que no participaron de la carrera son: \n");
        for(i=cont+1; i<=TAM; i++)
            printf("%d\n", i);
    }
    else
        printf("\nNo se han ingresado automoviles\n");

        return 0;
}

/*//////////////////////////////////////////////////////////FUNCIONES///////////////////////////////////////////////////////*/

int ValidaIntCorrYFin(int n, int cf)
{
    int num, band=0;

    do
    {
        if(band)
            printf("El valor proporcionado debe ser correlativo a %d o negativo para terminar. Intente nuevamente.\n", n);

        scanf("%d", &num);
        band = 1;
    } while(num!=n+1 && num>=cf);

    return num;
}

/*///////////////////////////////////////////////////////////////////////////////////////////////////////*/

float ValidaFloatMayA(int inf)
{
    float num;
    int band = 0;

    do
    {
        if(band)
            printf("El valor proporcionado debe ser mayor a %d. Intente nuevamente.\n", inf);

        scanf("%f", &num);
        band = 1;
    } while(num<inf);

    return num;
}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////*/

float HallarMenorFloat(float v[], int ce)
{
    int i = 0;
    float menor;

    menor = v[i];

    for(i=1; i<ce; i++)
        if(menor>=v[i])
            menor = v[i];

    return menor;
}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

float HallarMAyorFloat(float v[], int ce)
{
    int i = 0;
    float mayor;

    mayor = v[i];

    for(i=1; i<ce; i++)
        if(mayor<=v[i])
            mayor = v[i];

    return mayor;
}

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

void MostrarIgualAFloat(int v1[], float v2[], float num, int ce)
{
    int i;

    for(i=0; i<ce; i++)
    {
        if(v2[i] == num)
            printf("%d\n", v1[i]);
    }
}
