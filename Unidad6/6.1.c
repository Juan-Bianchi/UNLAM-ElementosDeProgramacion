/*6.1. Realizar un programa que al ingresar solicite el ingreso de dos n�meros enteros y luego muestre por pantalla el siguiente men� (las xx de
los n�meros deben ser reemplazadas con los valores correspondientes):
Men� de Opciones
---- -- --------
Numero 1: xx Numero 2: xx
1) Sumar
2) Restar
3) Multiplicar
4) Dividir
5) Ingresar Nuevos N�meros
6) Salir
Ingrese su opci�n:
Al ingresar el n�mero de la opci�n del 1 al 4, se realiza la operaci�n y muestra el resultado hasta que se presione una tecla. Luego vuelve a
mostrar el men� para poder realizar otra operaci�n con los mismos n�meros. La opci�n 5 pide el ingreso de dos nuevos n�meros de trabajo mientras
que la opci�n 6 sale y cierra el programa.
El ingreso de la opci�n debe estar validado y en caso de ingresarse un n�mero no v�lido debe solicitarlo nuevamente.
Usar una funci�n para mostrar el men� y retornar el valor elegido.*/

#include <stdio.h>
#include <string.h>
#define TODO_OK 0

void mostrarMenu(const int num1, const int num2);
int esValidoIntEntre(const int num, const int inf, const int sup);
int validaIntEntre(const int inf, const int sup);
int suma(const int num1, const int num2);
int resta(const int num1, const int num2);
int multiplica(const int num1, const int num2);
float divide(const int num1, const int num2);

int main()
{
    int num1, num2, opc, res;
    float resDiv;

    printf("A continuacion se ingresaran dos numeros enteros: \n");
    printf("Ingrese el primer numero: ");
    scanf("%d", &num1);
    fflush(stdin);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &num2);
    fflush(stdin);
    mostrarMenu(num1, num2);
    opc = validaIntEntre(1, 6);
    while(opc!=6)
    {
        if(opc==1)
        {
            res = suma(num1, num2);
            printf("El resultado de la suma es %d\n", res);
        }
        if(opc==2)
        {
            res = resta(num1, num2);
            printf("El resultado de la resta es %d\n", res);
        }
        if(opc==3)
        {
            res = multiplica(num1, num2);
            printf("El resultado de la multiplicacion es %d\n", res);
        }
        if(opc==4)
        {
            resDiv = divide(num1, num2);
            printf("El resultado de la division es %.2f\n", resDiv);
        }
        if(opc==5)
        {
            printf("Ingrese el primer numero: ");
            scanf("%d", &num1);
            fflush(stdin);
            printf("Ingrese el segundo numero: ");
            scanf("%d", &num2);
            fflush(stdin);
        }
        mostrarMenu(num1, num2);
        opc = validaIntEntre(1, 6);
    }

    return TODO_OK;
}


void mostrarMenu(const int num1, const int num2)
{
    printf("\nNumero 1: %d Numero 2: %d\n\
        1) Sumar\n\
        2) Restar\n\
        3) Multiplicar\n\
        4) Dividir\n\
        5) Ingresar Nuevos Numeros\n\
        6) Salir\n\
        Ingrese su opcion: ", num1, num2);
}

int esValidoIntEntre(const int num, const int inf, const int sup)
{
    return ( num>=inf && num<=sup);
}


int validaIntEntre(const int inf, const int sup)
{
    int num, esValido;

    do
    {
        fflush(stdin);
        scanf("%d", &num);
        fflush(stdin);
        esValido = esValidoIntEntre(num, inf, sup);
        if(!esValido)
            printf("El numero ingresado no es valido, el mismo debe estar entre %d y %d\n", inf, sup);
    } while(!esValido);

    return num;
}

int suma(const int num1, const int num2)
{
    return num1 + num2;
}


int resta(const int num1, const int num2)
{
    return num1 - num2;
}

int multiplica(const int num1, const int num2)
{
    return num1 * num2;
}

float divide(const int num1, const int num2)
{
    return (float)num1 / num2;
}

