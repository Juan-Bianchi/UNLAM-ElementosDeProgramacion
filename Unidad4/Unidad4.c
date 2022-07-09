#include "Unidad4.h"

int esValidoFloatMayA(const void* elem, const void* inf);
float validaFloatMayA(const float inf, esValidoNumMayA esMayorA);
int esValidoIntEntre(const void* elem, const void* inf, const void* sup);
int validaIntEntre(const int inf, const int sup, esValidoNumEntre estaEntre);
int esValidoIntMayA(const void* elem, const void* inf);
int validaIntMayA(const int inf, esValidoNumMayA esMayorA);
booleano esBisiesto(const int anio);
int cantDiasMes(int mes, int anio);
booleano esFechaValida(int dia, int mes, int anio);



/*4.1. Se ingresan 3 números distintos. Determinar el mayor.*/
int ejercicio4punto1()
{
    float n1, n2, n3, max;

    puts("Ejercicio 4.1");
    printf("Ingrese el primer numero: ");
    fflush(stdin);
    scanf("%f", &n1);
    fflush(stdin);
    printf("Ingrese el segundo numero: ");
    scanf("%f", &n2);
    fflush(stdin);
    printf("Ingrese el tercer numero: ");
    scanf("%f", &n3);
    fflush(stdin);

    max = max(max(n1, n2), n3);

    printf("Los numeros son : %.2f, %.2f y %.2f\nEl mayor de ellos es %.2f\n\n", n1, n2, n3, max);

    return TODO_OK;
}


/*4.2. Dados tres números determinar e informar con un mensaje si el primer número ingresado es menor que los otros dos.*/
int ejercicio4punto2()
{
    float n1, n2, n3;

    puts("Ejercicio 4.2");
    printf("Ingrese el primer numero: ");
    fflush(stdin);
    scanf("%f", &n1);
    fflush(stdin);
    printf("Ingrese el segundo numero: ");
    scanf("%f", &n2);
    fflush(stdin);
    printf("Ingrese el tercer numero: ");
    scanf("%f", &n3);
    fflush(stdin);

    (n1 < n2 && n1 < n3)? printf("El numero %.2f es el menor\n\n", n1): printf("El numero %.2f no es el menor\n\n", n1);

    return TODO_OK;
}


/*4.3. Confeccionar un programa que pueda determinar de 3 números enteros que se ingresan si alguno de ellos es igual a la suma de los otros
dos.*/
int ejercicio4punto3()
{
    int n1, n2, n3;

    puts("Ejercicio 4.3");
    printf("Ingrese el primer numero entero: ");
    fflush(stdin);
    scanf("%d", &n1);
    printf("Ingrese el segundo numero entero: ");
    fflush(stdin);
    scanf("%d", &n2);
    printf("Ingrese el tercer numero entero: ");
    fflush(stdin);
    scanf("%d", &n3);
    if(n1 == n2 + n3)
        printf("El numero %d es igual a la suma de %d y %d\n\n", n1, n2, n3);
    else
    {
        if(n2 == n1 + n3)
            printf("El numero %d es igual a la suma de %d y %d\n\n", n2, n1, n3);
        else
        {
            if(n3 == n1 + n2)
                printf("El numero %d es igual a la suma de %d y %d\n\n", n3, n1, n2);
            else
                printf("Ninguno de los numeros es suma de los otros dos\n\n");
        }
    }
    return TODO_OK;
}


