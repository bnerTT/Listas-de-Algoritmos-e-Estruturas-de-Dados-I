#include <stdio.h>
#include <stdlib.h>

/* Questão 1) Implemente uma função que receba como parâmetro um vetor de números inteiros (vet) de tamanho n
 e retorne quantos números pares estão armazenados nesse vetor.
Essa função deve obedecer ao protótipo: int pares(int n, int* vet); */

int pares(int n, int *vet){
    int i, soma = 0;
    for (i = 0; i < n; i++){
        if (vet[i] % 2 == 0){
                soma ++;
            }
    }
    return (soma);
}

void main(){
    int i, n, s, *vet;
    printf("Insira a quantidade de números a serem digitados:\n");
    scanf("%i", &n);
    vet = (int *)(malloc(n * sizeof(int)));
    for (i = 0; i < n; i++)
    {
        printf("Insira o %i número:\n", i + 1);
        scanf("%i", &vet[i]);
    }
    s = pares(n, &vet);
    printf("São %i valores pares.", s);
    free(vet);
}