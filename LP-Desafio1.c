/*O programa em C desenvolvido abaixo é um verificador de senha que verifica se uma senha digitada pelo usuário atende a um conjunto de critérios especificados. O programa utiliza apenas as bibliotecas padrão do C, stdio.h, string.h e ctype.h.
O programa inicia solicitando ao usuário o número de palavras no dicionário, as palavras do dicionário em letras minúsculas e a senha digitada pelo usuário. Em seguida, ele verifica se a senha atende aos seguintes critérios:
Possui pelo menos 8 caracteres.
Possui pelo menos uma letra maiúscula.
Possui pelo menos uma letra minúscula.
Possui pelo menos um número.
Possui pelo menos um dos seguintes símbolos: !, ?, #, @, $.
Não é um palíndromo, ou seja, não é igual quando os caracteres são revertidos.
Não contém nenhuma palavra reservada do dicionário.
Se a senha atender a todos os critérios, o programa exibe uma mensagem indicando que a senha é válida. Caso contrário, o programa exibe uma mensagem indicando que a senha é inválida e, se aplicável, que contém uma palavra reservada do dicionário.
Integrantes: Roberto Santana Silva RA: 2760482121012, Marco Túlio Santana RA: 2760482121043

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Função para verificar se uma string é um palíndromo
int isPalindrome(char *str) {
    int len = strlen(str);
    int i = 0, j = len - 1;
    while (i < j) {
        if (str[i++] != str[j--]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n;
    printf("Digite o número de palavras no dicionário: ");
    scanf("%d", &n);

    while (getchar() != '\n');

    // Lendo as palavras do dicionário
    char dictionary[50][20];
    printf("Digite as palavras do dicionário em letras minúsculas, separadas por espaço:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", dictionary[i]);
    }

    while (getchar() != '\n');

    char password[51];
    printf("Digite a senha: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0'; // Removendo o caractere de nova linha

    // Verificando se a senha atende aos critérios
    int len = strlen(password);
    int hasUppercase = 0;
    int hasLowercase = 0;
    int hasDigit = 0;
    int hasSymbol = 0;

    for (int i = 0; i < len; i++) {
        if (isupper(password[i])) {
            hasUppercase = 1;
        } else if (islower(password[i])) {
            hasLowercase = 1;
        } else if (isdigit(password[i])) {
            hasDigit = 1;
        } else if (strchr("!?#@$", password[i]) != NULL) {
            hasSymbol = 1;
        }
    }

    if (len < 8 || !hasUppercase || !hasLowercase || !hasDigit || !hasSymbol || isPalindrome(password)) {
        printf("Senha inválida.\n");
    } else {
        // Verificando se a senha contém alguma palavra reservada do dicionário
        char *token = strtok(password, " ");
        while (token != NULL) {
            for (int i = 0; i < n; i++) {
                if (strcmp(token, dictionary[i]) == 0) {
                    printf("Senha inválida. Contém uma palavra reservada do dicionário.\n");
                    return 0;
                }
            }
            token = strtok(NULL, " ");
        }
        printf("Senha válida.\n");
    }

    return 0;
}
