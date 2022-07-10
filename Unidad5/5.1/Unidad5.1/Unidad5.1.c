#include "Unidad5.1.h"


booleano esValidoFloatEntre(const void* num, const void* minimo, const void* maximo);
booleano esValidoFloatMayA(const void* num, const void* inf);
booleano esValidoIntEntre(const void* num, const void* minimo, const void* maximo);
booleano esValidoMayorAInt(const void* num, const void* inf);
int validaIntMayA(const int inf, EsValidoMayorA mayorA);
int validaIntEntre(const int inf, const int sup, EsValidoEntre estaEntre);
float validaFloatMayA(const float inf, EsValidoMayorA mayorA);
float validaFloatEntre(const float inf, const float sup, EsValidoEntre estaEntre);


/*5.1.1 Mostrar por pantalla los números pares comprendidos entre 100 y 500.*/
int ejercicio51punto1()
{
    int par, minimo = 100, maximo = 500;

    puts("Ejercicio 5.1.1");
    for(par=minimo; par<=maximo; par+=2)
        printf("%d\n", par);

    printf("\n");

    return TODO_OK;
}



/*5.1.2 Confeccionar un programa para calcular el valor de la siguiente suma: 100 + 95 + 90 + ... + 50.*/
int ejercicio51punto2()
{
    long suma=0;
    int i;

    puts("Ejercicio 5.1.2");
    for(i=100; i>=50; i-=5)
        suma += i;

    printf("El resultado de la siguiente suma 100 + 95 + 90 + ... + 50 es: %ld\n\n", suma);

    return TODO_OK;
}



/*5.1.3 Se ingresan 50 números enteros. Determinar el promedio de los números pares.*/
int ejercicio51punto3()
{
   int i, num, cont=0;
   long suma = 0;
   double prom = 0;

   puts("Ejercicio 5.1.3");
   for(i=0; i<5; i++)
   {
        printf("Numero %d: ", i+1);
        printf("Ingrese un numero: ");
        fflush(stdin);
        scanf("%d", &num);
        fflush(stdin);

        if(num%2==0)
        {
            suma += num;
            cont ++;
        }
   }
   if(suma)
        prom = (double)suma/cont;

    printf("El promedio de los numeros pares es %.2f\n\n", prom);

    return TODO_OK;
}



/*5.1.4 Se ingresan 100 letras. Determinar la cantidad de vocales ingresadas.*/
int ejercicio51punto4()
{
    char letra;
    int i, cont = 0;

    puts("Ejercicio 5.1.4");
    for(i=0; i<10; i++)
    {
        printf("Ingrese una letra: ");
        fflush(stdin);
        scanf("%c", &letra);
        fflush(stdin);

        if(esVocal(letra))
            cont ++;
    }

    printf("La cantidad de vocales ingresadas es %d\n\n", cont);

    return TODO_OK;
}



/*5.1.5 Confeccionar un programa para calcular la suma de los primeros N números naturales. El valor de N lo solicita por teclado el programa.*/
int ejercicio51punto5()
{
    int cantidad, i;
    long suma=0;

    puts("Ejercicio 5.1.5");
    printf("Ingrese un numero natural: ");
    fflush(stdin);
    scanf("%d", &cantidad);
    fflush(stdin);

    for(i=1; i<=cantidad; i++)
        suma += i;

    printf("El valor de la suma de los primeros %d numeros naturales es %ld\n\n", cantidad, suma);

    return TODO_OK;
}



/*5.1.6 Ingresar N y N Números naturales. Determinar e informar:
a. La sumatoria de los valores múltiplos de 3.
b. La cantidad de valores múltiplos de 5.
c. La sumatoria de los valores que se ingresan en orden par.*/
int ejercicio51punto6()
{
    int i, cantidad, num, cantM5=0;
    long sumaM3=0, sumaPar=0;

    puts("Ejercicio 5.1.6");
    printf("Ingrese la cantidad de numeros que se proporcinaran a continuacion: ");
    fflush(stdin);
    scanf("%d", &cantidad);
    fflush(stdin);

    for(i=1; i<=cantidad; i++)
    {
        printf("Ingrese un numero natural: ");
        num = validaIntMayA(0, esValidoMayorAInt);

        if(num%3==0)
            sumaM3 += num;

        if(num%5==0)
            cantM5++;

        if(i%2==0)
            sumaPar += num;
    }

    printf("La sumatoria de los numeros multiplos de 3 es: %ld\n", sumaM3);
    printf("La cantidad de numeros multiplos de 5 es: %d\n", cantM5);
    printf("La sumatoria de los numeros ingresados en orden par es: %ld\n\n", sumaPar);

    return TODO_OK;
}



