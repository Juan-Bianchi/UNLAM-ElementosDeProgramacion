#include<stdio.h>
#include<string.h>
#include<math.h>
#include "Unidad2.h"

booleano esValidoInt(const void* num, const void* inf, const void* sup);
booleano esValidoIntMay(const void* num, const void* inf);
booleano esValidoFloatMay(const void* num, const void* inf);

int validaIntEntre(const int inf, const int sup, ValidaNumEntre validaEntre);
float validaFloatMayorA(const float inf, ValidaNumMayorA validaMayorA);
int validaIntMayA(const int inf, ValidaNumMayorA);
int descomposRecursiva(int suma);




/*2.1. Se ingresan la cantidad de horas trabajadas y el valor por hora de un empleado. Determinar el sueldo.*/
int ej2punto1()
{
    int ht, minHor = 0;
    float vh, minSuel = 0;
    booleano esValido;

    puts("Ejercicio 2.1");
    do
    {
        printf("Ingrese la cantidad de horas trabajadas: ");
        scanf("%d", &ht);
        esValido = esValidoIntMay(&ht, &minHor);
        if(!esValido)
            puts("Valor no valido.");
    }
    while(!esValido);

    do
    {
        printf("Ingrese el valor hora de sueldo: ");
        scanf("%f", &vh);
        esValido = esValidoIntMay(&vh, &minSuel);
        if(!esValido)
            puts("Valor no valido.");
    }
    while(!esValido);

    printf("El sueldo a pagar es: %.2f\n\n", vh*ht);

    return TODO_OK;
}


/*2.2. Se ingresan las notas de dos evaluaciones de un alumno. Determinar la nota promedio.*/
int ej2punto2()
{
    int n1, n2, inf = 1, sup = 10;
    float prom;

    puts("Ejercicio 2.2");
    printf("Ingrese la primer nota (entero de 1 a 10): ");
    n1 = validaIntEntre(inf, sup, esValidoInt);
    printf("Ingrese la segunda nota (entero de 1 a 10): ");
    n2 = validaIntEntre(inf, sup, esValidoInt);

    prom = (n1 + n2) / 2.0;

    printf("El promedio es %.2f\n\n", prom);

    return TODO_OK;
}


/*2.3. Confeccionar un programa que pueda ingresar 2 números enteros y calcule e informe con mensajes aclaratorios la suma, el producto,
el cociente y el resto.*/
int ej2punto3()
{
    int n1, n2, suma, prod, cocient, resto;

    puts("Ejercicio 2.3");
    printf("Ingrese el primer numero entero: ");
    fflush(stdin);
    scanf("%d", &n1);
    fflush(stdin);
    printf("Ingrese el segundo numero entero: ");
    scanf("%d", &n2);
    fflush(stdin);

    suma = n1 + n2;
    prod = n1 * n2;

    if(n1)
    {
        cocient = n1 / n2;
        resto = n1 % n2;
    }
    else
        cocient = resto = 0;

    printf("La suma es %d, el producto es %d, el cociente es %d y el resto es %d\n\n", suma, prod, cocient, resto);

    return TODO_OK;
}


/*2.4. Confeccionar un programa que ingrese una medida en ‘pies’ y la exhiba convertida a yardas, pulgadas, cms. y mts.
NOTA: 1 pie = 12 pulgadas; 1 yarda = 3 pies; 1 pulgada = 2,54 cms.*/
int ej2punto4()
{
    float pies, yardas, pulgadas, cms, mts;

    puts("Ejercicio 2.4");
    printf("Ingrese la cantidad de pies (mayor a 0): ");
    pies = validaFloatMayorA(0, esValidoFloatMay);

    pulgadas = pies * 12;
    yardas = pies / 3;
    cms = pulgadas * 2.54;
    mts = cms / 100;

    printf("            Pies = %.2f\n\
            Yardas = %.2f\n\
            Cms = %.2f\n\
            Mts = %.2f\n\n", pies, yardas, cms, mts);

    return TODO_OK;
}



