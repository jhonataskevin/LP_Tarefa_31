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

    // Abre o arquivo de saída (triang.out) para escrita
    outputFile = fopen("triang.out", "w");
    if (outputFile == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        fclose(inputFile);
        return 1;
    }

    // Lê a base e a altura de cada triângulo do arquivo de entrada
    while (fscanf(inputFile, "%f %f", &base, &altura) == 2) {
        // Verifica a condição de parada
        if (base == 0 || altura == 0) {
            break;
        }

        // Calcula a área do triângulo
        area = (base * altura) / 2;

        // Escreve a área no arquivo de saída
        fprintf(outputFile, "Base: %.2f, Altura: %.2f, Área: %.2f\n", base, altura, area);
    }

    // Fecha os arquivos
    fclose(inputFile);
    fclose(outputFile);

    printf("Cálculo de áreas concluído. Resultados armazenados em triang.out\n");

    return 0;
}