/*5.1.7 Dadas 20 notas y legajos de alumnos de un curso. Determinar:
a. Cantidad de alumnos aplazados.
b. Cuando la nota sea mayor a 7, mostrar el mensaje: “El alumno con legajo xxx ha Promocionado”.*/
int ejercicio51punto7()
{
    int nota, legajo, i, cantApl=0;

    puts("Ejercicio 5.1.7");
    for(i=0; i<5; i++)
    {
        printf("Ingrese el numero de legajo: ");
        legajo = validaIntMayA(0, esValidoMayorAInt);

        printf("Ingrese la nota (entero entre 1 y 10): ");
        nota = validaIntEntre(1, 10, esValidoIntEntre);

        if(nota>=7)
            printf("El alumno con legajo %d ha Promocionado\n", legajo);
        if(nota<4)
            cantApl ++;
    }

    printf("La cantidad de alumnos aplazados es %d\n", cantApl);
    printf("\n");
    return TODO_OK;
}



/*5.1.8 Dadas las edades y estaturas de 45 alumnos de un curso. Determinar:
a. Edad promedio.
b. Estatura promedio.
c. Cantidad de alumnos mayores de 10 años.
d. Cantidad de alumnos que miden menos de 1.40 cm.*/
int ejercicio51punto8()
{
    int i, menos1Cuaren=0, mas10A=0;
    float edad, est, sumaEst =0, sumaEdad=0, edadProm=0, estProm=0;

    puts("Ejercicio 5.1.8");
    for(i=1; i<=5; i++)
    {
        printf("Ingrese la edad del alumno: ");
        edad = validaFloatMayA(5, esValidoFloatMayA);
        printf("Ingrese la estatura del almuno: ");
        est = validaFloatMayA(0, esValidoFloatMayA);

        sumaEdad += edad;
        sumaEst += est;
        if(edad>10)
            mas10A ++;
        if(est<1.3999)
            menos1Cuaren ++;
    }

    if(sumaEst)
        estProm = sumaEst / (i);
    if(sumaEdad)
        edadProm = sumaEdad / (i);

    printf("La edad promedio es de %.0f, la estatura promedio es de %.2f, la cantidad de alumnos de mas de 10 anios es %d, y la cantidad de alumnos de menos de 1.4 mts es %d\n\n", edadProm, estProm, mas10A, menos1Cuaren);

    return TODO_OK;
}



/*5.1.9 Confeccionar un programa que exhiba por pantalla una lista, a dos columnas, con los primeros 15 números impares en la primera y los 15
primeros pares en la segunda, incluyendo los títulos.*/
int ejercicio51punto9()
{
    int i;

    puts("Ejercicio 5.1.9");
    printf("%6s%6s\n", "IMPAR", "PAR");

    for(i=1; i<=30; i++)
        (i%2!=0)?printf("%6d", i): printf("%6d\n", i);

    printf("\n");

    return TODO_OK;
}



/*5.1.10 Confeccionar un programa que solicite el ingreso de un valor entero N < 12 y luego una lista de N números reales sobre la cual debe
calcular:
a. el promedio de los positivos.
b. el promedio de los negativos.
c. la cantidad de ceros.*/
int ejercicio51punto10()
{
    int i, cantTot, cantCeros=0;
    float num, sumaNeg=0, sumaPos=0, promNeg=0, promPos=0;

    puts("Ejercicio 5.1.10");
    printf("Ingrese la cantidad de numeros que se van a proporcionar (menor a 12): ");
    cantTot = validaIntEntre(1, 12, esValidoIntEntre);

    for(i=0; i<cantTot; i++)
    {
        printf("Ingrese un numero real: ");
        fflush(stdin);
        scanf("%f", &num);
        fflush(stdin);

        if(num>0)
            sumaPos += num;
        if(num<0)
            sumaNeg += num;
        if(!num)
            cantCeros ++;
    }
    if(sumaNeg)
        promNeg = sumaNeg / cantTot;
    if(sumaPos)
        promPos = sumaPos / cantTot;

    printf("El promedio de los numeros positivos es %.2f, el promedio de los numeros negativos es %.2f, y la cantidad de ceros ingresada es %d\n\n", promPos, promNeg, cantCeros);

    return TODO_OK;
}