/*2.5. Conociendo la cantidad de tarros de pintura que existe en un depósito de una pinturería y sabiendo que el 50% son tarros de 1Lt,
el 30% tarros de 4Lts. y el resto tarros de 20Lts. Determinar la cantidad de tarros de 1Lt., 4Lts. Y 20 Lts.*/
int ej2punto5()
{
    int cantTarr, tar4Lts, tar1Lts, tar20Lts;

    puts("Ejercicio 2.5");
    printf("Ingrese la cantidad de tarros totales en el deposito (mayor a 0): ");
    cantTarr = validaIntMayA(1, esValidoIntMay);
    tar1Lts = cantTarr * 0.5;
    if(tar1Lts>1)
        tar4Lts = cantTarr * 0.3;
    else
        tar4Lts = 0;
    tar20Lts = cantTarr - (tar1Lts + tar4Lts);

    printf("            La cantidad total de tarros es: %d\n\n\
           La cantidad de tarros de un litro es %d\n\
           La cantidad de tarros de 4 litros es %d\n\
           La cantidad de tarros de 20 litros es %d\n\n", cantTarr, tar1Lts, tar4Lts, tar20Lts);

    return TODO_OK;
}


/*2.6. El precio para un vuelo es de $8800 en clase turista y se aplica un incremento del 30% en primera clase. Se ingresan la cantidad de
pasajes vendidos de clase turista y de primera clase. Obtener la recaudación total del vuelo.*/
int ej2punto6()
{
    int cantVT, cantPC;
    float precio = 8800, recTot;

    puts("Ejercicio 2.6");
    printf("Ingrese el numero de pasajes vendidos para la clase turista: ");
    cantVT = validaIntMayA(1, esValidoIntMay);

    printf("Ingrese el numero de pasajes vendidos para la primera clase: ");
    cantPC = validaIntMayA(1, esValidoIntMay);

    recTot = precio * cantVT + precio * cantPC * 1.3;

    printf("La recaudacion total fue de $%.2f\n\n", recTot);

    return TODO_OK;
}


/*2.7. Se ingresa un número entero de 3 cifras. Descomponerlo en unidad, decena y centena.*/
int ej2punto7()
{
    int num, u, d, c;

    puts("Ejercicio 2.5");
    printf("Ingrese un numero de 3 cifras (100 a 999): ");
    num = validaIntEntre(100, 999, esValidoInt);
    c = num / 100;
    d = (num % 100) / 10;
    u = num % 10;

    printf("            Numero: %d\n\n\
           Unidad: %d\n\
           Decena: %d\n\
           Centena: %d\n\n", num, u, d, c);

    return TODO_OK;
}


/*2.8. Se ingresa un número entero que representa una fecha con formato (ddmmaa). Se pide transformarlo a un número con formato (aammdd).*/
int ej2punto8()
{
    int numFech, dias, mes, anio;

    puts("Ejercicio 2.8");
    printf("Ingrese una fecha con el formato ddmmaa: ");
    numFech = validaIntEntre(10100, 311299, esValidoInt);

    dias = numFech / 10000;
    mes = (numFech % 10000) / 100;
    anio = numFech % 100;

    printf("La fecha original con formato ddmmaa: %06d\nLa nueva fecha con formato aammdd: %02d%02d%02d\n\n", numFech, anio, mes, dias);

    return TODO_OK;
}


/*2.9. Confeccionar un programa que ingrese un valor expresado en Kibibyte (KiB)1 y lo informe expresado en: TiB, GiB, MiB, con leyendas
aclaratorias. (1MiB = 1024 KiB; 1GiB = 1024 MiB; 1TiB = 1024 GiB)*/
int ej2punto9()
{
    double kilo, mega, giga, tera;

    puts("Ejercicio 2.9");
    printf("Ingrese la cantidad de Kibibytes (mayor a 0): ");
    kilo = validaIntMayA(0, esValidoIntMay);

    mega = kilo / 1024;
    giga = mega / 1024;
    tera = giga / 1024;

    printf("El valor ingresado en Kib es: %f, en Mib es: %f, en Gib es: %f, en Tib es: %f\n\n", kilo, mega, giga, tera);

    return TODO_OK;
}



/*2.10. Confeccionar un programa que solicite el ingreso del valor del radio (r) de un círculo y con dicho valor calcule la superficie del
círculo, la longitud de la circunferencia (perímetro) y el volumen de la esfera.
Superficie = PI * r^2
Perimetro = 2 * PI * r
Volumen = 4/3 * PI * r^3*/
int ej2punto10()
{
    double radio, sup, per, vol;

    puts("Ejercicio 2.10");
    printf("Ingrese el valor del radio del circulo (mayor a 0): ");
    radio = validaFloatMayorA(1, esValidoFloatMay);
    sup = M_PI * pow(radio, 2);
    per = 2 * M_PI * radio;
    vol = 4 * M_PI * pow(radio, 3) / 3;

    printf("El valor del radio del circulo es %.2f, la superficie es %f, el perimetro es %f y el volumen es %f\n\n", radio, sup, per, vol);

    return TODO_OK;
}


