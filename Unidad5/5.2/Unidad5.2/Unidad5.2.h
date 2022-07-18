#ifndef UNIDAD5_2_H
#define UNIDAD5_2_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>


#define min(a)      ( ((a) < (b))? (a): (b) )
#define es_vocal_min(c) ( (c) == 'a' || (c) == 'e' || (c) == 'i' || (c) == 'o' || (c) == 'u' )
#define es_vocal_may(c) ( (c) == 'A' || (c) == 'E' || (c) == 'I' || (c) == 'O' || (c) == 'U' )
#define es_letra_may(c) ( (c) >= 'A' && (c) <= 'Z' )
#define es_letra_min(c) ( (c) >= 'a' && (c) <= 'z' )
#define es_numero(c)    ( (c) >= '0' && (c) <= '9' )
#define VERDADERO 1
#define FALSO 0
#define TODO_OK 0


int typedef booleano;

int typedef (*esValidoEntre)(const void* elem, const void* inf, const void* sup);
int typedef (*esValidoMayA)(const void* elem, const void* inf);
int typedef (*esValidoIntAbierto)(const void* num, const void* izq, const void* der);


int ejercicio52punto1();
int ejercicio52punto2();
int ejercicio52punto3();
int ejercicio52punto4();
int ejercicio52punto5();
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


#endif // UNIDAD5_2_H
