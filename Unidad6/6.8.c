/*6.8. Realizar una función que, dado un mes y un año, calcule la cantidad de días de dicho mes. El año se utilizará en el caso de que el mes sea
febrero ya que los años bisiestos tienen 29 días en lugar de 28. Un año es bisiesto cuando: (el año es divisible por 4 y NO por 100) o (el año es
divisible por 400).*/

#include<stdio.h>
#include<locale.h>

int estaDentroDelRango(const int num, const int inf, const int sup);
int validaIntEntre(const int inf, const int sup);
int esBisiesto(const int anio);
int cantDiasDelMes(const int mes, const int anio);


int main()
{
    int mes, anio, cantDias;

    setlocale(LC_ALL, "spanish");

    printf("Ingrese el mes: ");
    mes = validaIntEntre(1, 12);
    printf("Ingrese el año(mayor a 1601 y menor a 2023): ");
    anio = validaIntEntre(1601, 2022);

    cantDias = cantDiasDelMes(mes, anio);
    printf("La cantidad de días de el mes número %d es %d\n\n", mes, cantDias);

    return 0;
}

int esBisiesto(const int anio)
{
    return (anio % 4 == 0 && anio % 100 !=0) || anio % 400 == 0;
}

int cantDiasDelMes(const int mes, const int anio)
{
    const int diasXmes[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int bisiesto = esBisiesto(anio);

    if(mes==2)
        return diasXmes[mes-1] + bisiesto;

    return diasXmes[mes-1];
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
