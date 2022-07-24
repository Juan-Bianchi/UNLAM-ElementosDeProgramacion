/*6.3. Se realizó un concurso de tiro al blanco. Por cada participante se ingresa un número que lo identifica y el resultado de los disparos
efectuados. El ingreso finaliza con un número de participante negativo.
Cada participante efectúa 5 disparos, registrándose las coordenadas X-Y de cada disparo.
• No considere disparos sobre los ejes, pero sí en el centro (si es sobre los ejes las coordenadas deberán volver a ingresarse).
• Para determinar el cuadrante utilizar la función CUADRANTE que reciba las dos coordenadas y retorne el cuadrante al cual pertenece (1 a 4) y 0
para indicar un tiro en el centro.
Para calcular el puntaje utilizar la función PUNTAJE que reciba 5 parámetros que representan la cantidad disparos en cada cuadrante y en el centro.
La función debe retornar el puntaje obtenido según la siguiente escala:
* Cuadrantes 1 y 2: 50 puntos
* Cuadrantes 3 y 4: 40 puntos
* Centro: 100 puntos
Determinar:
a. El puntaje obtenido por cada participante, detallando cuantos disparos realizó en cada cuadrante.
b. Mostrar el número del participante ganador y el puntaje obtenido.
c. Calcular y mostrar la cantidad total de disparos en el centro (de todos los participantes)*/

#include<stdio.h>
#include<locale.h>

#define TODO_OK 0

int estaDentroDelRango(const int num, const int inf, const int sup);
int validaIntEntre(const int inf, const int sup);
int cuadrante(const int coordX, const int coordY);
int puntaje(const int disp1, const int disp2, const int disp3, const int disp4, const int disp5);

int main()
{
    int i, num, contCuad1, contCuad2, contCuad3, contCuad4, contCen, contCenTot = 0, coordX, coordY, numMay = 0, puntMay = 0, cuad, punt;

    setlocale(LC_ALL, "spanish");

    printf("A continuación se registraran los disparos de los diferentes participantes: ");

    printf("Ingrese el numero de participante (negativo para terminar): ");
    fflush(stdin);
    scanf("%d", &num);
    fflush(stdin);
    while(num>=0)
    {
        i = 0;
        contCuad1 = 0;
        contCuad2 = 0;
        contCuad3 = 0;
        contCuad4 = 0;
        contCen = 0;
        while(i<5)
        {
            do
            {
                printf("Ingrese la coordenada X del disparo numero %d: ", i+1);
                fflush(stdin);
                scanf("%d", &coordX);
                fflush(stdin);
                printf("Ingrese la coordenada Y del disparo numero %d: ", i+1);
                scanf("%d", &coordY);

                if( (coordX == 0 && coordY != 0) || (coordX != 0 && coordY == 0) )
                    printf("El disparo no puede realizarse sobre los ejes. Vuelva a disparar.\n");
            } while ( (coordX == 0 && coordY != 0) || (coordX != 0 && coordY == 0) );
            cuad = cuadrante(coordX, coordY);
            if(cuad==1)
                contCuad1 ++;
            if(cuad==2)
                contCuad2 ++;
            if(cuad==3)
                contCuad3 ++;
            if(cuad==4)
                contCuad4 ++;
            if(cuad==0)
            {
                contCen ++;
                contCenTot ++;
            }
            i ++;
        }
        punt = puntaje(contCuad1, contCuad2, contCuad3, contCuad4, contCen);
        printf("El puntaje del participante %d es %d y efectuo %d disparos en el cuadrante 1, %d disparos en el cuadrante 2, %d disparos en el cuadrante 3, %d disparos en el cuadrante 4 y %d disparos en el centro\n", i+1, punt, contCuad1, contCuad2, contCuad3, contCuad4, contCen);
        if(punt>puntMay)
        {
            puntMay = punt;
            numMay = num;
        }
        printf("Ingrese el numero de participante (negativo para terminar): ");
        fflush(stdin);
        scanf("%d", &num);
        fflush(stdin);
    }
    printf("El participante ganador es el participante numero %d y su puntaje es %d\n", numMay, puntMay);
    printf("La cantidad de disparos total al centro es %d\n\n", contCen);

    return TODO_OK;
}


int estaDentroDelRango(const int num, const int inf, const int sup)
{
    return num >= inf && num <= sup;
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
            printf("El numero ingresado no es válido. El mismo debe estar entre %d y %d. Vuelva a ingresar: ");
    } while(!esValido);

    return num;
}



int cuadrante(const int coordX, const int coordY)
{
    if(coordX>0 && coordY>0)
        return 1;
    if(coordX<0 && coordY>0)
        return 2;
    if(coordX<0 && coordY<0)
        return 3;
    if(coordX>0 && coordY<0)
        return 4;
    if(coordX == 0 && coordY == 0)
        return 0;
}



int puntaje(const int disp1, const int disp2, const int disp3, const int disp4, const int disp5)
{
    return disp1 * 50 + disp2 * 50 + disp3 * 40 + disp4 * 40 + disp5 * 100;
}
