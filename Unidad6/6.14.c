/*6.14. Realizar un programa que ingrese la fecha actual y la fecha de nacimiento de una persona y calcule su edad. Para validar las fechas
utilizar la función del punto 9. Para el cálculo realizar una función que reciba las dos fechas y retorne la edad de la persona.*/

#include<stdio.h>
#include<locale.h>

int esBisiesto(const int anio);
int cantDiasDelMes(const int mes, const int anio);
int esFechaValida(const int dia, const int mes, const int anio);
int calculaEdad(const int diaN, const int mesN, const int anioN, const int diaA, const int mesA, const int anioA);

int main()
{
    int diaN, mesN, anioN, diaA, mesA, anioA;

    setlocale(LC_ALL, "spanish");

    printf("Ingrese la fecha a de nacimiento (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &diaN, &mesN, &anioN);
    printf("Ingrese la fecha actual (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &diaA, &mesA, &anioA);

    if(esFechaValida(diaN, mesN, anioN) && esFechaValida(diaA, mesA, anioA))
    {
        printf("La fecha de nacimiento %02d/%02d/%d es válida.\n", diaN, mesN, anioN);
        printf("La fecha de nacimiento %02d/%02d/%d es válida.\n", diaA, mesA, anioA);
        printf("La edad es %d.", calculaEdad(diaN, mesN, anioN, diaA, mesA, anioA));
    }
    else
        printf("Alguna de las dos fechas no es válida.");

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


int calculaEdad(const int diaN, const int mesN, const int anioN, const int diaA, const int mesA, const int anioA)
{
    if(anioA<anioN)
        return 0;
    if(anioA>=anioN && mesA>=mesN && diaA>=diaN)
        return anioA - anioN;
    else
        return anioA - anioN - 1;
}
