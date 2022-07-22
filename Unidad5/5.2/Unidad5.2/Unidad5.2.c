#ifndef UNIDAD5_2_C_INCLUDED
#define UNIDAD5_2_C_INCLUDED

#include "Unidad5.2.h"


int esValidoIntYCondFin(const void* elem, const void* inf, const void* sup, const void* condFin);
int esValidoIntEntre(const void* elem, const void* inf, const void* sup);
int esValidoIntMayA(const void* elem, const void* inf);
int esValidoIntIntervAbierto(const void* elem, const void* izq, const void* der);
int validaIntEntre(const int inf, const int sup, esValidoEntre valido);
int validaIntMayA(const int inf, esValidoMayA valido);
int validaIntIntervaloAbierto(const int izq, const int der, esValidoIntAbierto valido);
int esValidoFloatMayA(const void* elem, const void* inf);
float validaFloatMayA(const float inf, esValidoMayA valido);
int validaIntEntreYCondFin(const int inf, const int sup, const int condFin, esValidoEntreYCondFin valido);
int esBisiesto(const int anio);
int cantDiasDelMes(const int mes, const int anio);
int esFechaValida(const int dia, const int mes, const int anio);
char validaCharEntreDosOpc(const char comp1, const char comp2);



/*5.2.1 Confeccionar un programa que calcule e informe los valores de las potencias de 2 cuyo resultado sean menores que 600. (1 2 4 8 16 …)*/
int ejercicio52punto1()
{
    int pot=1;

    puts("Ejercicio 5.2.1");
    while(pot<600)
    {
        printf("%d\n", pot);
        pot <<= 1;
    }
    printf("\n");

    return TODO_OK;
}



