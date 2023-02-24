#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calcula_hexagono(float I, float *area,float *perimetro){
    *area = (3 * (I*I) * sqrt(3))/2;
    *perimetro = 6*I;
}

int main(){
    float lado, area, perimetro;
    printf("Insira o tamanhho do lado:");
    scanf("%f", &lado);
    calcula_hexagono(lado, &area, &perimetro);
    printf("Área = %.2f e Perímetro = %.2f", area, perimetro);

    return 0;
}