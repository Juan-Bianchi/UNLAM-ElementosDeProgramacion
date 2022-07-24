/*6.6. Confeccionar un programa que permita determinar e informar en cuántos de los números enteros comprendidos entre 10001 y 90009 existen más
cifras 3 que 4. Debe existir por lo menos, un 4 para que sea considerado el número como válido. Para resolverlo confeccionar una función llamada
CIFRAS, que pueda determinar cuántas cifras “n” existen en un número de 5 cifras.*/

#define TODO_OK 0
#include<stdio.h>
#include<locale.h>

int cifras(const int num, const int n);


int main()
{
    int n1 = 3, n2 = 4, cont = 0, i;

    setlocale(LC_ALL, "spanish");

    for(i=10001; i<=90009; i++)
    {
        if(cifras(i, n1))
        {
            if(cifras(i,n1)<cifras(i,n2))
            {
                cont ++;
                printf("Numero %d\n", i);
            }
        }
    }

    printf("Entre 10001 y 90009 existen %d numeros con mas cantidad de digitos 4 que digitos 3\n\n", cont);

    return TODO_OK;
}

int cifras(const int num, const int n)
{
    int decMil, unMil, cent, dec, un, cont = 0;

    decMil = num / 10000;
    unMil = (num % 10000) / 1000;
    cent = (num % 1000) / 100;
    dec = (num % 100) / 10;
    un = num  % 10;

    if(decMil == n)
        cont ++;
    if(unMil == n)
        cont ++;
    if(cent == n)
        cont ++;
    if(dec == n)
        cont ++;
    if(un == n)
        cont ++;

    return cont;
}
