#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char estado;               // Letra de A a H
    char codigo[4];            // Ex: "A01"
    char cidade[100];          // Nome com espaços
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;

void limparEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

float calcularSuperPoder(Carta c) {
    return (float)c.populacao +
           c.area +
           c.pib +
           (float)c.pontosTuristicos +
           c.pib_per_capita +
           (1.0f / c.densidade_populacional);
}

int main() {
    Carta carta1, carta2;

    // Cadastro da Carta 1
    printf("Cadastro da Carta 1:\n");
    printf("Estado (A-H): ");
    scanf(" %c", &carta1.estado);
    limparEntrada();

    printf("Código (ex: A01): ");
    fgets(carta1.codigo, sizeof(carta1.codigo), stdin);
    carta1.codigo[strcspn(carta1.codigo, "\n")] = '\0';

    printf("Nome da Cidade: ");
    fgets(carta1.cidade, sizeof(carta1.cidade), stdin);
    carta1.cidade[strcspn(carta1.cidade, "\n")] = '\0';

    printf("População: ");
    scanf("%lu", &carta1.populacao);

    printf("Área (em km²): ");
    scanf("%f", &carta1.area);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &carta1.pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);
    limparEntrada();

    // Cálculos da Carta 1
    carta1.densidade_populacional = carta1.populacao / carta1.area;
    carta1.pib_per_capita = (carta1.pib * 100000000) / carta1.populacao;
    carta1.super_poder = calcularSuperPoder(carta1);

    // Cadastro da Carta 2
    printf("\nCadastro da Carta 2:\n");
    printf("Estado (A-H): ");
    scanf(" %c", &carta2.estado);
    limparEntrada();

    printf("Código (ex: A01): ");
    fgets(carta2.codigo, sizeof(carta2.codigo), stdin);
    carta2.codigo[strcspn(carta2.codigo, "\n")] = '\0';

    printf("Nome da Cidade: ");
    fgets(carta2.cidade, sizeof(carta2.cidade), stdin);
    carta2.cidade[strcspn(carta2.cidade, "\n")] = '\0';

    printf("População: ");
    scanf("%lu", &carta2.populacao);

    printf("Área (em km²): ");
    scanf("%f", &carta2.area);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &carta2.pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    // Cálculos da Carta 2
    carta2.densidade_populacional = carta2.populacao / carta2.area;
    carta2.pib_per_capita = (carta2.pib * 100000000) / carta2.populacao;
    carta2.super_poder = calcularSuperPoder(carta2);

    // Exibição das cartas
    printf("\nCarta 1:\n");
    printf("Estado: %c\n", carta1.estado);
    printf("Código: %s\n", carta1.codigo);
    printf("Nome da Cidade: %s\n", carta1.cidade);
    printf("População: %lu\n", carta1.populacao);
    printf("Área: %.2f km²\n", carta1.area);
    printf("PIB: %.2f bilhões de reais\n", carta1.pib);
    printf("Pontos Turísticos: %d\n", carta1.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta1.densidade_populacional);
    printf("PIB per Capita: %.2f reais\n", carta1.pib_per_capita);
    printf("Super Poder: %.2f\n", carta1.super_poder);

    printf("\nCarta 2:\n");
    printf("Estado: %c\n", carta2.estado);
    printf("Código: %s\n", carta2.codigo);
    printf("Nome da Cidade: %s\n", carta2.cidade);
    printf("População: %lu\n", carta2.populacao);
    printf("Área: %.2f km²\n", carta2.area);
    printf("PIB: %.2f bilhões de reais\n", carta2.pib);
    printf("Pontos Turísticos: %d\n", carta2.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta2.densidade_populacional);
    printf("PIB per Capita: %.2f reais\n", carta2.pib_per_capita);
    printf("Super Poder: %.2f\n", carta2.super_poder);

    // Comparações
    printf("\nComparação de Cartas:\n");
    printf("População: Carta 1 venceu (%d)\n", carta1.populacao > carta2.populacao);
    printf("Área: Carta 1 venceu (%d)\n", carta1.area > carta2.area);
    printf("PIB: Carta 1 venceu (%d)\n", carta1.pib > carta2.pib);
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", carta1.pontosTuristicos > carta2.pontosTuristicos);
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", carta1.densidade_populacional < carta2.densidade_populacional);
    printf("PIB per Capita: Carta 1 venceu (%d)\n", carta1.pib_per_capita > carta2.pib_per_capita);
    printf("Super Poder: Carta 1 venceu (%d)\n", carta1.super_poder > carta2.super_poder);

    // Contagem de vitórias
    int vitoriasCarta1 = 0;
    int vitoriasCarta2 = 0;

    vitoriasCarta1 += carta1.populacao > carta2.populacao;
    vitoriasCarta2 += carta2.populacao > carta1.populacao;

    vitoriasCarta1 += carta1.area > carta2.area;
    vitoriasCarta2 += carta2.area > carta1.area;

    vitoriasCarta1 += carta1.pib > carta2.pib;
    vitoriasCarta2 += carta2.pib > carta1.pib;

    vitoriasCarta1 += carta1.pontosTuristicos > carta2.pontosTuristicos;
    vitoriasCarta2 += carta2.pontosTuristicos > carta1.pontosTuristicos;

    vitoriasCarta1 += carta1.densidade_populacional < carta2.densidade_populacional;
    vitoriasCarta2 += carta2.densidade_populacional < carta1.densidade_populacional;

    vitoriasCarta1 += carta1.pib_per_capita > carta2.pib_per_capita;
    vitoriasCarta2 += carta2.pib_per_capita > carta1.pib_per_capita;

    vitoriasCarta1 += carta1.super_poder > carta2.super_poder;
    vitoriasCarta2 += carta2.super_poder > carta1.super_poder;

    // Mensagem final
    printf("\nResultado Final:\n");
    if (vitoriasCarta1 > vitoriasCarta2) {
        printf("🏆 Carta 1 é a vencedora com %d atributos superiores!\n", vitoriasCarta1);
    } else if (vitoriasCarta2 > vitoriasCarta1) {
        printf("🏆 Carta 2 é a vencedora com %d atributos superiores!\n", vitoriasCarta2);
    } else {
        printf("🤝 Empate! Cada carta venceu em %d atributos.\n", vitoriasCarta1);
    }

    return 0;
}