/*4.4. Ingresar 3 valores reales y:
a. Si los dos primeros son mayores al tercero informar “MAYORES AL TERCERO”.
b. Si los tres son iguales informar “TRES IGUALES .
c. Si alguno de los dos primeros es menor al tercero informar “ALGUNO ES MENOR”.*/
int ejercicio4punto4()
{
    float n1, n2, n3;

    puts("Ejercicio 4.4");
    printf("Ingrese el primer numero: ");
    fflush(stdin);
    scanf("%f", &n1);
    fflush(stdin);
    printf("Ingrese el segundo numero: ");
    scanf("%f", &n2);
    fflush(stdin);
    printf("Ingrese el tercer numero: ");
    scanf("%f", &n3);
    fflush(stdin);

    if(n1>n3 && n2>n3)
        printf("MAYORES AL TERCERO.\n\n");
    if((n1 == n2) == n3)
        printf("TRES IGUALES\n\n");
    if(n1<n3 || n2<n3)
        printf("ALGUNO MENOR\n\n");

    return TODO_OK;
}

/*4.5. Se ingresan 3 números enteros. Informarlos en orden creciente.*/
int ejercicio4punto5()
{
    int n1, n2, n3;

    puts("Ejercicio 4.5");
    printf("Ingrese el primer numero entero: ");
    fflush(stdin);
    scanf("%d", &n1);
    printf("Ingrese el segundo numero entero: ");
    fflush(stdin);
    scanf("%d", &n2);
    printf("Ingrese el tercer numero entero: ");
    fflush(stdin);
    scanf("%d", &n3);

    puts("Numeros ordenados en forma creciente: ");
    if(n2<=n3 && n1<=n2)
        printf("%d\t%d\t%d\n\n", n1, n2, n3);
    if(n3<n2 && n1<=n3)
        printf("%d\t%d\t%d\n\n", n1, n3, n2);
    if(n1<n3 && n2<=n1)
        printf("%d\t%d\t%d\n\n", n2, n1, n3);
    if(n3<n1 && n2<=n3)
        printf("%d\t%d\t%d\n\n", n2, n3, n1);
    if(n1<n2 && n3<=n1)
        printf("%d\t%d\t%d\n\n", n3, n1, n2);
    if(n2<n1 && n3<=n2)
        printf("%d\t%d\t%d\n\n", n3, n2, n1);
    return TODO_OK;
}


/*4.6. Confeccionar un programa que permita ingresar 4 números enteros, de a uno por vez y determine el menor valor y su número de orden.
Informe los valores ingresados e identifique al menor con mensaje aclaratorio.*/
int ejercicio4punto6()
{
    int n1, n2, n3, n4;

    puts("Ejercicio 4.6");
    printf("Ingrese el primer numero entero: ");
    fflush(stdin);
    scanf("%d", &n1);
    printf("Ingrese el segundo numero entero: ");
    fflush(stdin);
    scanf("%d", &n2);
    printf("Ingrese el tercer numero entero: ");
    fflush(stdin);
    scanf("%d", &n3);
    printf("Ingrese el cuarto numero entero: ");
    fflush(stdin);
    scanf("%d", &n4);

    if(n1<=n2 && n1<=n3 && n1<=n4)
        printf("El menor es %d y su numero de orden es 1\n\n", n1);
    if(n2<n1 && n2<n3 && n2<n4)
        printf("El menor es %d y su numero de orden es 2\n\n", n2);
    if(n3<n1 && n3<n2 && n3<n4)
        printf("El menor es %d y su numero de orden es 3\n\n", n3);
    if(n4<n1 && n4<n3 && n4<n3)
        printf("El menor es %d y su numero de orden es 4\n\n", n4);

    return TODO_OK;
}


/*4.7. Confeccionar un programa que solicite e ingrese 3 valores reales positivos, mayores que cero y determine e informe si forman o no
triángulo. Para ello utilizar el teorema de la desigualdad del triángulo que establece que la suma de las longitudes de cualesquiera de dos
lados de un triángulo es mayor que la longitud del tercer lado.*/
int ejercicio4punto7()
{
    float n1, n2, n3;

    puts("Ejercicio 4.7");
    printf("Ingrese el primer numero: ");
    n1 = validaFloatMayA(0, esValidoFloatMayA);
    printf("Ingrese el segundo numero: ");
    n2 = validaFloatMayA(0, esValidoFloatMayA);
    printf("Ingrese el tercer numero: ");
    n3 = validaFloatMayA(0, esValidoFloatMayA);

    if(n1+n2 > n3 && n1+n3 > n2 && n2+n3 > n1)
        printf("Los lados forman un triangulo, pues la suma de dos de sus lados es mayor a la longitud del lado restante\n\n");
    else
        printf("No se forma un triangulo porque no se cumple el teorema de la desigualdad del triangulo.\n\n");

    return TODO_OK;
}


