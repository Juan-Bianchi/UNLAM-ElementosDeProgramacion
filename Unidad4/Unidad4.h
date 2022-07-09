#ifndef UNIDAD4_H
#define UNIDAD4_H

#define VERDADERO 1
#define FALSO 0
#define min(a,b)    ( ((a)<(b))? (a):(b) )
#define max(a,b)    ( ((a)>(b))? (a):(b) )
#define TODO_OK 0
#define es_alfanum(a)   (((a)>='0' && (a)<='9') || ((a)>='A' && (a)<='Z') || ((a)>='a' && (a)<='z'))
#define es_vocal(a)     ((a)=='A' || (a)=='E' || (a) =='I' || (a) =='O' || (a) == 'U' || (a) == 'a' || (a) == 'e' || (a) == 'i' || (a) =='o' || (a) == 'u' )

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

typedef int booleano;
int typedef (*esValidoNumEntre)(const void* elem, const void* inf, const void* sup);
int typedef (*esValidoNumMayA)(const void* elem, const void* inf);


int ejercicio4punto1();
int ejercicio4punto2();
int ejercicio4punto3();
int ejercicio4punto4();
int ejercicio4punto5();
int ejercicio4punto6();
int ejercicio4punto7();
int ejercicio4punto8();
int ejercicio4punto9();
int ejercicio4punto10();
int ejercicio4punto11();
int ejercicio4punto12();
int ejercicio4punto13();
int ejercicio4punto14();
int ejercicio4punto15();
int ejercicio4punto16();
int ejercicio4punto17();
int ejercicio4punto18();

#endif // UNIDAD4_H
