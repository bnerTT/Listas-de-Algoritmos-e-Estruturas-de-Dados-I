#include <stdlib.h>
#include <stdio.h>


struct dados{
    char nome[50];
    int num_doc;
    int idade;
};
typedef struct dados dados;

//Preenchendo os dados das pessoas para cada vetor.
void preenche(dados **pessoas, int n){
    for(int i = 0; i < n; i++){
        printf("Insira o nome da %i° pessoa:\n", i+1);
        scanf(" %[^\n]", pessoas[i] -> nome);
        printf("Insira o número de documento da %i° pessoa:\n", i+1);
        scanf("%i", &pessoas[i]->num_doc);
        printf("Insira a idade da %i° pessoa:\n", i+1);
        scanf("%i", &pessoas[i]->idade);
    }
}
//Imprimindo os dados que foram preenchidos anteriormente.
void imprime(dados **pessoa, int n){
    for(int i = 0; i < n; i++){
        printf("Nome:%s\nNúmero de documento:%i\nIdade:%i\n\n", pessoa[i]->nome, pessoa[i]->num_doc,pessoa[i]->idade);
    }
}

//Alterando a idade da pessoa escolhida.
void alteraidade(dados **pessoa){
    int n;
    printf("Qual o índice da pessoa que deseja atualizar a idade?\n");
    scanf("%i", &n);
    printf("Qual a idade atualizada da pessoa??\n");
    scanf("%i", &pessoa[n-1]->idade);
    printf("A idade atualizada é %i.\n", pessoa[n-1]->idade);
}

//Calculando a maior e a menor idade e armazenando o índice da respectiva maior e menor para imprimir posteriormente.
void maioridade(dados **pessoa, int n){
    int indicemaior = 0, indicemenor = 0;
    for(int i = 0; i < n;i++){
        if ((pessoa[i]-> idade) > pessoa[indicemaior] ->idade){
            indicemaior = i;
        }
        if ((pessoa[i])-> idade < pessoa[indicemenor] -> idade){
            indicemenor = i;
        }
    }
    printf("A pessoa mais velha é '%s', com %i anos.\n", pessoa[indicemaior]->nome,pessoa[indicemaior]->idade);
    printf("A pessoa mais nova é '%s', com %i anos.\n", pessoa[indicemenor]->nome,pessoa[indicemenor]->idade);
}






int main(){
    int n;
    printf("Escreva o número de pessoas a serem cadastradas:\n");
    scanf("%i", &n);
    dados **criardados = malloc(n*sizeof(dados*));
    if (criardados == NULL){
        printf("Memória insuficiente!\n");
        exit(1);
    }
    for(int i = 0; i < n; i++){
        criardados[i] = (dados*) malloc(n*sizeof(dados));
        if(criardados[i] == NULL){
            printf("Memória insuficiente!\n");
            exit(1);
        }
    }
    preenche(criardados, n);
    imprime(criardados, n);
    alteraidade(criardados);
    maioridade(criardados,n);



    return 0;
}