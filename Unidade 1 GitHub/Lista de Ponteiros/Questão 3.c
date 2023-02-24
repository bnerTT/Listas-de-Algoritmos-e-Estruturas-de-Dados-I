#include <stdio.h>
int main(void) {
 int a, b, c, d;
 int *p1;
 int *p2 = &a;              //p2 aloca o endereço da varíavel a, logo, alterações em *p2 irão alterar a.
 int *p3 = &c;              //p3 aloca o endereço da varíavel c, logo, alterações em *p3 irão alterar c.    
 p1 = p2;                   //p1 = p2, logo, p1 = &a.
 *p2 = 10;                  //*p2 = 10, que é o mesmo que a = 10.
 b = 20;                    //b = 20.
 int **pp;
 pp = &p1;                  //pp aloca o endereço de p1.
 *p3 = **pp;                //o conteúdo do ponteiro p3, a varíavel c, recebe o conteúdo de **pp, que é o endereço de p1 e consequentemente a varíavel a.
 int *p4 = &d;              //*p4 recebe o endereço da varíavel d
 *p4 = b + (*p1)++;         //*p4, ou varíavel d, recebe b + conteúdo de p1(10), e incrementa o conteúdo de p1, logo d = 30 e a = 11
 printf("%d\t%d\t%d\t%d\n", a, b, c, d);
 return 0;
}