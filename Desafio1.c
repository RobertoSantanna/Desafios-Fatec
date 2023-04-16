/* O objetivo deste programa é calcular a circunferência de um planeta com base na observação do ângulo A, entre duas localidades C1 e C2, e na distância D, em estádios, entre elas. 
Para isso, o programa recebe a entrada composta da distância D e do ângulo A, um número em cada linha, e utiliza a fórmula desenvolvida por Eratóstenes para calcular a circunferência Ce, em estádios, e Ckm, em quilômetros, do planeta.
Roberto Santana Silva 
RA: 2760482121012 */

#include <stdio.h>

int main() {
    float d, a, ce, ckm;
    const float pi = 3.14159265359; // valor aproximado de pi
    
    // leitura dos valores de d e a
    printf("Digite a distancia entre as localidades em estadios: ");
    scanf("%f", &d);
    printf("Digite o angulo observado entre as localidades: ");
    scanf("%f", &a);
    
    // cálculo da circunferência em estádios e em quilômetros
    ce = (d * 360) / a;
    ckm = ce * 176.4 / 1000;
    
    // impressão dos resultados
    printf("Circunferencia do planeta em estadios: %.1f\n", ce);
    printf("Circunferencia do planeta em quilometros: %.1f\n", ckm);

    return 0;
}
