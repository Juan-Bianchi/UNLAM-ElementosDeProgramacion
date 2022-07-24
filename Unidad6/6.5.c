/*6.5. Confeccionar un programa que permita ingresar varias ternas de valores a punto flotante, que finalice al ingresar una terna con los valores
ORDENADOS en forma creciente. Para cada terna exhibir la siguiente pantalla:
** OPCIONES POSIBLES **
1 – Mayor valor
2 – Promedio
3 – Suma
4 - Finalizar
** Digite su opción:
Según la opción deseada debe aparecer en pantalla el resultado, sin borrar el menú. No admitir otros valores de opción. Confeccionar y utilizar
una función PARA CADA UNA de las opciones y otra para detectar la condición final.*/

#include<stdio.h>
#include<locale.h>
#define max(a,b)    ( ((a)>(b))?(a):(b) )
#define TODO_OK 0

int ordenAscendente(const float num1, const float num2, const float num3);
void suma(const float num1, const float num2, const float num3);
void promedio(const float sum, const float cantElem);
void mayorValor(const float num1, const float num2, const float num3);
int estaDentroDelRango(const int num, const int inf, const int sup);
int validaIntEntre(const int inf, const int sup);


int main()
{
    float num1, num2, num3, prom, sum;
    int opc;

    setlocale(LC_ALL, "spanish");

    printf("Ingrese una terna de valores reales (para terminar ingreselos con un orden de crecimiento ascendente): \n");
    printf("Ingrese el primer valor: ");
    fflush(stdin);
    scanf("%f", &num1);
    printf("Ingrese el segundo valor: ");
    fflush(stdin);
    scanf("%f", &num2);
    fflush(stdin);
    printf("Ingrese el tercer valor: ");
    scanf("%f", &num3);
    while(!ordenAscendente(num1, num2, num3))
    {
        printf("** OPCIONES POSIBLES **\n\
                1 – Mayor valor\n\
                2 – Promedio\n\
                3 – Suma\n\
                4 - Finalizar\n\
                ** Digite su opción: ");
        opc = validaIntEntre(1, 4);
        while(opc==1 || opc==2 || opc==3)
        {
            if(opc == 1)
                mayorValor(num1, num2, num3);
            if(opc == 2)
                promedio(num1 + num2 + num3, 3);
            if(opc == 3)
                suma(num1, num2, num3);
            opc = validaIntEntre(1, 4);
        }

        printf("Ingrese el primer valor: ");
        fflush(stdin);
        scanf("%f", &num1);
        fflush(stdin);
        printf("Ingrese el segundo valor: ");
        scanf("%f", &num2);
        fflush(stdin);
        printf("Ingrese el tercer valor: ");
        scanf("%f", &num3);
    }

    return TODO_OK;

}



int ordenAscendente(const float num1, const float num2, const float num3)
{
    return (num1<num2 && num2<num3);
}


void suma(const float num1, const float num2, const float num3)
{
    printf("** OPCIONES POSIBLES **\n\
                1 – Mayor valor\n\
                2 – Promedio\n\
                3 – Suma = %.2f\n\
                4 - Finalizar\n\
                ** Digite su opción: ", num1+num2+num3);
}

void promedio(const float sum, const float cantElem)
{
    if(suma)
    {
        printf("** OPCIONES POSIBLES **\n\
                1 – Mayor valor\n\
                2 – Promedio = %.2f\n\
                3 – Suma\n\
                4 - Finalizar\n\
                ** Digite su opción: ", sum / cantElem);
    }
    else
    {
        printf("** OPCIONES POSIBLES **\n\
                1 – Mayor valor\n\
                2 – Promedio = 0\n\
                3 – Suma\n\
                4 - Finalizar\n\
                ** Digite su opción: ");
    }
}

void mayorValor(const float num1, const float num2, const float num3)
{
    printf("** OPCIONES POSIBLES **\n\
                1 – Mayor valor = %.2f\n\
                2 – Promedio\n\
                3 – Suma\n\
                4 - Finalizar\n\
                ** Digite su opción: ", max(max(num1, num2), num3));
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
