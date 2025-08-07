#include <stdio.h>

int main() {
  char Código[10];
  char Nome[50];
  int População;
  float Área;
  float Pib;
  int Pontosturisticos;

printf("Digite o Código da Cidade: ")
scanf("%s", Código);

printf("Digite o Nome da Cidade: ");
scanf("%n", Nome);

printf("Digite a Populçao: ");
scanf("%d", &População);

printf("Digite a Área (em km²): ");
scanf("%f", &Área);

printf("Digite o Pib: ");
scanf("%f", &Pib);

printf(" Digite o numero de Pontos Turisticos: ");
scanf("%d", &Pontosturisticos);



printf("/n== Carta da Cidade ==\n");
printf("Código: %s\n", Código);
printf("Nome: %n\n", Nome);
printf("População: %d\n", População);
printf("Área: %f\n", Área);
printf("Pib: %f\n", Pib);
printf("Pontos Turisticos: %d\n", Pontosturisticos);



    return 0;
}
