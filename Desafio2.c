/*O programa em C abaixo utiliza a biblioteca stdio.h para criar um programa que ajuda os analistas do Banco Central do Brasil a determinar qual triênio, dentro de um determinado intervalo de anos, teve o maior crescimento médio do PIB.
A entrada consiste em um número inteiro positivo representando o número de anos considerados, seguido dos valores do PIB de cada ano informados pelo usuário. O programa então calcula o crescimento percentual anual com base nos valores de PIB informados e armazena em um array. Em seguida, calcula a média de crescimento de cada triênio, que é composto por três anos consecutivos, e armazena em outro array.
O programa determina o triênio com a maior média de crescimento, comparando as médias de crescimento calculadas e armazenando a maior média encontrada, bem como os anos de início e fim do triênio correspondente. Em caso de empate, o programa considera o triênio mais antigo.
Por fim, o programa exibe o resultado contendo a frase "A maior media de crescimento foi entre os anos X e Y: Z", onde X e Y representam o primeiro e o último ano do triênio com a maior média de crescimento, e Z é a média de crescimento percentual desse triênio com uma casa decimal.
Integrante: Roberto Santana Silva RA: 2760482121012. 
*/
#include <stdio.h>

int main() {
    int n; 
    float pib[50]; 
    float crescimento[49]; 
    float mediaCrescimento[47]; 
    float maiorMedia = 0; 
    int anoInicio = 0; // Variável para armazenar o ano de início do triênio com a maior média
    int anoFim = 0; // Variável para armazenar o ano de fim do triênio com a maior média

    // Leitura do número de anos considerados
    printf("Digite o numero de anos considerados: ");
    scanf("%d", &n);

    // Leitura do PIB de cada ano
    for (int i = 0; i < n; i++) {
        printf("Digite o PIB do ano %d: ", i);
        scanf("%f", &pib[i]);
    }

    // Cálculo do crescimento percentual anual
    for (int i = 1; i < n; i++) {
        crescimento[i-1] = ((pib[i] - pib[i-1]) / pib[i-1]) * 100;
    }

    // Cálculo da média de crescimento de cada triênio
    for (int i = 0; i < n-2; i++) {
        mediaCrescimento[i] = (crescimento[i] + crescimento[i+1] + crescimento[i+2]) / 3;
        // Verifica se a média de crescimento atual é maior do que a maior média encontrada até o momento
        if (mediaCrescimento[i] > maiorMedia) {
            maiorMedia = mediaCrescimento[i];
            anoInicio = i;
            anoFim = i + 2;
        }
    }

    printf("A maior media de crescimento foi entre os anos %d e %d: %.1f%%\n", anoInicio, anoFim, maiorMedia);

    return 0;
}
