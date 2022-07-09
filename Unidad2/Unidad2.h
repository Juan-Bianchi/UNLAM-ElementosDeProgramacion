#ifndef UNIDAD2_H
#define UNIDAD2_H

#define TODO_OK 0
#define min(a,b)    ( ( (a)<(b) )? (a): (b) )
#define VERDADERO 1
#define FALSO 0

typedef int booleano;


typedef booleano (*ValidaNumEntre)(const void* num, const void* inf, const void* sup);
typedef booleano (*ValidaNumMayorA)(const void* num, const void* inf);


int ej2punto1();
int ej2punto2();
int ej2punto3();
int ej2punto4();
int ej2punto5();
int ej2punto6();
int ej2punto7();
int ej2punto8();
int ej2punto9();
int ej2punto10();
int ej2punto11();
int ej2punto12();
int ej2punto13();


#endif // UNIDAD2_H