/*2.11. Una pizzería vende empanadas por unidad o por docena, la docena cuesta $300 pero si se compra individualmente se cobra $30 la unidad.
Si se compran más empanadas que no se agrupen en docenas las adicionales se cobran como por unidad. Indicar el precio total a abonar.*/
int ej2punto11()
{
    int cantEmp, doce, uni;

    puts("Ejercicio 2.11");
    printf("Ingrese la cantidad de empanadas pedidas (mayor a 0): ");
    cantEmp = validaIntMayA(0, esValidoIntMay);

    doce = cantEmp / 12.0;
    uni = cantEmp % 12;

    printf("El monto a abonar es %.2f\n\n", doce * 300.0 + uni * 30);

    return TODO_OK;
}


/*2.12. Una farmacia vende algunos artículos sin descuento y a otros con descuento del 20%. Confeccionar un programa que recibiendo el precio
original y un código que indica si es o no con descuento, informe el precio final (0 no aplica el descuento y 1 aplica el descuento).*/
int ej2punto12()
{
    int cod;
    float precio;

    puts("Ejercicio 2.12");
    printf("Ingrese el precio del articulo (mayor a 0): ");
    precio = validaFloatMayorA(0, esValidoFloatMay);
    printf("Indique si se debe aplicar el descuento del 20%% (0: NO   1: SI): ");
    cod = validaIntEntre(0,1, esValidoInt);
    if(cod == 1)
        precio *= 0.8;

    printf("El precio del producto es: $%.2f\n\n", precio);

    return TODO_OK;
}


/*2.13. Confeccionar un programa que solicite el ingreso de un número entero positivo de 4 cifras y pueda calcular e informar la suma de sus
dígitos hasta llegar a una sola cifra. Ej:2561 -> 5.*/
int ej2punto13()
{
    int num, uMil, cent, dec, un, suma;

    puts("Ejercicio 2.13");
    printf("Por favor ingrese el numero para realizar el procedimiento: ");
    num = validaIntEntre(1000, 9999, esValidoInt);

    uMil = num / 1000;
    cent = num % 1000 / 100;
    dec = num % 100 / 10;
    un = num % 10;

    suma = descomposRecursiva(uMil + cent + dec + un);

    printf("La suma de digitos es: %d", suma);
    return TODO_OK;
}

int descomposRecursiva(int suma)
{
    int d, u;

    if(suma/10 == 0)
        return suma;

    d = suma / 10;
    u = suma % 10;

    suma = d + u;
    return descomposRecursiva(suma);
}

int validaIntEntre(const int inf, const int sup, ValidaNumEntre validaNum)
{
    int num;
    booleano esValido;

    do
    {
        fflush(stdin);
        scanf("%d", &num);
        esValido = validaNum(&num, &inf, &sup);
        if(!esValido)
            printf("El valor ingresado debe estar entre %d y %d. Vuelva a ingresar: ", inf, sup);
    }
    while (!esValido);

    return num;
}


int validaIntMayA(const int inf, ValidaNumMayorA validaMay)
{
    int num;
    booleano esValido;

    do
    {
        scanf("%d", &num);
        esValido = validaMay(&num, &inf);
        if(!esValido)
            printf("El valor ingresado debe ser mayor a %d. Vuelva a ingresar: ", inf);
    }
    while (!esValido);

    return num;
}


float validaFloatMayorA(const float inf, ValidaNumMayorA validaMayorA)
{
    float num;
    booleano esValido;

    do
    {
        scanf("%f", &num);
        esValido = validaMayorA(&num, &inf);
        if(!esValido)
            printf("El valor ingresado debe ser mayor a %.2f. Vuelva a ingresar: ", inf);
    }
    while (!esValido);

    return num;
}


booleano esValidoInt(const void* num, const void* inf, const void* sup)
{
    return (*(int*)num >= *(int*)inf && *(int*)num <= *(int*)sup);
}


booleano esValidoIntMay(const void* num, const void* inf)
{
    return (*(int*)num >= *(int*)inf);
}

booleano esValidoFloatMay(const void* num, const void* inf)
{
    return (*(float*)num >= *(float*)inf);
}
