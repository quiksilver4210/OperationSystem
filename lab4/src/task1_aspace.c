/* Example code for Think OS.

Copyright 2015 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>

int global;

int main ()
{
    int local = 5; //стековая переменная
    void *p = malloc(128); //указатель на выделенную память
    void *n_p = malloc(128);// указатель на новую выделенную память
    int n_local = 10;//новая стековая переменная

    printf ("Address of main is %p\n", main);
    printf ("Address of global is %p\n", &global);// адрес глобальной переменной
    printf ("Address of local is %p\n", &local);/// адрес локальной переменной
    printf ("Address of n_local is %p\n", &n_local);//адрес новой локальной переменной
    printf ("Address of p is %p\n", p);// адрес выделенной памяти
    printf ("Address of n_p %p\n", n_p);//адрес новой выделенной памяти
    printf ("Address of pointer p is %p\n", &p); // адрес, по котором хранится значение адреса выделенной памяти




    return 0;
}