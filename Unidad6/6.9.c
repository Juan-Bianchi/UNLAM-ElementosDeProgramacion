/*6.9. Realizar una función que reciba 3 números enteros correspondientes al día, mes y año de una fecha y valide si la misma es correcta. En caso
de que la fecha es correcta debe retornar un 1 y si es incorrecta debe retornar un 0. Para la validación usar la función del punto 8 que retorna
la cantidad de días de un mes.*/

#include<stdio.h>
#include<locale.h>

int esBisiesto(const int anio);
int cantDiasDelMes(const int mes, const int anio);
int esFechaValida(const int dia, const int mes, const int anio);

int main()
{
    int dia, mes, anio;

    setlocale(LC_ALL, "spanish");

    printf("Ingrese la fecha a verificar (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &dia, &mes, &anio);

    if(esFechaValida(dia, mes, anio))
        printf("La fecha %02d/%02d/%d es válida.", dia, mes, anio);
    else
        printf("La fecha %02d/%02d/%4d no es válida.", dia, mes, anio);

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

int esFechaValida(const int dia, const int mes, const int anio)
{
    return (anio>=1601 && mes>=1 && mes<=12 && dia>=1 && dia<=cantDiasDelMes(mes, anio));
}
