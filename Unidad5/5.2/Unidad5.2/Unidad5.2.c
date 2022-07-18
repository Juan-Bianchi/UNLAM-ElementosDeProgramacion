#ifndef UNIDAD5_2_C_INCLUDED
#define UNIDAD5_2_C_INCLUDED

#include "Unidad5.2.h"


int esValidoIntEntre(const void* elem, const void* inf, const void* sup);
int esValidoIntMayA(const void* elem, const void* inf);
int esValidoIntIntervAbierto(const void* elem, const void* izq, const void* der);
int validaIntEntre(const int inf, const int sup, esValidoEntre valido);
int validaIntMayA(const int inf, esValidoMayA valido);
int validaIntIntervaloAbierto(const int izq, const int der, esValidoIntAbierto valido);
int esValidoFloatMayA(const void* elem, const void* inf);
float validaFloatMayA(const float inf, esValidoMayA valido);




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

    printf("El dia y mes ingresados son: %2d/%02d\n\n", dia, mes);

    return TODO_OK;
}



/*5.2.3 Confeccionar un programa que pueda ingresar una secuencia de caracteres hasta que se digite un *. Se desea obtener e informar cuantos
caracteres ingresados son numéricos y cuantos alfabéticos. Estos últimos tienen que mostrarse separados por mayúsculas y minúsculas. También
informar la cantidad de otros símbolos que no sean ni letras ni números.*/
int ejercicio52punto3()
{
    char caracter;
    int contNum = 0, contAlfMin = 0, contAlfMay = 0, contSimbEsp = 0;

    printf("Ingrese un caracter: ");
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
        printf("Ingrese un caracter: ");
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
int ejercicio52punto1()
{
    double importe, totEfect = 0, totTarj = 0, totCheq = 0, ventaTotal, iva;
    char cod;

    puts("Ejercicio 5.2.4");
    printf("Ingrese el codigo de forma de pago (F para finalizar la carga): ");
    do
    {
        fflush(stdin);
        scanf("%c", &cod);
        fflush(stdin);
        cod = toupper(cod);
    } while (cod != 'F' || cod != 'C' || cod != 'E' || cod != 'T');
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
        printf("Ingrese el codigo de forma de pago (F para finalizar la carga): ");
        do
        {
            fflush(stdin);
            scanf("%c", &cod);
            fflush(stdin);
            cod = toupper(cod);
        } while (cod != 'F' || cod != 'C' || cod != 'E' || cod != 'T');
    }
    ventaTotal = totTarj + totCheq + totEfect;
    iva = ventaTotal * 1.21;

    printf("Efectivo en Caja:\t$%.2f\nVentas con Tarjeta de Credito:\t$%.2f\nVentas con cheque:\t$%.2f\nTotal de Venta:\t$%.2f\nImporte del IVA:\t$%.2f\nNota: El IVA corresponde al 21%% del total de ventas.\n\n", totEfect, totTarj, totCheq, ventaTotal, iva);

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
int ejercicio52punto4()
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
            printf("El alumno con DNI: %d, obtuvo las notas: %02d y %02d [PROMOCIONA]", dni, nota1, nota2);
            suma = nota1 + nota2;
            cont ++;
        }
        else
        {
            if(nota1 >= 4 && nota2 >= 4)
                printf("El alumno con DNI: %d, obtuvo las notas: %02d y %02d [RINDE EXAMEN FINAL]", dni, nota1, nota2);
            else
                printf("El alumno con DNI: %d, obtuvo las notas: %02d y %02d [REPROBO LA MATERIA]", dni, nota1, nota2);
        }
        printf("Ingrese el DNI del alumno (negativo para terminar): ");
        dni = validaIntIntervaloAbierto(0, 9000000, esValidoIntIntervAbierto);
    }
    if(cont)
        prom = (float)suma / cont;
    printf("El promedio de los alumnos promocionados es %.2f\n\n", prom);

    return TODO_OK;
}


/*5.2.6 Un negocio de perfumería efectúa descuentos en sus ventas según el importe de las mismas, con la siguiente escala:
• menor a 50 pesos el 3.5 %
• entre 50 y 150 pesos el 10 %
• entre 151 y 300 pesos el 20 %.
• mayor a 300 pesos el 25 %
Confeccionar un programa que:
a. Solicite un importe y calcule el descuento a efectuar y el importe neto a cobrar, con mensajes aclaratorios.
b. Informe el importe promedio de todas las ventas realizadas.*/
int ejercicio52punto6();
int ejercicio52punto7();
int ejercicio52punto8();
int ejercicio52punto9();
int ejercicio52punto10();
int ejercicio52punto11();
int ejercicio52punto12();
int ejercicio52punto13();
int ejercicio52punto14();
int ejercicio52punto15();

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

#endif // UNIDAD5_2_C_INCLUDED