/*4.8. Realizar un programa que ingrese dos números e indique si el primer número es divisible por el segundo.*/
int ejercicio4punto8()
{
    int n1, n2;

    puts("Ejercicio 4.8");
    printf("Ingrese el primer numero entero: ");
    fflush(stdin);
    scanf("%d", &n1);
    printf("Ingrese el segundo numero entero: ");
    fflush(stdin);
    scanf("%d", &n2);

    if(n2 && n1 % n2 == 0)
        printf("El primer numero es divisible por el segundo\n\n");
    else
        printf("El primer numero no es divisible por el segundo\n\n");

    return TODO_OK;
}


/*4.9. Confeccionar un programa que permita ingresar un carácter alfanumérico y determine e informe si lo ingresado corresponde a una vocal,
con el mensaje “VOCAL”. y su correspondiente valor numérico en ASCII.*/
int ejercicio4punto9()
{
    char caract;
    booleano esAlfaNum;

    puts("Ejercicio 4.9");
    printf("Por favor, ingrese un caracter alfanumerico: ");
    do
    {
        fflush(stdin);
        scanf("%c", &caract);
        fflush(stdin);
        esAlfaNum = es_alfanum(caract);
        if(!esAlfaNum)
            printf("El caracter ingresado no es alfanumerico. Por favor vuelva a ingresar: ");
    } while(!esAlfaNum);

    if(es_vocal(caract))
        printf("El caracter %c es vocal y su codigo ASCII correspondiente es %d\n\n", caract, (int)caract);
    else
        printf("El caracter %c no es vocal\n\n", caract);

    return TODO_OK;
}


/*4.10. Confeccionar un programa que permita convertir grados sexagesimales a radianes y viceversa, según el valor de un código que se ingresa
junto al valor. Si código = 1 se ingresan grados, si es 2 se ingresan radianes.
1 radian = (180 / PI) grados
1 grado = (PI / 180) radianes*/
int ejercicio4punto10()
{
    int cod;
    float dato;

    printf("Ingrese el codigo del dato que se ingresara a continuacion (1 para grados, 2 para radianes): ");
    cod = validaIntEntre(1,2,esValidoIntEntre);
    printf("Ingrese el dato (mayor a 0): ");
    dato = validaFloatMayA(0, esValidoFloatMayA);
    if(cod==1)
        printf("Valor ingresado %.2f grados.\nValor modificado: %.2f radianes\n\n", dato, M_PI / 180 * dato);
    if(cod==2)
        printf("Valor ingresado %.2f radianes.\nValor modificado: %.2f grados\n\n", dato, 180 / M_PI * dato);

    return TODO_OK;
}


/*4.11. Escribir un programa que solicite el año y el número de mes y nos informe cuantos días tiene dicho mes. Debemos considerar que el año
puede ser bisiesto. Un año es bisiesto cuando es divisible por 4 y no por 100 o el año es divisible por 400.*/
int ejercicio4punto11()
{
    int anio, mes, diasDelMes;

    puts("Ejercicio 4.11");
    printf("Ingrese el anio: ");
    anio = validaIntMayA(1601, esValidoIntMayA);
    printf("Ingrese el mes: ");
    mes = validaIntEntre(1, 12, esValidoIntEntre);
    diasDelMes = cantDiasMes(mes, anio);

    printf("La cantidad de dias del mes %d en el anio %d es %d\n\n", mes, anio, diasDelMes);

    return TODO_OK;
}


