#include <stdio.h>

/* 
int main(void) {
    int x, *p;
    x = 100;
    p = x;
    printf(“Valor de p = %p\t Valor de *p = %d”, p, *p)
}

Se tentarmos compilar o programa (não o compile ainda), você acha que o compilador nos
fornece alguma mensagem? Se sim, responda:
a) Esta mensagem é de erro ou advertência? 
    R:Advertência, pois está tentando alocar um valor inteiro em um ponteiro.
b) Por que o compilador emite tal mensagem? 
    R:Porque pode gerar erros na memória.
c) Compile e execute o programa. A execução foi bem sucedida? 
    R:Não, o programa não imprimiu o que foi desejado e o compilador(Codeblocks) emitiu a seguinte mensagem:
    "||=== Build: Debug in ad (compiler: GNU GCC Compiler) ===|
warning: assignment to 'int *' from 'int' makes pointer from integer without a cast [-Wint-conversion]|
d) Modifique o trecho de código acima, de modo que nenhuma mensagem seja emitida 
pelo compilador.
R:
    int main(void) {
        int x, *p;
        x = 100;
        p = &x;
        printf("Valor de p = %p \t Valor de *p = %d", p, *p);
}

e) Compile e execute novamente o programa. A execução foi bem sucedida?
    R:Sim.

*/

int main(void) {
int x, *p;
x = 100;
p = &x;
printf("Valor de p = %p \t Valor de *p = %d", p, *p);
}