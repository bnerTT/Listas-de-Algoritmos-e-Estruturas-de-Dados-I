#include <stdlib.h>
#include <stdio.h>

//Criação da estrutura
struct funcionario{
    char nome[50];
    float salario;
    int identificador;
    char cargo[30];
};
typedef struct funcionario funcionario;

//A função está preenchendo o vetor de funcionários em ordem crescente.
void preenche(funcionario **pessoa, int n){
    for(int i = 0; i < n; i++){
        printf("Insira o nome do %i funcionário:\n", i+1);
        scanf(" %[^\n]", pessoa[i] -> nome);
        printf("Insira o salário do %i funcionário:\n", i+1);
        scanf("%f", &pessoa[i]->salario);
        printf("Insira o identificador do %i funcionário:\n", i+1);
        scanf("%i", &pessoa[i]->identificador);
        printf("Insira o cargo do %i funcionário:\n", i+1);
        scanf(" %[^\n]", pessoa[i]->cargo);
    }
}

void imprime(funcionario **pessoa, int n){
    for(int i = 0; i < n; i++){
        printf("Nome:%s\nSalário:%.2f\nIdentificador:%i\nCargo:%s\n\n", pessoa[i]->nome, pessoa[i]->salario,pessoa[i]->identificador,pessoa[i]->cargo);
    }
}

//Alterando o salário do funcionário de acordo com o índice, por exemplo, se o funcionário foi o terceiro a ser preenchido, seu índice é 3.
void alterasalario(funcionario **pessoa){
    int n;
    printf("Qual o índice do funcionário que deseja alterar o salário?\n");
    scanf("%i", &n);
    printf("Qual o novo salário do funcionário?\n");
    scanf("%f", &pessoa[n-1]->salario);
    printf("O novo salário é %2.f.\n", pessoa[n-1]->salario);
}


//  Compara o salário dos funcionários entre si, inicialmente o índice é igual a 0, se o indice posterior for menor ou maior do que o indicemenor ou indice menor
//será armazenado respectivamente no seu índice. 
void maiorsalario(funcionario **funcionarios, int n){
    int indicemaior = 0, indicemenor = 0;
    for(int i = 0; i < n;i++){
        if ((funcionarios[i]-> salario) > funcionarios[indicemaior] ->salario){
            indicemaior = i;
        }
        if ((funcionarios[i])-> salario < funcionarios[indicemenor] -> salario){
            indicemenor = i;
        }
    }
    printf("O maior salário é para %s, %2.f\n", funcionarios[indicemaior]->cargo,funcionarios[indicemaior]->salario);
    printf("O menor salário é para %s, %2.f\n", funcionarios[indicemenor]->cargo,funcionarios[indicemenor]->salario);
}





int main(){
    //Alocando espaço na memória de acordo com a quantidade de funcionários
    int n;
    printf("Insira a quantidade de funcionários:\n");
    scanf("%i", &n);
    funcionario **criarfuncionarios = malloc(n*sizeof(funcionario*));
    if (criarfuncionarios == NULL){
        printf("Memória insuficiente!\n");
        exit(1);
    }
    for(int i = 0; i < n; i++){
        criarfuncionarios[i] = (funcionario*) malloc(n*sizeof(funcionario));
        if(criarfuncionarios[i] == NULL){
            printf("Memória insuficiente!\n");
            exit(1);
        }
    }

    preenche(criarfuncionarios,n);
    imprime(criarfuncionarios,n);
    alterasalario(criarfuncionarios);
    maiorsalario(criarfuncionarios, n);


    for(int i = 0; i < n; i++){
        free(criarfuncionarios[i]);
    }
    free(criarfuncionarios);
    return 0;
}