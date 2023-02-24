#include <stdio.h>

/*Quais serão os valores de x, y e p ao final do trecho de código abaixo:

int x, y, *p;
y = 0;
p = &y;
x = *p;
x = 4;
(*p)++;
--x;
(*p) += x;
*/

/* Pela lógica feita manualmente, os valores deverão ser:
    y = 4;
    p = &y;
    x = 3;
*/
void main(){
    int x, y, *p;
    y = 0;
    p = &y;
    x = *p;
    x = 4;
    (*p)++;
    --x;
    (*p) += x;
    printf("y = %i, p = %i e x = %i",y,p,x);
}