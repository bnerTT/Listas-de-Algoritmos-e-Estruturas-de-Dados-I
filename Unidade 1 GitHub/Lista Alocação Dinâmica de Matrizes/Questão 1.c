#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
    //Declarando o tamanho do mapa
    int m,n;
    printf("Quantas linhas são necessárias?\n");
    scanf("%i", &m);
    printf("Quantas colunas são necessárias?\n");
    scanf("%i", &n);
    
    //Alocando a matriz para o mapa
    char **mapa;
    mapa = (char**) malloc(m*sizeof(char*));
    if (mapa == NULL){
        printf("Espaço insuficiente!\n");
        exit(1);
    }
    for (int i = 0; i < m;i++){
        mapa[i] = (char*) malloc(n*sizeof(char));
        if ((mapa[i])==NULL){
            printf("Espaço insuficiente!\n");
        }  
    }

    //Recebendo o mapa
    printf("Escreva o mapa, linha por linha\n");
    printf("Legenda:\n'.' representa água\n'#' representa terra\nTerritório em branco representa ocupado por água\n");
    for(int i = 0; i < m;i++){
        printf("Escreva a %i linha com %i colunas.\n", i+1, n);
        scanf(" %[^\n]", mapa[i]);
    }

    //Imprimindo o mapa
    printf("Esse é o mapa:\n");
    for(int i = 0; i < m; i++){
        printf("%s",mapa[i]);
        printf("\n");
    }

    int costa = 0;

    for(int i = 0; i < m; i++){
        for(int j = 0;j < n;j++){
            if((mapa[i][j]) == '#'){
                if(i == 0){ //Se estiver na primeira linha
                    if(j == 0 && (mapa[i][j+1]) == '.'){ //Se estiver na primeira coluna
                        costa++;
                    }
                    else if( j == n-1 && (mapa[i][j-1]) == '.'){ //Se estiver na última coluna
                        costa++;
                    }
                    else if ((mapa[i][j-1]) == '.' || (mapa[i][j+1]) == '.' || (mapa[i+1][j]) == '.'){ //Condições normais da primeira linha
                        costa++;}
                }
                else if(i == m-1){ //Se estiver na última linha
                    if(j == 0 && (mapa[i][j+1]) == '.'){ //Se estiver na primeira coluna
                        costa++;
                    }
                    else if( j == n-1 && (mapa[i][j-1]) == '.'){ //Se estiver na última coluna
                        costa++;}
                    else if ((mapa[i][j-1]) == '.' || (mapa[i][j+1]) == '.' || (mapa[i-1][j]) == '.'){
                        costa++;}
                }
                else if(j == 0){    //Se estiver na primeira coluna
                    if((mapa[i][j+1]) == '.' || (mapa[i-1][j]) == '.' || (mapa[i+1][j]) == '.'){
                        costa ++;}
                }
                else if(j == n-1){  //Se estiver na última coluna
                    if((mapa[i][j-1]) == '.' || (mapa[i-1][j]) == '.' || (mapa[i+1][j]) == '.'){
                        costa ++;}
                }
                else if ((mapa[i][j-1]) == '.' || (mapa[i][j+1]) == '.' || (mapa[i-1][j]) == '.' || (mapa[i+1][j]) == '.'){ //Se não atender nenhum dos critérios anteriores
                        costa++;
                }
            }
        }              
    }
    printf("A costa tem %i quadrados de medida.", costa);



            

    for(int i = 0; i < n;i++){
        free(mapa[i]);
    }
    free(mapa);
    return 0;
}
