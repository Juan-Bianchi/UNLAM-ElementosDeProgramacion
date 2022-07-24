/*6.7. Confeccionar un programa que permita ingresar diversas ternas de valores enteros mayores que 0 y menores que 99. Finalizar el ingreso
cuando se informen 3 valores iguales a 96, 97 y 98. Determinar e informar para cada terna, el mayor y el menor de los valores. Confeccionar y
utilizar una función con parámetros llamada MayorMenor, que permita calcular el menor o el mayor valor de la terna según un parámetro de
configuración.*/

#define min(a,b)        ( ((a)<(b))?(a):(b) )
#define max(a,b)        ( ((a)>(b))?(a):(b) )

#include<stdio.h>
#include<locale.h>

int validaIntEntre(const int inf, const int sup);
int estaDentroDelRango(const int num, const int inf, const int sup);
int mayorMenor(const int num1, const int num2, const int num3, const int parametro);


int main()
{
    int num1, num2, num3, parametro;

    setlocale(LC_ALL, "spanish");

    printf("A continuacion se ingresarán ternas de números entre 0 y 99 (96, 97, 98 para terminar): \n");
    printf("Ingrese el primer número: ");
    num1 = validaIntEntre(0,99);
    printf("Ingrese el segundo número: ");
    num2 = validaIntEntre(0,99);
    printf("Ingrese el tercer número: ");
    num3 = validaIntEntre(0,99);

    while(num1!=96 || num2!=97 || num3!=98)
    {
        printf("Ingrese el parametro (1 para menor, 2 para mayor): ");
        parametro = validaIntEntre(1,2);

        if(parametro==1)
            printf("El menor de la terna es %d\n\n", mayorMenor(num1, num2, num3, parametro));
        else
            printf("El mayor de la terna es %d\n\n", mayorMenor(num1, num2, num3, parametro));

        printf("A continuacion se ingresarán ternas de números entre 0 y 99 (96, 97, 98 para terminar): \n");
        printf("Ingrese el primer número: ");
        num1 = validaIntEntre(0,99);
        printf("Ingrese el segundo número: ");
        num2 = validaIntEntre(0,99);
        printf("Ingrese el tercer número: ");
        num3 = validaIntEntre(0,99);
    }
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
            printf("El numero ingresado no es válido. El mismo debe estar entre %d y %d. Vuelva a ingresar: ");
    } while(!esValido);

    return num;
}


int mayorMenor(const int num1, const int num2, const int num3, const int parametro)
{
    return (parametro==1)? min(min(num1, num2), num3): max(max(num1, num2), num3);
}