/*5.2.2 Escribir las sentencias que permitan el ingreso correcto del valor numérico de un día y un mes determinado. Por algún error volver a
solicitar.*/
int ejercicio52punto2()
{
    int mes, dia;
    const int meses[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    puts("Ejercicio 5.2.2");
    printf("Ingrese el mes (1 a 12): ");
    mes = validaIntEntre(1, 12, esValidoIntEntre);
    printf("Ingrese el dia: ");
    if(mes==2)
        dia = validaIntEntre(1, meses[mes-1]+1, esValidoIntEntre);
    else
        dia = validaIntEntre(1, meses[mes-1], esValidoIntEntre);

    printf("El dia y mes ingresados son: %02d/%02d\n\n", dia, mes);

    return TODO_OK;
}



/*5.2.3 Confeccionar un programa que pueda ingresar una secuencia de caracteres hasta que se digite un *. Se desea obtener e informar cuantos
caracteres ingresados son numéricos y cuantos alfabéticos. Estos últimos tienen que mostrarse separados por mayúsculas y minúsculas. También
informar la cantidad de otros símbolos que no sean ni letras ni números.*/
int ejercicio52punto3()
{
    char caracter;
    int contNum = 0, contAlfMin = 0, contAlfMay = 0, contSimbEsp = 0;

    puts("Ejercicio 5.2.3");
    printf("Ingrese un caracter (* para terminar): ");
    fflush(stdin);
    scanf("%c", &caracter);
    fflush(stdin);
    while(caracter != '*')
    {
        if(es_letra_may(caracter))
            contAlfMay++;
        else
        {
            if(es_letra_min(caracter))
            contAlfMin++;
            else
            {
                if(es_numero(caracter))
                    contNum++;
                else
                    contSimbEsp++;
            }
        }
        printf("Ingrese un caracter (* para terminar): ");
        fflush(stdin);
        scanf("%c", &caracter);
        fflush(stdin);
    }
    printf("Se han ingresado %d letras minusculas, %d letras mayusculas, %d numeros y %d caracteres especiales\n\n", contAlfMin, contAlfMay, contNum, contSimbEsp);

    return TODO_OK;
}



/*5.2.4 Un negocio de venta de granos desea controlar las ventas realizadas. De cada una ingresa el importe total y un código que indica la
forma de pago. El código puede ser:
• C: cheque, 20% de recargo.
• E: efectivo, 10% de descuento.
• T: con tarjeta, 12% de recargo.
Se debe ingresar una F para finalizar el día de venta y arrojar los siguientes totales.
Efectivo en Caja:               $ xxxx.xx
Ventas con Tarjeta de Crédito:  $ xxxx.xx
Ventas con cheque:              $ xxxx.xx
Total de Venta:                 $ xxxx.xx
Importe del IVA:                $ xxxx.xx
Nota: El IVA corresponde al 21% del total de ventas.*/
int ejercicio52punto4()
{
    double importe, totEfect = 0, totTarj = 0, totCheq = 0, ventaTotal, iva;
    char cod;

    puts("Ejercicio 5.2.4");
    printf("Ingrese el codigo de forma de pago (E: Efectivo, T: tarjeta de credito, C: cheque , F para finalizar la carga): ");
    do
    {
        fflush(stdin);
        scanf("%c", &cod);
        fflush(stdin);
        cod = toupper(cod);
        if(cod != 'F' && cod != 'C' && cod != 'E' && cod != 'T')
            printf("Se ha ingresado mal el codigo, vuelva a intentar: ");
    } while (cod != 'F' && cod != 'C' && cod != 'E' && cod != 'T');
    while(cod!= 'F')
    {
        printf("Indique el importe pagado (mayor a 0): ");
        importe = validaFloatMayA(0, esValidoFloatMayA);
        if(cod == 'C')
        {
            importe *= 1.2;
            printf("El precio es $%.2f\n", importe);
            totCheq += importe;
        }
        if(cod == 'E')
        {
            importe *= 0.9;
            printf("El precio es $%.2f\n", importe);
            totEfect += importe;
        }
        if(cod == 'T')
        {
            importe *= 1.12;
            printf("El precio es $%.2f\n", importe);
            totTarj += importe;
        }
        printf("Ingrese el codigo de forma de pago (E: Efectivo, T: tarjeta de credito, C: cheque , F para finalizar la carga): ");
        do
        {
            fflush(stdin);
            scanf("%c", &cod);
            fflush(stdin);
            cod = toupper(cod);
            if(cod != 'F' && cod != 'C' && cod != 'E' && cod != 'T')
                printf("Se ha ingresado mal el codigo, vuelva a intentar: ");
        } while (cod != 'F' && cod != 'C' && cod != 'E' && cod != 'T');
    }
    ventaTotal = totTarj + totCheq + totEfect;
    iva = ventaTotal * 0.21;

    printf("%-40s$%.2f\n%-40s$%.2f\n%-40s$%.2f\n%-40s$%.2f\n%-40s$%.2f\nNota: El IVA corresponde al 21%% del total de ventas.\n\n","Efectivo en Caja:", totEfect, "Ventas con Tarjeta de Credito:", totTarj, "Ventas con cheque:", totCheq, "Total de Venta:", ventaTotal, "Importe del IVA:", iva);

    return TODO_OK;
}



/*5.2.5 De cada uno de los alumnos de un curso se ingresa su número de DNI y las notas de los dos exámenes parciales confeccionar, un programa
que muestre por cada alumno su condición final con el siguiente mensaje:
“El alumno con DNI: xxxxxxx, obtuvo las notas: xx y xx [condición final]”
La condición final se establece según las siguientes reglas:
• PROMOCIONA: ambas notas > = 7
• RINDE EXAMEN FINAL: ambas notas > = 4
• REPROBO LA MATERIA: alguna nota no cumple lo anterior
El programa finaliza cuando se ingresa un valor negativo como número de DNI. Al finalizar mostrar la nota promedio de alumnos promocionados.*/
int ejercicio52punto5()
{
    int dni, nota1, nota2, cont = 0;
    float prom = 0, suma = 0;

    puts("Ejercicio 5.2.5");
    printf("Ingrese el DNI del alumno (negativo para terminar): ");
    dni = validaIntIntervaloAbierto(0, 9000000, esValidoIntIntervAbierto);

    while(dni>9000000)
    {
        printf("Ingrese la nota 1 (1 a 10): ");
        nota1 = validaIntEntre(1, 10, esValidoIntEntre);
        printf("Ingrese ela nota 2 (1 a 10): ");
        nota2 = validaIntEntre(1, 10, esValidoIntEntre);
        if(nota1 >= 7 && nota2 >= 7)
        {
            printf("El alumno con DNI: %d, obtuvo las notas: %2d y %2d [PROMOCIONA]\n", dni, nota1, nota2);
            suma += (nota1 + nota2);
            cont += 2;
        }
        else
        {
            if(nota1 >= 4 && nota2 >= 4)
                printf("El alumno con DNI: %d, obtuvo las notas: %2d y %2d [RINDE EXAMEN FINAL]\n", dni, nota1, nota2);
            else
                printf("El alumno con DNI: %d, obtuvo las notas: %2d y %2d [REPROBO LA MATERIA]\n", dni, nota1, nota2);
        }
        printf("Ingrese el DNI del alumno (negativo para terminar): ");
        dni = validaIntIntervaloAbierto(0, 9000000, esValidoIntIntervAbierto);
    }
    if(cont)
        prom = (float)suma / cont;
    printf("\nEl promedio de los alumnos promocionados es %.2f\n\n", prom);

    return TODO_OK;
}


/*5.2.6 Un negocio de perfumería efectúa descuentos en sus ventas según el importe de las mismas, con la siguiente escala:
• menor a 50 pesos el 3.5 %
• entre 50 y 150 pesos el 10 %
• entre 151 y 300 pesos el 20 %.
• mayor a 300 pesos el 25 %
Confeccionar un programa que:
a. Solicite un importe y calcule el descuento a efectuar y el importe neto a cobrar, con mensajes aclaratorios.
b. Informe el importe promedio de todas las ventas realizadas.
Se debe contemplar que se puedan ingresar varios importes y para finalizar se ingresa un valor negativo o cero.*/
int ejercicio52punto6()
{
    float importe, desc, neto, suma=0, prom=0;
    int cont = 0;

    puts("Ejercicio 5.2.6");

    printf("Ingrese el importe de la venta (cero o negativo para terminar): ");
    scanf("%f", &importe);
    fflush(stdin);
    while(importe>0)
    {
        if(importe<50)
            desc = importe * 0.035;
        if(importe>=50 && importe<=150)
            desc = importe * 0.1;
        if(importe>150 && importe<=300)
            desc = importe * 0.2;
        if(importe>300)
            desc = importe * 0.25;

        neto = importe - desc;
        suma += neto;
        cont ++;

        printf("%-20s$%.2f\n%-20s$%.2f\n%-20s$%.2f\n", "Importe: ", importe, "Descuento: ", desc, "Neto: ", neto);

        printf("Ingrese el importe de la venta (cero o negativo para terminar): ");
        scanf("%f", &importe);
        fflush(stdin);
    }
    if(suma)
        prom = suma / cont;

    printf("El promedio de ventas es $%.2f\n\n", prom);

    return TODO_OK;
}



/*5.2.7 Ingresar diversos quintetos de números positivos de 1 cifra c/u, finalizando cuando las cinco cifras leídas sean iguales a cero.
Determinar e informar cuantos de los quintetos ingresados han formado números capicúas 'triples' y cuantos 'quíntuples'.*/
int ejercicio52punto7()
{
    int num1, num2, num3, num4, num5, contTrip = 0, contQuin = 0;

    puts("Ejercicio 5.2.7");
    printf("A continuacion debera proporcionar un quinteto ( para terminar 0 0 0 0 0)\n");
    printf("Ingrese el primer numero (0 a 9): ");
    num1 = validaIntEntre(0, 9, esValidoIntEntre);
    printf("Ingrese el segundo numero (0 a 9): ");
    num2 = validaIntEntre(0, 9, esValidoIntEntre);
    printf("Ingrese el tercer numero (0 a 9): ");
    num3 = validaIntEntre(0, 9, esValidoIntEntre);
    printf("Ingrese el cuarto numero (0 a 9): ");
    num4 = validaIntEntre(0, 9, esValidoIntEntre);
    printf("Ingrese el quinto numero (0 a 9): ");
    num5 = validaIntEntre(0, 9, esValidoIntEntre);

    while(num1 != 0 || num2 != 0 || num3 != 0 || num4 != 0 || num5 != 0)
    {
        if(num1 == num5 && num2 == num4)
            contQuin ++;
        else
        {
            if(num1 == num3)
                contTrip ++;
            if(num2 == num4)
                contTrip ++;
            if(num3 == num5)
                contTrip ++;
        }
        printf("A continuacion debera proporcionar un quinteto ( para terminar 0 0 0 0 0)\n");
        printf("Ingrese el primer numero (0 a 9): ");
        num1 = validaIntEntre(0, 9, esValidoIntEntre);
        printf("Ingrese el segundo numero (0 a 9): ");
        num2 = validaIntEntre(0, 9, esValidoIntEntre);
        printf("Ingrese el tercer numero (0 a 9): ");
        num3 = validaIntEntre(0, 9, esValidoIntEntre);
        printf("Ingrese el cuarto numero (0 a 9): ");
        num4 = validaIntEntre(0, 9, esValidoIntEntre);
        printf("Ingrese el quinto numero (0 a 9): ");
        num5 = validaIntEntre(0, 9, esValidoIntEntre);
    }

    printf("Los quintetos ingresados han formado %d capicuas triples y %d capicuas quintuples\n\n", contTrip, contQuin);

    return TODO_OK;
}



/*5.2.8 Confeccionar un programa que me permita calcular y mostrar una cantidad de números primos que se solicita por la pantalla.
Los números se calculan a partir del 2. Ejemplo: Si ingreso 6, genero los números: 2 – 3 - 5 - 7 - 11 - 13. El algoritmo para el cálculo de si
un número es primo o no, debe estar optimizado para que si encuentra un divisor no seguir buscando ya que se sabe que no es primo.*/
int ejercicio52punto8()
{
    int i=1, j, cantPrim, contDiv, contPrim = 0;

    puts("Ejercicio 5.2.8");

    printf("Ingrese la cantidad de numeros primos a buscar: ");
    cantPrim = validaIntMayA(0, esValidoIntMayA);
    while(contPrim < cantPrim)
    {
        i ++;
        j = 2;
        contDiv = 0;
        while(j<=i/2 && contDiv < 1)
        {
            if(i % j == 0)
                contDiv ++;
            j++;
        }
        if(contDiv==0)
        {
            printf("El numero %d es primo\n", i);
            contPrim ++;
        }
    }
    printf("\n");
    return TODO_OK;
}



/*5.2.9 Se desea realizar un programa para calcular el sueldo final a pagar a cada empleado de una empresa. De cada uno se tiene, sueldo básico,
antigüedad, cantidad de hijos y estudios superiores (‘S’ o ‘N’). Además, se conocen los porcentajes de aumento del sueldo que dependen de los
siguientes factores:
• Si el empleado tiene más de 10 años de antigüedad: aumento del 10%
• Si el empleado tiene más de 2 hijos: aumento del 10%, si solo tiene uno 5%
• Si el empleado posee estudios superiores: aumento del 5%
Luego de ingresar los datos de un empleado se debe preguntar si se desea ingresar otro empleado o no. Se termina la carga cuando no se deseen
ingresar más empleados.
Determinar:
a. Por cada empleado: número de empleado, el sueldo básico y el nuevo sueldo.
b. Sueldo nuevo promedio de la empresa.*/
int ejercicio52punto9()
{
    float sueldoBas, sueldoNuev, sumaSueldNuev = 0, promSuelNuev = 0;
    int antig, contEmp = 0, cantHij;
    char estSup, ingreso = 'S';

    puts("Ejercicio 5.2.9");

    printf("A continuacion se ingresara los datos de los empleados: \n");
    while(ingreso == 'S')
    {
        contEmp ++;
        sueldoNuev = 0;
        printf("Ingrese el sueldo basico del empleado: ");
        sueldoBas = validaFloatMayA(0, esValidoFloatMayA);
        printf("Ingrese la antiguedad en anios del empleado: ");
        antig = validaIntMayA(-1, esValidoIntMayA);
        printf("Ingrese la cantidad de hijos del empleado: ");
        cantHij = validaIntMayA(-1, esValidoIntMayA);
        printf("Indique si el empleados tiene estudios superiores ('S' o 'N'): ");
        do
        {
            fflush(stdin);
            scanf("%c", &estSup);
            estSup = toupper(estSup);
            if(estSup != 'S' && estSup != 'N')
                printf("La opcion ingresada es incorrecta. Debe ser 'S' o 'N'. Vuelva a ingresar: ");
        } while (estSup != 'S' && estSup != 'N');
        sueldoNuev = sueldoBas;
        if(antig>10)
            sueldoNuev += sueldoBas * 0.1;
        if(cantHij>=2)
            sueldoNuev += sueldoBas * 0.1;
        if(cantHij == 1)
            sueldoNuev += sueldoBas * 0.05;
        if(estSup == 'S')
            sueldoNuev += sueldoBas * 0.05;
        printf("El empleado numero %d tiene como sueldo basico $%.2f y como nuevo sueldo $%.2f\n", contEmp, sueldoBas, sueldoNuev);

        sumaSueldNuev += sueldoNuev;

        printf("Desea ingresar un nuevo empleado? ('S' o 'N'): ");
        fflush(stdin);
        scanf("%c", &ingreso);
        ingreso = toupper(ingreso);
    }

    if(sumaSueldNuev)
        promSuelNuev = sumaSueldNuev / contEmp;

    printf("El promedio del nuevo sueldo del total de la empresa es $%.2f\n\n", promSuelNuev);

    return TODO_OK;
}



/*5.2.10 En un proceso de control se evalúan valores de temperatura, finalizando cuando de ingresa un valor ficticio de temperatura -50.
Determinar el valor máximo y mínimo medido y sus posiciones respecto al ingreso.*/
int ejercicio52punto10()
{
    float temp, min = 0, max = 0;
    int posMin = 0, posMax = 0, pos = 1;

    puts("Ejercicio 5.2.10");

    printf("Ingrese la temperatura (-50 para terminar): ");
    temp = validaFloatMayA(-51, esValidoFloatMayA);
    if(temp != -50)
    {
        min = temp;
        max = temp;
        posMax = pos;
        posMin = pos;
    }
    while(temp != -50)
    {
        if(temp<min)
        {
            min = temp;
            posMin = pos;
        }
        if(temp>max)
        {
            max = temp;
            posMax = pos;
        }
        pos ++;
        printf("Ingrese la temperatura (-50 para terminar): ");
        temp = validaFloatMayA(-51, esValidoFloatMayA);
    }
    printf("El valor maximo es %.2f y su posicion de ingreso es %d, el valor minimo es %.2f y su posicion de ingreso es %d\n\n", max, posMax, min, posMin);

    return TODO_OK;
}




/*5.2.11 Se ingresan números enteros, hasta que se ingrese el número cero. Determinar los 2 valores mayores.*/
int ejercicio52punto11()
{
    int num, may1, may2;

    puts("Ejercicio 5.2.11");

    printf("Ingrese un numero entero (cero para terminar): ");
    fflush(stdin);
    scanf("%d", &num);
    fflush(stdin);
    may1 = num;
    may2 = num;
    while(num != 0)
    {
        if(num > may1)                          //busco el mas grande
        {
            may2 = may1;
            may1 = num;
        }
        if(num > may2 && num < may1)            //busco el segundo mas grande
            may2 = num;

        printf("Ingrese un numero entero (cero para terminar): ");
        fflush(stdin);
        scanf("%d", &num);
        fflush(stdin);
    }

    printf("El valor mas grande es %d y el segundo mas grande es %d\n\n", may1, may2);
    return TODO_OK;
}




/*5.2.12 Confeccionar un programa que permita el ingreso de 6 ternas de valores enteros.
a. de cada terna informar el mayor valor y su orden en la terna.
b. de cada terna informar cuantos valores son múltiplos de 7.
c. de las 6 ternas determinar e informar el promedio de los primeros valores de cada una.*/
int ejercicio52punto12()
{
    int num, j, i, mayor, pos, contMult7, sumaPrimVal = 0;
    float prom = 0;

    puts("Ejercicio 5.2.12");
    for(i=0; i<6; i++)
    {
        contMult7 = 0;
        for(j=1; j<=3; j++)
        {
            printf("Ingrese el %d numero entero: ", j);
            fflush(stdin);
            scanf("%d", &num);
            fflush(stdin);

            if(j==1)
            {
                mayor = num;
                pos = j;
                sumaPrimVal += num;
            }

            if(num>mayor)
            {
                mayor = num;
                pos = j;
            }

            if(num % 7 == 0)
                contMult7 ++;
        }
        printf("El mayor de esta terna es el %d, esta en la posicion %d y la misma tiene %d multiplos de 7\n", mayor, pos, contMult7);
    }
    if(sumaPrimVal)
        prom = sumaPrimVal / 6.0;

    printf("El promedio de los primeros valores de cada terna es %.2f\n\n", prom);

    return TODO_OK;
}




/*5.2.13 Realizar un programa que le solicite al usuario el ingreso de una vocal (este dato de ingreso se debe validar). Luego el programa debe
dibujar en pantalla la vocal ingresada en cinco líneas y cuatro columnas. La vocal debe estar formada en cada carácter por la misma letra en
mayúscula.
El programa finaliza al ingresar la letra f.
Restricciones: Por cada printf se debe exhibir un solo carácter o salto de línea o espacio.
Ejemplos:
Ingreso del carácter a:
AAAA
A  A
AAAA
A  A
A  A
Ingreso del carácter e:
EEEE
E
EEEE
E
EEEE
Extender el programa para que la vocal se exhiba más grande ingresando un factor de multiplicación. Por ejemplo si se ingresa un 2 debe
dibujarse el doble de grande la letra en pantalla.*/
int ejercicio52punto13()
{
    char vocal, i, j;
    int fact;

    puts("Ejercicio 5.2.13");

    do
    {
        printf("Ingrese una vocal o la letra f para terminar: ");
        fflush(stdin);
        scanf("%c", &vocal);
        vocal = toupper(vocal);

        if(!es_vocal_may(vocal))
            printf("El caracter ingresado no es una vocal ni la f.\n");
    } while (!es_vocal_may(vocal) && vocal != 'F');
    while(vocal != 'F')
    {
        printf("Escriba el factor de multiplicacion: ");
        fact = validaFloatMayA(0, esValidoFloatMayA);
        for(i=1; i<=5*fact; i++)
        {
            for(j=1; j<=4*fact; j++)
            {
                if(vocal == 'A')
                {
                    if(i<=fact || (i>=3*fact && i<4*fact))
                        printf("A");
                    else
                    {
                        if(j<=fact || j>3*fact)
                            printf("A");
                        else
                            printf(" ");
                    }
                }
                if(vocal == 'E')
                {
                    if(i<=fact || (i>2*fact && i<=3*fact) || i>4*fact)
                        printf("E");
                    else
                    {
                        if(j<=fact)
                            printf("E");
                        else
                            printf(" ");
                    }
                }
                if(vocal == 'I')
                {
                    if(i<=fact || i>4*fact)
                        printf("I");
                    else
                    {
                        if(j>fact && j<=3*fact)
                            printf("I");
                        else
                            printf(" ");
                    }
                }
                if(vocal == 'O')
                {
                    if(i<=fact || i>4*fact)
                        printf("O");
                    else
                    {
                        if(j<=fact || j>3*fact)
                            printf("O");
                        else
                            printf(" ");
                    }
                }
                if(vocal == 'U')
                {
                    if(i>4*fact)
                        printf("U");
                    else
                    {
                        if(j<=fact || j>3*fact)
                            printf("U");
                        else
                            printf(" ");
                    }
                }
            }
            printf("\n");
        }
        do
        {
            printf("Ingrese una vocal o la letra f para terminar: ");
            fflush(stdin);
            scanf("%c", &vocal);
            vocal = toupper(vocal);

            if(!es_vocal_may(vocal))
                printf("El caracter ingresado no es una vocal ni la f.\n");
        } while (!es_vocal_may(vocal) && vocal != 'F');
    }
    printf("\n\n");
    return TODO_OK;
}


/*5.2.14 Se ingresan datos de los empleados de una empresa. Por cada empleado se ingresa:
• Legajo (entero entre 1000 y 5000)
• Sueldo básico (float mayor a 1000)
• Antigüedad en años (mayor o igual a 0)
• Sexo (‘M' o 'F')
• Categoría (entero entre 1 a 5)
Por cada empleado ingresado se debe calcular el sueldo final a abonar sabiendo que:
• Las Categorías 2 y 3 tienen $500 de bonificación.
• La Categoría 4 tiene 10% de bonificación.
• La Categoría 5 tiene 30% de bonificación.
• Si la antigüedad es mayor a 10 años recibe una bonificación del 10% adicional.
Todos los datos ingresados deben ser validados. El ingreso finaliza con un legajo igual a cero.
Informar:
• El sueldo a abonar a cada empleado.
• Cantidad de empleados de más de 10 años de antigüedad.
• El mayor sueldo y el legajo del empleado que cobra dicho sueldo.
• Cantidad de hombres y de mujeres.*/
int ejercicio52punto14()
{
    int leg = 0, antig, cat, cantMasDe10 = 0, cantH = 0, cantM = 0, legMay;
    float sueldo, mayorSuel, sueldoF, bonif, bonifExtra;
    char sexo;

    puts("Ejercicio 5.2.14");

    printf("Ingrese el numero de legajo (entre 1000 y 5000 o 0 para terminar): ");
    leg = validaIntEntreYCondFin(1000, 5000, 0, esValidoIntYCondFin);
    while(leg != 0)
    {
        bonifExtra = 0;
        bonif = 0;
        printf("Ingrese el sueldo basico del empleado(mayor a 1000): ");
        sueldo = validaFloatMayA(1000, esValidoFloatMayA);
        printf("Ingrese los anios de antiguedad del empleado (mayor o igual a 0): ");
        antig = validaIntMayA(-1, esValidoIntMayA);
        do
        {
            if(!cantH && !cantM)
            {
                mayorSuel = sueldo;
                legMay = leg;
            }
            else
            {
                if(sueldo>mayorSuel)
                {
                    mayorSuel = sueldo;
                    legMay = leg;
                }
            }
            printf("Ingrese el sexo del empleado (M o F): ");
            fflush(stdin);
            scanf("%c", &sexo);
            sexo = toupper(sexo);
            if(sexo != 'F' && sexo != 'M')
                printf("El sexo debe especificarse con M o con F. Vuelva a intentar.\n");
        } while(sexo != 'F' && sexo != 'M');
        printf("Ingrese la categoria del empleado (1 a 5): ");
        cat = validaIntEntre(1, 5, esValidoIntEntre);

        if(cat == 2 || cat == 3)
            bonif = 500;
        if(cat == 4)
            bonif = sueldo * 0.1;
        if(cat == 5)
            bonif = sueldo * 0.3;
        if(antig>10)
        {
            bonifExtra = sueldo * 0.1;
            cantMasDe10 ++;
        }
        if(sexo == 'M')
            cantM ++;
        else
            cantH ++;

        sueldoF = sueldo + bonif + bonifExtra;

        printf("El sueldo final del empleado de legajo %d es $%.2f\n", leg, sueldoF);

        printf("Ingrese el numero de legajo (entre 1000 y 5000 o 0 para terminar): ");
        leg = validaIntEntreYCondFin(1000, 5000, 0, esValidoIntYCondFin);
    }
    if(cantH || cantM)
    {
        printf("La cantidad de empleados de mas de diez anios de antiguedad es: %d\n", cantMasDe10);
        printf("El mayor sueldo es $%.2f y el legajo correspondiente a ese sueldo es %d\n", mayorSuel, legMay);
        printf("Se han ingresado %d hombres y %d mujeres\n\n", cantH, cantM);
    }
    else
        printf("No se han ingresado datos\n\n");

    return TODO_OK;
}


/*5.2.15 El gobierno de la Ciudad de Buenos Aires realiza una encuesta a los estudiantes de los colegios secundarios. Los primeros datos a
ingresar son la fecha (día, mes y año) y la cantidad de colegios de la ciudad en que se realizó la encuesta.
De cada colegio se conoce: número de escuela, la cantidad de alumnos inscriptos y la especialidad (‘T’: técnico, ‘N’: no técnico).
De cada alumno del colegio que respondió la encuesta se conoce: DNI, fecha de nacimiento (día, mes y año), sexo (‘M’ o ‘F’), opinión con
respecto a los conocimientos adquiridos (‘B’: buenos, ‘M’: malos). Se identifica el fin de ingreso de datos de los alumnos que respondieron la
encuesta por cada colegio con ingreso 0 en el DNI del estudiante.
Validar todos los datos que se ingresan por teclado.
Informar:
a. Por cada colegio, el porcentaje de alumnos que contestaron la encuesta sobre la cantidad de alumnos inscriptos del colegio.
b. Cantidad de estudiantes de colegio no técnicos que respondieron la encuesta.
c. Porcentaje de mujeres de escuelas técnicas sobre la cantidad de estudiantes que respondieron la encuesta.
d. Porcentaje de estudiantes que respondieron que los conocimientos adquiridos eran malos, sobre el total de encuestados.
e. Mayor edad de los estudiantes encuestados.
f. Número del colegio con mayor opinión buena sobre los conocimientos adquiridos.*/
int ejercicio52punto15()
{
    int i, dia, mes, anio, cantCol, numEsc, cantAlum, dni, diaNac, mesNAc, anioNac, edad, contAl, contTot = 0, contAlNoTec = 0, contMujEscTec = 0, mayEdad = 0, numEscMayPos = 0, contBuenaOp, mayOpBuen = 0, contMalaOp = 0;
    char espec, sexo, opinion;
    booleano fechaValida;

    puts("Ejercicio 5.2.15");

    do
    {
        printf("Ingrese la fecha actual (dd/mm/aaaa): ");
        fflush(stdin);
        scanf("%d/%d/%d", &dia, &mes, &anio);
        fflush(stdin);
        fechaValida = esFechaValida(dia, mes, anio);
        if(!fechaValida)
            printf("La fecha ingresada no es valida. Vuelva a ingresar.\n");
    } while (!fechaValida);
    printf("Ingrese la cantidad de colegios que se encuestaron: ");
    cantCol = validaIntMayA(0, esValidoIntMayA);

    for(i=0; i<cantCol; i++)
    {
        contBuenaOp = 0;
        contAl = 0;
        printf("Colegio ingresado numero %d:\n", i+1);
        printf("Ingrese el numero de escuela: ");
        numEsc = validaIntMayA(0, esValidoIntMayA);
        printf("Ingrese la cantidad de alumnos inscriptos: ");
        cantAlum = validaIntMayA(0, esValidoIntMayA);
        printf("Ingrese la modalidad de la escuela ('T': tecnico, 'N': no tecnico): ");
        espec = validaCharEntreDosOpc('T', 'N');

        puts("A continuacion se ingresaran los alumnos encuestados: ");
        printf("Ingrese el numero de DNI del alumno (cero para terminar): ");
        dni = validaIntMayA(-1, esValidoIntMayA);
        while(dni != 0)
        {
            contTot ++;
            do
            {
                printf("Ingrese fecha de nacimiento (dd/mm/aaaa): ");
                fflush(stdin);
                scanf("%d/%d/%d", &diaNac, &mesNAc, &anioNac);
                fflush(stdin);
                fechaValida = esFechaValida(diaNac, mesNAc, anioNac);
                if(!fechaValida || (anioNac > anio || ( anioNac == anio && mesNAc > mes) || (anioNac == anio && mesNAc == mes && diaNac > dia) ))
                    printf("La fecha ingresada no es valida. Vuelva a ingresar.\n");
            } while (!fechaValida);
            printf("Ingrese sexo del alumnos ('M' o 'F'): ");
            sexo = validaCharEntreDosOpc('M', 'F');
            printf("Indique la opinion con respecto a los conocimientos adquiridos ('B': buenos, 'M': malos): ");
            opinion = validaCharEntreDosOpc('B', 'M');

            contAl ++;
            if(espec == 'N')
                contAlNoTec ++;
            if(espec == 'T' && sexo == 'F')
                contMujEscTec ++;
            if(mesNAc>mes || (mesNAc == mes && diaNac > dia))
                edad = anio - anioNac - 1;
            else
                edad = anio - anioNac;
            if(edad>mayEdad)
                mayEdad = edad;
            if(opinion == 'B')
                contBuenaOp ++;
            else
                contMalaOp ++;

            printf("Ingrese el numero de DNI del alumno (cero para terminar): ");
            dni = validaIntMayA(-1, esValidoIntMayA);
        }
        if(contBuenaOp>mayOpBuen)
        {
            mayOpBuen = contBuenaOp;
            numEscMayPos = numEsc;
        }
        printf("El porcentaje de alumnos que respondieron la encuesta sobre el total de inscriptos del colegio %d es: %.2f %%\n", numEsc, (float)contAl / cantAlum *100);
    }
    printf("La cantidad de estudiantes de colegios no tecnicos que resolvieron la encuesta es %d\n", contAlNoTec);
    printf("El porcentaje de mujeres de escuelas tecnicas sobre la cantidad de estudiantes que respondieron la encuesta es %.2f %%\n", (float) contMujEscTec / contTot * 100);
    printf("El porcentaje de estudiantes que respondieron que los conocimientos adquiridos eran malos, sobre el total de encuestados es %.2f %%\n", (float) contMalaOp / contTot * 100);
    printf("La mayor edad de los estudiantes encuestados es %d\n", mayEdad);
    printf("El numero del colegio con mayor opinion buena sobre los conocimientos adquiridos es %d\n\n", numEscMayPos);

    return TODO_OK;
}

int esValidoIntEntre(const void* elem, const void* inf, const void* sup)
{
    return (*(int*)elem >= *(int*)inf && *(int*)elem <= *(int*)sup);
}



int validaIntEntre(const int inf, const int sup, esValidoEntre valido)
{
    int num;
    booleano esValido;

    do
    {
        fflush(stdin);
        scanf("%d", &num);
        fflush(stdin);
        esValido = valido(&num, &inf, &sup);
        if(!esValido)
            printf("El numero ingresado no es valido. Debe estar entre %d y %d. Vuelva a ingresar: ", inf, sup);
    } while(!esValido);

    return num;
}


int esValidoIntMayA(const void* elem, const void* inf)
{
    return *(int*)elem > *(int*)inf;
}

int validaIntMayA(const int inf, esValidoMayA valido)
{
    int num;
    booleano esValido;

    do
    {
        fflush(stdin);
        scanf("%d", &num);
        fflush(stdin);
        esValido = valido(&num, &inf);
        if(!esValido)
            printf("El numero ingresado no es valido. Debe ser mayor a %d. Vuelva a ingresar: ", inf);
    } while(!esValido);

    return num;
}

int esValidoFloatMayA(const void* elem, const void* inf)
{
    return *(float*)elem > *(float*)inf;
}

float validaFloatMayA(const  float inf, esValidoMayA valido)
{
    float num;
    booleano esValido;

    do
    {
        fflush(stdin);
        scanf("%f", &num);
        fflush(stdin);
        esValido = valido(&num, &inf);
        if(!esValido)
            printf("El numero ingresado no es valido. Debe ser mayor a %.2f. Vuelva a ingresar: ", inf);
    } while(!esValido);

    return num;
}


int esValidoIntIntervAbierto(const void* elem, const void* izq, const void* der)
{
    return (*(int*)elem < *(int*)izq || *(int*)elem > *(int*)der);
}

int validaIntIntervaloAbierto(const int izq, const int der, esValidoIntAbierto valido)
{
    int num;
    booleano esValido;

    do
    {
        fflush(stdin);
        scanf("%d", &num);
        fflush(stdin);
        esValido = valido(&num, &izq, &der);
        if(!esValido)
            printf("El numero ingresado no es valido. Debe debe ser menor a %d y mayor a %d. Vuelva a ingresar: ", izq, der);
    } while(!esValido);

    return num;
}


int esValidoIntYCondFin(const void* elem, const void* inf, const void* sup, const void* condFin)
{
    return ( *(int*)elem >= *(int*)inf || *(int*)elem <= *(int*)sup || *(int*)elem == *(int*)condFin );
}


int validaIntEntreYCondFin(const int inf, const int sup, const int condFin, esValidoEntreYCondFin valido)
{
    int num;
    booleano esValido;

    do
    {
        fflush(stdin);
        scanf("%d", &num);
        fflush(stdin);
        esValido = valido(&num, &inf, &sup, &condFin);
        if(!esValido)
            printf("El numero ingresado no es valido. Debe estar entre %d y %d o %d para terminar. Vuelva a ingresar: ", inf, sup, condFin);
    } while(!esValido);

    return num;
}


int esBisiesto(const int anio)
{
    return (anio % 400 == 0 || (anio % 4 == 0 && anio % 100 != 0));
}


int cantDiasDelMes(const int mes, const int anio)
{
    const int diasXMEs [12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int bisiesto;

    bisiesto = esBisiesto(anio);
    if(mes==2)
        return diasXMEs[mes-1] + bisiesto;

    return diasXMEs[mes-1];
}


int esFechaValida(const int dia, const int mes, const int anio)
{
    return anio >= 1601 && (mes >= 1 && mes <= 12) && (dia >= 1 && dia <= cantDiasDelMes(mes, anio));
}


char validaCharEntreDosOpc(const char comp1, const char comp2)
{
    char caracter;

    do
    {
        fflush(stdin);
        scanf("%c", &caracter);
        caracter = toupper(caracter);
        if(caracter != comp1 && caracter != comp2)
            printf("El caracter ingresado debe ser igual a %c o a %c. Vuelva a intentarlo: ", comp1, comp2);
    } while (caracter != comp1 && caracter != comp2);

    return caracter;
}

#endif // UNIDAD5_2_C_INCLUDED
