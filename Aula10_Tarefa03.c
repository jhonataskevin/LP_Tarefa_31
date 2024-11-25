#include <stdio.h>

int main() {
    FILE *inputFile, *outputFile;
    float base, altura, area;

    // Abre o arquivo de entrada (triang.in) para leitura
    inputFile = fopen("triang.in", "r");
    if (inputFile == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    // Abre o arquivo de sa�da (triang.out) para escrita
    outputFile = fopen("triang.out", "w");
    if (outputFile == NULL) {
        printf("Erro ao abrir o arquivo de sa�da.\n");
        fclose(inputFile);
        return 1;
    }

    // L� a base e a altura de cada tri�ngulo do arquivo de entrada
    while (fscanf(inputFile, "%f %f", &base, &altura) == 2) {
        // Verifica a condi��o de parada
        if (base == 0 || altura == 0) {
            break;
        }

        // Calcula a �rea do tri�ngulo
        area = (base * altura) / 2;

        // Escreve a �rea no arquivo de sa�da
        fprintf(outputFile, "Base: %.2f, Altura: %.2f, �rea: %.2f\n", base, altura, area);
    }

    // Fecha os arquivos
    fclose(inputFile);
    fclose(outputFile);

    printf("C�lculo de �reas conclu�do. Resultados armazenados em triang.out\n");

    return 0;
}

