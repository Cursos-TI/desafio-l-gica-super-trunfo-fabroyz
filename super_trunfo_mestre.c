#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Aluno: Fabrício Silva Costa

int main() {
    // Variáveis dos países cadastrados
    char nomePais1[] = "Brasil";
    char nomePais2[] = "Japão";

    float populacaoPais1 = 214000000;
    float populacaoPais2 = 125000000;
    float areaPais1 = 8510000;
    float areaPais2 = 377975;
    float pibPais1 = 2000000;
    float pibPais2 = 5000000;
    int pontosTuristicosPais1 = 50;
    int pontosTuristicosPais2 = 80;

    float densidadePais1 = populacaoPais1 / areaPais1;
    float densidadePais2 = populacaoPais2 / areaPais2;

    int escolha1, escolha2;

    printf("== SUPER TRUNFO ==\n");
    printf("\nCartas em jogo:\n");
    printf("1️⃣  %s\n", nomePais1);
    printf("2️⃣  %s\n\n", nomePais2);

    // PRIMEIRO ATRIBUTO A SER ESCOLHIDO
    printf("Escolha o primeiro atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Escolha: ");
    scanf("%d", &escolha1);

    // SEGUNDO ATRIBUTO A SER ESCOLHIDO
    printf("\nEscolha o segundo atributo:\n");
    for (int i = 1; i <= 5; i++) {
        if (i == escolha1) continue;
        switch (i) {
            case 1: printf("1 - População\n"); break;
            case 2: printf("2 - Área\n"); break;
            case 3: printf("3 - PIB\n"); break;
            case 4: printf("4 - Pontos Turísticos\n"); break;
            case 5: printf("5 - Densidade Demográfica\n"); break;
        }
    }
    printf("Escolha: ");
    scanf("%d", &escolha2);

    // Código que evita que o usuário escolha o mesmo atributo duas vezes
    if (escolha1 == escolha2) {
        printf("\nOs atributos escolhidos devem ser diferentes.\n");
        return 1;
    }

    float valor1Atributo1 = 0;
    float valor2Atributo1 = 0;
    float valor1Atributo2 = 0;
    float valor2Atributo2 = 0;

    // PRIMEIRO ATRIBUTO A SER COMPARADO
    switch (escolha1) {
        case 1: // População
            valor1Atributo1 = populacaoPais1;
            valor2Atributo1 = populacaoPais2;
            break;
        case 2: // Área
            valor1Atributo1 = areaPais1;
            valor2Atributo1 = areaPais2;
            break;
        case 3: // PIB
            valor1Atributo1 = pibPais1;
            valor2Atributo1 = pibPais2;
            break;
        case 4: // Pontos turísticos
            valor1Atributo1 = pontosTuristicosPais1;
            valor2Atributo1 = pontosTuristicosPais2;
            break;
        case 5: // Densidade
            valor1Atributo1 = densidadePais1;
            valor2Atributo1 = densidadePais2;
            break;
        default:
            printf("Opção inválida!\n");
            return 1;
    }

    // SEGUNDO ATRIBUTO A SER COMPARADO
    switch (escolha2) {
        case 1: valor1Atributo2 = populacaoPais1; valor2Atributo2 = populacaoPais2; break;
        case 2: valor1Atributo2 = areaPais1; valor2Atributo2 = areaPais2; break;
        case 3: valor1Atributo2 = pibPais1; valor2Atributo2 = pibPais2; break;
        case 4: valor1Atributo2 = pontosTuristicosPais1; valor2Atributo2 = pontosTuristicosPais2; break;
        case 5: valor1Atributo2 = densidadePais1; valor2Atributo2 = densidadePais2; break;
        default:
            printf("Opção inválida!\n");
            return 1;
    }

    // EXIBIÇÃO DOS VALORES DOS ATRIBUTOS ESCOLHIDOS
    printf("\n== COMPARAÇÃO ==\n");
    printf("Atributo 1 (Escolha %d): %.2f x %.2f\n", escolha1, valor1Atributo1, valor2Atributo1);
    printf("Atributo 2 (Escolha %d): %.2f x %.2f\n", escolha2, valor1Atributo2, valor2Atributo2);

    // PONTOS INDIVIDUAIS
    int pontosCarta1 = 0, pontosCarta2 = 0;

    // Comparação 1
    if (escolha1 == 5) { // densidade (menor vence)
        (valor1Atributo1 < valor2Atributo1) ? pontosCarta1++ : (valor2Atributo1 < valor1Atributo1) ? pontosCarta2++ : 0;
    } else {
        (valor1Atributo1 > valor2Atributo1) ? pontosCarta1++ : (valor2Atributo1 > valor1Atributo1) ? pontosCarta2++ : 0;
    }

    // Comparação 2
    if (escolha2 == 5) { // densidade (menor vence)
        (valor1Atributo2 < valor2Atributo2) ? pontosCarta1++ : (valor2Atributo2 < valor1Atributo2) ? pontosCarta2++ : 0;
    } else {
        (valor1Atributo2 > valor2Atributo2) ? pontosCarta1++ : (valor2Atributo2 > valor1Atributo2) ? pontosCarta2++ : 0;
    }

    // SOMA DOS ATRIBUTOS PARA RESULTADO FINAL
    float somaCarta1 = valor1Atributo1 + valor1Atributo2;
    float somaCarta2 = valor2Atributo1 + valor2Atributo2;

    // RESULTADO FINAL
    printf("\n== RESULTADO FINAL ==\n");
    printf("%s - Soma dos atributos: %.2f\n", nomePais1, somaCarta1);
    printf("%s - Soma dos atributos: %.2f\n", nomePais2, somaCarta2);

    if (somaCarta1 > somaCarta2) {
        printf("\n%s (carta 1) venceu!\n", nomePais1);
    } else if (somaCarta2 > somaCarta1) {
        printf("\n%s (carta 2) venceu!\n", nomePais2);
    } else {
        printf("\nEmpate!\n");
    }

    return 0;
}
