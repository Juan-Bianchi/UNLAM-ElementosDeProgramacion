/*6.12. Realizar una función que permita restar 1 día a una fecha válida mostrando la fecha resultante. Si la fecha recibida no es válida
informarlo con un mensaje (validar utilizando la función del punto 9).*/

#include<stdio.h>
#include<locale.h>

int esBisiesto(const int anio);
int cantDiasDelMes(const int mes, const int anio);
int esFechaValida(const int dia, const int mes, const int anio);
void restaUnDiaAFecha(int* dia, int* mes, int* anio);

int main()
{
    int dia, mes, anio;

    setlocale(LC_ALL, "spanish");

    printf("Ingrese la fecha a verificar (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &dia, &mes, &anio);

    if(esFechaValida(dia, mes, anio))
    {
        printf("La fecha %02d/%02d/%d es válida.\n", dia, mes, anio);
        restaUnDiaAFecha(&dia, &mes, &anio);
        printf("La nueva fecha es %02d/%02d/%d.", dia, mes, anio);
    }
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


void restaUnDiaAFecha(int* dia, int* mes, int* anio)
{
    *dia = *dia - 1;
    if(*dia < 1)
    {
        *mes -= 1;
        if(*mes<1)
        {
            *mes = 12;
            *anio -= 1;
        }
        *dia = cantDiasDelMes(*mes, *anio);
    }
}