/*5.1.11 Ingresar 18 valores de temperatura distintos de cero. Se pide determinar e informar cuantas ternas (tres valores seguidos) de valores
positivos y cuantas de negativos hay.*/
int ejercicio51punto11()
{
    int i, contPos = 0, contNeg = 0, contTernPos = 0, contTernNeg = 0;
    float num;
    booleano esValido;

    puts("Ejercicio 5.1.11");
    for(i=0; i<5; i++)
    {
        do
        {
            printf("Ingrese un numero distinto de cero: ");
            scanf("%f", &num);
            if(num!=0)
                esValido = VERDADERO;
            else
                esValido = FALSO;

            if(!esValido)
                printf("El numero ingresado debe ser distinto de cero. ");
        } while(!esValido);

        if(num>0)
        {
            contPos++;
            contNeg = 0;
        }
        if(num<0)
        {
            contNeg++;
            contPos = 0;
        }
        if(contNeg>=3)
            contTernNeg++;
        if(contPos>=3)
            contTernPos++;
    }

    printf("La cantidad de ternas de numeros positivos es %d y la cantidad de ternas de numeros negativos es %d\n\n", contTernPos, contTernNeg);

    return TODO_OK;
}




/*5.1.12 Calcular el factorial de un número ingresado por teclado. El factorial se calcula como el producto de todos los enteros positivos
desde 1 hasta el número. En matemática el factorial se expresa con el símbolo. Por ejemplo, el factorial de 5 es 120 ya
que 5! = 1 x 2 x 3 x 4 x 5 =120*/
int ejercicio51punto12()
{
    int num, i;
    double factorial=1;

    puts("Ejercicio 5.1.12");
    printf("Ingrese el numero al cual se le calculara su factorial: ");
    num = validaIntMayA(-1, esValidoMayorAInt);

    if(num>1)
    {
        for(i=num; i>=2; i--)
            factorial *= i;
    }

    printf("El factorial de %d es %.0f\n\n", num, factorial);

    return TODO_OK;
}



/*5.1.13 Realizar un programa que:
a. Muestre todos los números primos entre 1 y 100. (Un nro. es primo cuando es divisible solamente por 1 y por sí mismo)
b. Contar y mostrar la cantidad de primos encontrados.*/
int ejercicio51punto13()
{
    int cantPrim=0, i, j, cantDiv;

    puts("Ejercicio 5.1.13");
    for(i=1; i<101; i++)
    {
        j = 2;
        cantDiv = 0;
        while(cantDiv<2 && j<=i)
        {
            if(i%j==0)
                cantDiv++;
            j++;
        }
        if(cantDiv<2)
        {
            cantPrim ++;
            printf("%d es numero primo\n", i);
        }
    }
    printf("Desde el 1 al 100 hay %d numeros primos.\n\n", cantPrim);

    return TODO_OK;
}



/*5.1.14 Confeccionar un programa que determine e informe los números perfectos comprendidos entre 1 y 9000. Un número es perfecto cuando es
igual a la suma de sus divisores positivos menores que él.*/
int ejercicio51punto14()
{
    int i, j, sumaDiv;

    puts("Ejercicio 5.1.14");
    printf("Numeros perfectos entre 1 y 9000\n");
    for(i=1; i<=9000; i++)
    {
        sumaDiv = 0;
        for(j=1; j<=i/2; j++)
        {
            if(i%j==0)
                sumaDiv += j;
        }
        if(sumaDiv == i)
            printf("%d es un numero perfecto\n", i);
    }
    printf("\n");

    return TODO_OK;
}



/*5.1.15 Se realizó un concurso de tiro al blanco. Existen 5 participantes y cada uno de ellos efectúa 3 disparos, registrándose las
coordenadas X-Y de cada disparo. Determinar:
a. Cuantos disparos se efectuaron en cada cuadrante por cada participante
b. Cuantos disparos se efectuaron en total en el centro.
NOTA: no considere disparos sobre los ejes.*/
int ejercicio51punto15()
{
    int i, coordX, coordY, cantDisp, contCuad1, contCuad2, contCuad3, contCuad4, contCentro = 0;

    puts("Ejercicio 5.1.15");
    for(i=0; i<5; i++)
    {
        cantDisp = 1;
        contCuad1 = 0;
        contCuad2 = 0;
        contCuad3 = 0;
        contCuad4 = 0;
        while(cantDisp<=3)
        {
            printf("Disparo %d:\n", cantDisp);
            printf("Ingrese la coordenada X del disparo: ");
            fflush(stdin);
            scanf("%d", &coordX);
            fflush(stdin);
            printf("Ingrese la coordenada Y del disparo: ");
            scanf("%d", &coordY);
            if(coordX>0 && coordY>0)
            {
                cantDisp ++;
                contCuad1 ++;
            }
            if(coordX<0 && coordY>0)
            {
                cantDisp ++;
                contCuad2 ++;
            }
            if(coordX<0 && coordY<0)
            {
                cantDisp ++;
                contCuad3 ++;
            }
            if(coordX>0 && coordY<0)
            {
                cantDisp ++;
                contCuad4 ++;
            }
            if((!coordX && coordY)||(coordX && !coordY))
                printf("El disparo no sera contado pues se ha disparado sobre los ejes\n");
            if(!coordX && !coordY)
            {
                cantDisp ++;
                contCentro ++;
            }
        }
        printf("La cantidad de disparos al Cuadrante 1 es %d, la cantidad de disparos al Cuadrante 2 es %d, la cantidad de disparos al Cuadrante 3 es %d y la cantidad de disparos al Cuadrante 4 es %d\n", contCuad1, contCuad2, contCuad3, contCuad4);
    }
    printf("La cantidad de disparos totales al centro es de %d\n\n", contCentro);

    return TODO_OK;
}




