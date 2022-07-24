/*6.2. Se ingresan números enteros comprendidos entre 100 y 2000 (usar función LeerYValidar). Determinar usando la función EstaDentroDelRango:
a. Cantidad de números ingresados entre 100 y 500
b. Cantidad de números pares ingresados entre 500 y 1200
c. Promedio de números ingresados entre 1200 y 2000
El ingreso de datos finaliza cuando se ingresa un número igual a 99.
Para realizar este programa se deben realizar las siguientes funciones:
• EstaDentroDelRango: que reciba 3 enteros correspondientes a un número a validar y los límites superior e inferior del rango. La función debe
retornar un 1 si el número a validar se encuentra dentro del rango indicado o un 0 si no lo está.
• LeerYValidar: que reciba los límites superior e inferior de un rango y retorne un número que se encuentre dentro del mismo. (El ingreso de datos
se realiza dentro de la función). Para validar el rango utilizar la función EstaDentroDelRango realizada en el punto anterior.*/

#define TODO_OK 0;
#include<stdio.h>


int estaDentroDelRango(const int num, const int inf, const int sup);
int leerYValidar(const int inf, const int sup);

int main(void)
{
    int num, cont1 = 0, cont2 = 0, cont3 = 0, suma3 = 0;
    float prom3 = 0;

    printf("Ingrese un numero entero (entre 100 y 2000 o 99 para terminar): ");
    num = leerYValidar(99, 2000);
    while(num != 99)
    {
        if(num>=100 && num<=500)
            cont1 ++;
        if(num>=500 && num<=1200 && num%2==0)
            cont2 ++;
        if(num>=1200 && num<=2000)
        {
            cont3 ++;
            suma3 += num;
        }

        printf("Ingrese un numero entero (entre 100 y 2000 o 99 para terminar): ");
        num = leerYValidar(99, 2000);
    }
    if(suma3)
        prom3 = (float)suma3 / cont3;

    printf("La cantidad de numeros ingresados entre 100 y 500 es %d\n", cont1);
    printf("La cantidad de numeros multiplos de 2 entre 500 y 1200 es %d\n", cont2);
    printf("El promedio de los numeros ingresados entre 1200 y 2000 es %.2f\n\n", prom3);

    return TODO_OK;
}


int estaDentroDelRango(const int num, const int inf, const int sup)
{
    return num>=inf && num<=sup;
}


int leerYValidar(const int inf, const int sup)
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
