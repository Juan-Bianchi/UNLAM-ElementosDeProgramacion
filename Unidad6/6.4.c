/*6.4. Se ingresa valores positivos entre 1 y 50, finalizando el ingreso con el valor -10, para ello generar una funci�n que valide dicho ingreso.
Calcular:
a. Cu�ntos n�meros son primos.
b. Cantidad de n�meros pares.
c. Promedio de los n�meros impares.
Utilizar las siguientes funciones:
� Resto: recibe por par�metro el Dividendo y el Divisor; Retorna el resto.
� EsPar: recibe por par�metro un n�mero; Retorna 1 si es Par, 0 si es Impar; Invoca a la funci�n Resto.
� EsPrimo: recibe por par�metro un n�mero; Retorna 1 si es primo, 0 si no es primo; Invoca a la funci�n Resto. (un n�mero es primero si solo es
divisible por 1 y por s� mismo).
� Promedio: recibe por par�metro la suma y el contador; Retorna el promedio si contador > 0 sino Retorna 0.*/


#define TODO_OK 0
#include<stdio.h>
#include<locale.h>

int estaEnElRangoYCondFin(const int num, const int inf, const int sup, const int condF);
int validaIntEntreYCondFin(const int inf, const int sup, const int condF);
int resto(const int num, const int div);
int esPAr(const int num);
int promedio(const int suma, const int contador);

int main()
{
    int num, contPar = 0, contPrim = 0, sumaImp = 0, contImp, promImp = 0, contDiv, i;

    setlocale(LC_ALL, "spanish");
    printf("A continuaci�n se ingresaran numeros enteros entre 1 y 50 (-10 para terminar): \n\n");
    printf("Ingrese entero entre 1 y 50 (-10 para terminar): ");
    num = validaIntEntreYCondFin(1, 50, -10);
    while(num!=-10)
    {
        contDiv = 0;
        i = 2;
        contImp = 0;
        if(esPAr(num))
        {
            sumaImp += num;
            contImp ++;
        }
        else
            contPar ++;
        while(i<=num/2 && contDiv<1)
        {
            if(!resto(num, i))
                contDiv ++;
            i ++;
        }
        if(contDiv == 0)
            contPrim ++;

        printf("Ingrese entero entre 1 y 50 (-10 para terminar): ");
        num = validaIntEntreYCondFin(1, 50, -10);
    }
    printf("La cantidad de n�meros primos es %d\n", contPrim);
    printf("La cantidad de n�meros pares es %d\n", contPar);
    printf("El promedio de los n�meros impares es %d\n\n", promImp);

    return TODO_OK;
}


int estaEnElRangoYCondFin(const int num, const int inf, const int sup, const int condF)
{
    return ( num >= inf && num <= sup) || num == condF;
}


int validaIntEntreYCondFin(const int inf, const int sup, const int condF)
{
    int num, esValido;

    do
    {
        fflush(stdin);
        scanf("%d", &num);
        fflush(stdin);
        esValido = estaEnElRangoYCondFin(num, inf, sup, condF);

        if(!esValido)
            printf("El n�mero ingresado no es v�lido. Debe estar entre %d y %d, o % para terminar. Vuelva a ingresar: ");
    } while (!esValido);

    return num;
}



int resto(const int num, const int div)
{
    return num % div;
}


int esPAr(const int num)
{
    return num % 2 == 0;
}


int promedio(const int suma, const int contador)
{
    return (suma)? suma/contador: 0;
}