/*4.12. Ingresar el valor de la hora y la cantidad de horas trabajadas por un empleado. Calcular su sueldo tomando en cuenta que recibe un
premio de $500 si trabajo más de 50 horas y, además, si trabajó más de 150 horas se le otorgan $1000 adicionales.*/
int ejercicio4punto12()
{
    int cantHor;
    float valHor, sueldo;

    puts("Ejercicio 4.12");
    printf("Ingrese la cantidad de horas trabajadas (mayor a 0): ");
    cantHor = validaIntMayA(0, esValidoIntMayA);
    printf("Ingrese el valor hora del empleado (mayor a 0): ");
    valHor = validaFloatMayA(0, esValidoFloatMayA);

    sueldo = cantHor * valHor;
    if(cantHor>150)
        sueldo += 1000;
    if(cantHor>50)
        sueldo += 500;

    printf("El sueldo del empleado es $%.2f\n\n", sueldo);

    return TODO_OK;
}


/*4.13. Un fabricante de repuestos para tractores ha descubierto que ciertos artículos identificados por los números de catálogo 12121 al 18081;
30012 al 45565 y 67000 al 68000 son defectuosos. Se desea confeccionar un programa al que informándole el número de catálogo indique si el
artículo es o no defectuoso. Los artículos del catálogo van desde el 1200 al 90000. Si se ingresa otro número informar “FUERA DE CATALOGO”.*/
int ejercicio4punto13()
{
    int numCat;

    puts("Ejercicio 4.13");
    printf("Ingrese el numero de catalogo del articulo (1200 a 90000): ");
    fflush(stdin);
    scanf("%d", &numCat);
    fflush(stdin);
    if(numCat<1200 || numCat>90000)
        printf("FUERA DE CATALOGO\n\n");
    else
    {
        if((numCat>=12121 && numCat<=18081) || (numCat>= 30012 && numCat<=45565) || (numCat>=67000 && numCat<=68000))
            printf("El articulo es defectuoso\n\n");
        else
            printf("El articulo no es defectuoso\n\n");
    }

    return TODO_OK;
}


/*4.14. La farmacia Sindical efectúa descuentos a sus afiliados según el importe de la compra con la siguiente escala:
a. menor de $55 el descuento es del 4.5%
b. entre $55 y $100 el descuento es del 8%
c. más de $100 el descuento es del 10.5%
Confeccionar un programa que reciba un importe e informe: el descuento y el precio neto a cobrar, con mensajes aclaratorios.*/
int ejercicio4punto14()
{
    float importe;

    puts("Ejercicio 4.14");
    printf("Ingrese el importe de la venta: ");
    importe = validaFloatMayA(0, esValidoFloatMayA);
    if(importe<55)
        printf("El descuento a efectuar es del 4.5%% y el importe neto es de %.2f\n\n", importe * 0.955);
    if(importe>=55 && importe<=100)
        printf("El descuento a efectuar es del 8%% y el importe neto es de %.2f\n\n", importe * 0.92);
    if(importe>100)
        printf("El descuento a efectuar es del 10.5%% y el importe neto es de %.2f\n\n", importe * 0.895);

    return TODO_OK;
}



/*4.15. Un negocio de artículos de computación vende DVDs según la siguiente escala de precios:
• sueltos, entre 1 y 9 a $15 c/u.
• la caja de 10 cuesta $120.
• la caja de 50 cuesta $500.
Si la compra excede las 100 unidades se efectúa un descuento del 10%.
NOTA: se aceptan compras entre 1 y 500 DVDs.
Se pide que se ingrese una cantidad de DVDs que se quiere comprar y calcule e informe el importe a pagar.*/
int ejercicio4punto15()
{
    int cant;
    float precio;

    puts("Ejercicio 4.15");
    printf("Ingrese la cantidad de DVDs vendidos (1 a 500): ");
    cant = validaIntMayA(0, esValidoIntMayA);

    if(cant>500)
        printf("La cantidad vendida tiene que estar entre 1 y 500\n\n");
    else
    {
        precio = cant / 50 * 500 + (cant % 50) / 10 * 120 + (cant % 10) * 15;
        printf("El precio de la venta es $%.2f\n\n", precio);
    }
    return  TODO_OK;
}


