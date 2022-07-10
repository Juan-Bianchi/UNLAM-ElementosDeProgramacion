#ifndef UNIDAD5_1_H
#define UNIDAD5_1_H


#include <stdio.h>
#include <string.h>

#define TODO_OK 0
#define VERDADERO 1
#define FALSO 0

#define esVocal(a)      ( (a) == 'A' || (a) == 'E' || (a) == 'I' || (a) == 'O' || (a) == 'U' || \
                         (a) == 'a' || (a) == 'e' || (a) == 'i' || (a) == 'o' || (a) == 'u' )

typedef int booleano;

booleano typedef (*EsValidoMayorA)(const void* num, const void* minimo);
booleano typedef (*EsValidoEntre)(const void* num, const void* minimo, const void* maximo);


int ejercicio51punto1();
int ejercicio51punto2();
int ejercicio51punto3();
int ejercicio51punto4();
int ejercicio51punto5();
int ejercicio51punto6();
int ejercicio51punto7();
int ejercicio51punto8();
int ejercicio51punto9();
int ejercicio51punto10();
int ejercicio51punto11();
int ejercicio51punto12();
int ejercicio51punto13();
int ejercicio51punto14();
int ejercicio51punto15();
int ejercicio51punto16();
int ejercicio51punto17();
int ejercicio51punto18();
int ejercicio51punto19();
int ejercicio51punto20();
int ejercicio51punto21();

#endif // UNIDAD5_1_H
