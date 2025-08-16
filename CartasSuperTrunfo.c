#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char estado;               // Letra de A a H
    char codigo[4];            // Ex: "A01"
    char cidade[100];          // Nome com espaços
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade_populacional;
    float pib_per_capita;

} Carta;

void limparEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
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
    scanf("%d", &carta1.populacao);

    printf("Área (em km²): ");
    scanf("%f", &carta1.area);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &carta1.pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);
    limparEntrada();

    printf("\n");

    // Cadastro da Carta 2
    printf("Cadastro da Carta 2:\n");
    printf("Estado (A-H): ");
    scanf(" %c", &carta2.estado);
    limparEntrada();

         //calculando a densidade e o pib per capita da carta 1//
    carta1.densidade_populacional = carta1.populacao / carta1.area;
    carta1.pib_per_capita = (carta1.pib * 100000000) / carta1.populacao;

    printf("\n");

    printf("Código (ex: A01): ");
    fgets(carta2.codigo, sizeof(carta2.codigo), stdin);
    carta2.codigo[strcspn(carta2.codigo, "\n")] = '\0';

    printf("Nome da Cidade: ");
    fgets(carta2.cidade, sizeof(carta2.cidade), stdin);
    carta2.cidade[strcspn(carta2.cidade, "\n")] = '\0';

    printf("População: ");
    scanf("%d", &carta2.populacao);

    printf("Área (em km²): ");
    scanf("%f", &carta2.area);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &carta2.pib);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);


         //calculando a densidade e o pib per capita da carta 2//
    carta2.densidade_populacional = carta2.populacao / carta2.area;
    carta2.pib_per_capita = (carta2.pib * 100000000) / carta2.populacao;

    // Exibição
    printf("\nCarta 1:\n");
    printf("Estado: %c\n", carta1.estado);
    printf("Código: %s\n", carta1.codigo);
    printf("Nome da Cidade: %s\n", carta1.cidade);
    printf("População: %d\n", carta1.populacao);
    printf("Área: %.2f km²\n", carta1.area);
    printf("PIB: %.2f bilhões de reais\n", carta1.pib);
    printf("Número de Pontos Turísticos: %d\n", carta1.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta1.densidade_populacional);
    printf("PIB per Capita: %.2f reais\n", carta1.pib_per_capita);

    printf("\nCarta 2:\n");
    printf("Estado: %c\n", carta2.estado);
    printf("Código: %s\n", carta2.codigo);
    printf("Nome da Cidade: %s\n", carta2.cidade);
    printf("População: %d\n", carta2.populacao);
    printf("Área: %.2f km²\n", carta2.area);
    printf("PIB: %.2f bilhões de reais\n", carta2.pib);
    printf("Número de Pontos Turísticos: %d\n", carta2.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta2.densidade_populacional);
    printf("PIB per Capita: %.2f reais\n", carta2.pib_per_capita);

    return 0;
}
