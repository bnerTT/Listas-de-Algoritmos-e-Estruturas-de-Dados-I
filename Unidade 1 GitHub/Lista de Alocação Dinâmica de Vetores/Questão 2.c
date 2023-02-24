#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calculanota(char **respostas, char *gabarito, int *aprovacao, float n){
    float questoes;
    float acerto, nota, pesoq;
    questoes = n;
    pesoq = (10/questoes);              //Atribuindo o peso para calcular a nota final de cada aluno.
    for (int i = 0; i < 10; i++){
        acerto = 0;
        nota = 0;
        for (int j = 0; j < questoes; j++){             //Comparando cada questão do aluno com as questões do gabarito. 
            if ((respostas[i][j]) == (gabarito[j])){
                acerto++;
            }
        }
        nota = acerto*pesoq;                            //Calculando a nota, se a nota do aluno for maior ou igual a 6, o aluno foi aprovado e a varíavel aprovacao é incrementada.
        printf("A nota do %i° aluno foi %.2f.\n", i + 1, nota);
        if (nota >= 6){
            (*aprovacao)++;
        }
    }
}

int main()
{

    // Primeira etapa da questão: criando um vetor para alocar as respostas no gabarito.
    int n;
    char *gabarito;
    printf("Insira o número de questões:\n");
    scanf("%i", &n);
    gabarito = (char *) malloc (n * sizeof(char));
    if (gabarito == NULL)
    {
        printf("Espaço insuficiente!");
        exit(1);
    }
    for (int i = 0; i < n; i++)
    {
        printf("Insira a resposta da %i° alternativa:\n", i + 1);
        scanf(" %[^\n]", &gabarito[i]);
    }

    // Segunda etapa da questão: criando uma matriz para alocar as respostas dos alunos.
    char **respostas;
    respostas = (char **) malloc (10 * sizeof(char*)); 
    if ((respostas) == NULL)
    {
        printf("Memória insuficiente.\n");
        exit(1);
    }
    for (int i = 0; i < 10; i++){
        respostas[i] = malloc (n * sizeof(char));
        if ((respostas[i]) == NULL)
        {
            printf("Memória insuficiente!");
            exit(1);
        }
    }

    // Terceira etapa da questão: Recebendo e alocando as respostas de cada um dos alunos para cada uma das questões: J representa o número da questão e I o aluno
    for (int i = 0; i < 10; i++)
    { 
        for (int j = 0; j < n; j++)
        {
            printf("Insira a resposta do %i° aluno na questão %i:\n", i + 1, j + 1);
            scanf(" %[^\n]", &respostas[i][j]);
        }
    }

    int aprovacao = 0;
    calculanota(respostas, gabarito, &aprovacao, (float)n);
    printf("%i por cento da turma foi aprovada.\n", ((aprovacao*100)/10)); //Calculando e imprimindo a taxa de aprovação da turma.

    for (int i = 0; i < 10; i++)
    {
        free(respostas[i]);
    }
    free(respostas);
    free(gabarito);
    return 0;
}