/*5.1.16 Se ingresan DNI y la nota promedio de 10 alumnos. Determinar el DNI del alumno de mayor nota promedio (considerar único).*/
int ejercicio51punto16()
{
    int dni, i, dniMayor;
    float notaProm, mayor=0;

    puts("Ejercicio 5.1.16");
    for(i=0; i<10; i++)
    {
        printf("Ingrese el numero de DNI del alumno (mayor a 10000000): ");
        dni = validaIntMayA(10000000, esValidoMayorAInt);
        printf("Ingrese la nota promedio (1 a 10): ");
        notaProm = validaFloatEntre(1, 10, esValidoFloatEntre);
        if(notaProm>mayor)
        {
            mayor = notaProm;
            dniMayor = dni;
        }
    }
    printf("El DNI %d tiene la mayor nota promedio (%.2f)\n\n", dniMayor, mayor);

    return TODO_OK;
}




/*5.1.17 Ingresar N artículos (códigos) y sus correspondientes precios. Indicar el código del artículo más caro y el precio del más barato.
NOTA: todos los artículos tienen precios distintos.*/
int ejercicio51punto17()
{
    int cant, cod, codMAyor, i;
    float precio, precioMay, precioMen;

    puts("Ejercicio 5.1.17");
    printf("Ingrese la cantidad de articulos a proporcionar (mayor a 0): ");
    cant = validaIntMayA(0, esValidoMayorAInt);

    for(i=0; i<cant; i++)
    {
        printf("Ingrese el codigo del producto: ");
        fflush(stdin);
        scanf("%d", &cod);
        fflush(stdin);
        printf("Ingrese el precio del producto (mayor a cero): ");
        precio = validaFloatMayA(0, esValidoFloatMayA);
        if(i==0)
        {
            precioMay = precio;
            precioMen = precio;
            codMAyor = cod;
        }
        if(precio>precioMay)
        {
            precioMay = precio;
            codMAyor = cod;
        }
        if(precio<precioMen)
            precioMen = precio;
    }

    printf("EL codigo del articulo mas caro es %d y su precio es %.2f\n", codMAyor, precioMay);
    printf("El precio del articulo mas barato es %.2f\n\n", precioMen);

    return  TODO_OK;
}




/*5.1.18 Realizar un programa que muestre por pantalla las tablas de multiplicar del 1 al 9 de la siguiente forma:
1  2  3  4  5  6  7  8  9
2  4  6  8 10 12 14 16 18
3  6  9 12 15 18 21 24 27
4  8 12 16 20 24 28 32 36
5 10 15 20 25 30 35 40 45
6 12 18 24 30 36 42 48 54
7 14 21 28 35 42 49 56 63
8 16 24 32 40 48 56 64 72
9 18 27 36 45 54 63 72 81*/
int ejercicio51punto18()
{
    int fil, col;

    puts("Ejercicio 5.1.18");
    for(fil=1; fil<10; fil++)
    {
        for(col=1; col<10; col++)
        {
            printf("%4d", fil*col);
        }
        printf("\n");
    }
    printf("\n");

    return TODO_OK;
}




/*5.1.19 Ingresar un número entero mayor a 0. Debe dibujar un triángulo rectángulo con * con tantas filas como el número indicado. En cada fila
se va incrementando la cantidad de asteriscos. Por ejemplo, si se ingresa el número 6 debe mostrar en pantalla:
*
**
***
****
*****
******
*/
int ejercicio51punto19()
{
    int cant, i, j;

    puts("Ejercicio 5.1.19");
    printf("Ingrese la cantidad de filas de la figura (mayor a 0): ");
    cant = validaIntMayA(0, esValidoMayorAInt);
    for(i=1; i<=cant; i++)
    {
        for(j=1; j<=i; j++)
            printf("*");
        printf("\n");
    }

    printf("\n");
    return TODO_OK;
}



