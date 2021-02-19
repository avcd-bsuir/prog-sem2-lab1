// License: CC BY-NC-SA 4.0
/*
 * task1.c
 *
 * Find the n / 8 without division or modulus.
 *
 * Written by AlexeyFilich
 * 19 feb 2021
 */

#include <stdio.h>
#include "Interactions.h"

typedef struct {
    int reminder : 3;
    int quotient : 29;
} Number;

int main(int argc, char* args[]) {
    Number num;
    aScanCheck("Input number: ", "%d", &num);
    printf("Quotient: %d\n", num.quotient);
    return 0;
}