/*4.16. Un negocio vende distintos artículos identificados por un código, según se muestra:
• código 1; 10; 100: 10 pesos la unidad.
• código 2; 22; 222: 7 pesos la unidad. La caja de 10 unidades vale 65 pesos.
• código 3; 33: 3 pesos la unidad. Si la compra es por más de 10 unidades se hace un descuento del 10% sobre el total de la compra.
• código 4; 44: 1 peso la unidad.
Confeccionar un programa que ingrese como dato el código de un artículo y la cantidad a comprar y se informe el importe de la compra, con las
siguientes leyendas:
ARTÍCULO xxxxx  CANTIDAD xxxx   IMPORTE A PAGAR $ xxxx.xx*/
int ejercicio4punto16()
{
    int cod, cant;
    float precio;

    puts("Ejercicio 4.16");
    printf("Ingrese el codigo del articulo: ");
    fflush(stdin);
    scanf("%d", &cod);
    fflush(stdin);
    printf("Ingrese la cantidad de la compra (mayor a 0): ");
    cant = validaIntMayA(0, esValidoIntMayA);
    if(cod==1 || cod==10 || cod==100)
        precio = cant * 10;
    else
    {
        if(cod==2 || cod==22 || cod==222)
            precio = cant / 10 * 65 + (cant % 10) * 7;
        else
        {
            if(cod==3 || cod==33)
            {
                if(cant>10)
                    precio = cant * 3 * 0.9;
                else
                    precio = cant * 3;
            }
            else
            {
                if(cod==4 || cod==44)
                    precio = cant;
                else
                    printf("El codigo de articulo seleccionado es inexistente\n\n");
            }
        }
    }
    printf("ARTICULO %d\tCANTIDAD %d\tIMPORTE A PAGAR $%.2f\n\n", cod, cant, precio);

    return TODO_OK;
}



/*4.17. Confeccionar un programa que pueda determinar el importe a pagar por una prestación médica según su código. Los importes se cobran según
la siguiente tabla:
Código  Importe
 A        20
 D        40
 F        60
 M        150
 T        150
Se debe ingresar el número de historia del paciente y el código de la prestación. Se debe emitir un ticket con el número de la historia, el
código y el importe a pagar.*/
int ejercicio4punto17()
{
    int hist;
    char cod;
    float precio;

    puts("Ejercicio 4.17");
    printf("Ingrese el numero de historial del paciente: ");
    fflush(stdin);
    scanf("%d", &hist);
    fflush(stdin);
    printf("Ingrese el codigo de prestacion del plan: ");
    scanf("%c", &cod);
    cod = toupper(cod);
    fflush(stdin);

    switch (cod)
    {
        case 'A':
        {
            precio = 20;
            printf("Historia numero %d\nCodigo de prestacion %c\nImporte a pagar $%.2f\n\n", hist, cod, precio);
            break;
        }
        case 'D':
        {
            precio = 40;
            printf("Historia numero %d\nCodigo de prestacion %c\nImporte a pagar $%.2f\n\n", hist, cod, precio);
            break;
        }
        case 'F':
        {
            precio = 60;
            printf("Historia numero %d\nCodigo de prestacion %c\nImporte a pagar $%.2f\n\n", hist, cod, precio);
            break;
        }
        case 'M':
        case 'T':
        {
            precio = 150;
            printf("Historia numero %d\nCodigo de prestacion %c\nImporte a pagar $%.2f\n\n", hist, cod, precio);
            break;
        }
        default :
            printf("El codigo de prestacion seleccionado es inexistente\n\n");

    }


    return TODO_OK;
}