/*5.1.20 Ingresar un número entero mayor a 0. Debe dibujar una pirámide con * con tantas filas como el número indicado. En cada fila se va
incrementando la cantidad de asteriscos de 2 en 2.
Por ejemplo, si se ingresa el número 5 debe mostrar en pantalla:
    *
   ***
  *****
 *******
*********
*/
int ejercicio51punto20()
{
    int cant, i, j, k;

    puts("Ejercicio 5.1.20");
    printf("Ingrese la cantidad de filas del triangulo (mayor a 0): ");
    cant = validaIntMayA(0, esValidoMayorAInt);

    for(i=1; i<=cant; i++)
    {
        for(j=0; j<cant-i; j++)
            printf(" ");
        for(k=0; k<i*2-1; k++)
            printf("*");
        printf("\n");
    }
    printf("\n");

    return TODO_OK;
}




/*5.1.21 Tomando como base el ejercicio anterior ingresar un número entero mayor a 0 y dibujar un rombo con *. Por ejemplo, si se ingresa el
número 5 dibuja la pirámide de 5 filas y luego completa el rombo al ir decrementando la cantidad de asteriscos.
*
***
*****
*******
*********
*******
*****
***
*
*/
int ejercicio51punto21()
{
    int cant, i, j, k;

    puts("Ejercicio 5.1.21");
    printf("Ingrese la cantidad de filas del triangulo (mayor a 0): ");
    cant = validaIntMayA(0, esValidoMayorAInt);

    for(i=1; i<=cant; i++)
    {
        for(j=0; j<cant-i; j++)
            printf(" ");
        for(k=0; k<i*2-1; k++)
            printf("*");
        printf("\n");
    }
    for(i=cant; i>=1; i--)
    {
        for(j=0; j<cant-i+1; j++)
            printf(" ");
        for(k=0; k<(i-1)*2-1; k++)
            printf("*");
        printf("\n");
    }
    printf("\n");

    return TODO_OK;
}


booleano esValidoMayorAInt(const void* num, const void* inf)
{
    return (*(int*)num > *(int*)inf);
}


booleano esValidoIntEntre(const void* num, const void* minimo, const void* maximo)
{
    return ( *(int*)num >= *(int*)minimo && *(int*)num <= *(int*)maximo );
}

int validaIntMayA(const int inf, EsValidoMayorA mayorA)
{
    int num;
    booleano esValido;

    do
    {
        fflush(stdin);
        scanf("%d", &num);
        fflush(stdin);
        esValido = (mayorA(&num, &inf));

        if(!esValido)
            printf("A ingresado un dato no permitido, el valor proporcionado debe ser mayor a %d, vuelva a ingresar: ", inf);
    } while (!esValido);

    return num;
}

int validaIntEntre(const int inf, const int sup, EsValidoEntre estaEntre)
{
    int num;
    booleano esValido;

    do
    {
        fflush(stdin);
        scanf("%d", &num);
        fflush(stdin);
        esValido = (estaEntre(&num, &inf, &sup));

        if(!esValido)
            printf("A ingresado un dato no permitido, el valor proporcionado debe estar entre %d y %d, vuelva a ingresar: ", inf, sup);
    } while (!esValido);

    return num;
}


booleano esValidoFloatEntre(const void* num, const void* minimo, const void* maximo)
{
    return (*(float*)num >= *(float*)minimo && *(float*)num <= *(float*)maximo);
}


booleano esValidoFloatMayA(const void* num, const void* inf)
{
    return (*(float*)num > *(float*)inf);
}


float validaFloatMayA(const float inf, EsValidoMayorA mayorA)
{
    float num;
    booleano esValido;

    do
    {
        fflush(stdin);
        scanf("%f", &num);
        fflush(stdin);
        esValido = (mayorA(&num, &inf));

        if(!esValido)
            printf("A ingresado un dato no permitido, el valor proporcionado debe ser mayor a %.2f, vuelva a ingresar: ", inf);
    } while (!esValido);

    return num;
}


float validaFloatEntre(const float inf, const float sup, EsValidoEntre estaEntre)
{
    float num;
    booleano esValido;

    do
    {
        fflush(stdin);
        scanf("%f", &num);
        fflush(stdin);
        esValido = (estaEntre(&num, &inf, &sup));

        if(!esValido)
            printf("A ingresado un dato no permitido, el valor proporcionado debe estar entre %.2f y %.2f, vuelva a ingresar: ", inf, sup);
    } while (!esValido);

    return num;
}