/*4.18. Confeccionar un programa que permita ingresar la fecha actual (día, mes y año) y la fecha de nacimiento de una persona (día, mes y año).
Con ambos datos debe calcular la edad de dicha persona.*/
int ejercicio4punto18()
{
    int dia , mes , anio , diaN, mesN, anioN;
    booleano fechaValida;

    do
    {
        printf("Ingrese el anio actual: ");
        scanf("%d", &anio);
        fflush(stdin);
        printf("Ingrese el mes actual: ");
        scanf("%d", &mes);
        fflush(stdin);
        printf("Ingrese el dia actual: ");
        scanf("%d", &dia);
        fechaValida = esFechaValida(dia, mes, anio);
    } while(!fechaValida);

    do
    {
        printf("Ingrese el anio de su nacimiento: ");
        scanf("%d", &anioN);
        fflush(stdin);
        printf("Ingrese el mes de su nacimiento: ");
        scanf("%d", &mesN);
        fflush(stdin);
        printf("Ingrese el dia de su nacimiento: ");
        scanf("%d", &diaN);
        fechaValida = esFechaValida(diaN, mesN, anioN);
    } while(!fechaValida);

    if(mes<mesN)
        printf("Su edad es %d\n\n", anio - anioN - 1);
    else
    {
        if(mes == mesN && dia<diaN)
            printf("Su edad es %d\n\n", anio - anioN - 1);
        else
            printf("Su edad es %d\n\n", anio - anioN);
    }

    return TODO_OK;
}


int esValidoFloatMayA(const void* elem, const void* inf)
{
    return *(float*)elem > *(float*)inf;
}

float validaFloatMayA(const float inf, esValidoNumMayA mayorA)
{
    float num;
    booleano esValido = VERDADERO;

    do
    {
        scanf("%f", &num);
        esValido = mayorA(&num, &inf);
        if(!esValido)
            printf("El numero ingresado no es valido. Debe ser mayor a %.2f. Vuelva a ingresar: ", inf);
    } while (!esValido);

    return num;
}


int esValidoIntEntre(const void* elem, const void* inf, const void* sup)
{
    return *(int*)elem >= *(int*)inf && *(int*)elem <= *(int*)sup;
}


int validaIntEntre(const int inf, const int sup, esValidoNumEntre estaEntre)
{
    int num;
    booleano esValido;

    do
    {
        fflush(stdin);
        scanf("%d", &num);
        fflush(stdin);
        esValido = estaEntre(&num, &inf, &sup);
        if(!esValido)
            printf("El numero ingresado no es valido, debe estar entre %d y %d. Vuelva a ingresar: ", inf, sup);
    } while(!esValido);

    return num;
}


booleano esBisiesto(const int anio)
{
        return (anio % 400 == 0) || (anio % 4 == 0 && anio % 100 !=0);
}


int esValidoIntMayA(const void* elem, const void* inf)
{
    return *(int*)elem > *(int*)inf;
}


int validaIntMayA(const int inf, esValidoNumMayA esMayorA)
{
    int num;
    booleano esValido;

    do
    {
        scanf("%d", &num);
        esValido = esMayorA(&num, &inf);
        if(!esValido)
            printf("El numero ingresado no es valido. Debe ser mayor a %d. Vuelva a ingresar: ", inf);
    } while (!esValido);

    return num;
}


int cantDiasMes(int mes, int anio)
{
    int bisiesto, diasDelMes;
    const int diasXMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    bisiesto = esBisiesto(anio);
    if(mes==2)
        diasDelMes = diasXMes[mes-1]-bisiesto;
    diasDelMes = diasXMes[mes-1];

    return diasDelMes;
}


booleano esFechaValida(int dia, int mes, int anio)
{
    return anio>=1601 && mes >=1 && mes <=12 && dia>=1 && dia <= cantDiasMes(mes, anio);
}
