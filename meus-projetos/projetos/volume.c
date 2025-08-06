// volume.c

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Número de bytes no cabeçalho do arquivo .wav
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Verifica se a quantidade de argumentos está correta
    if (argc != 4)
    {
        printf("Uso correto: ./volume input.wav output.wav fator\n");
        return 1;
    }

    // Abre o arquivo de entrada
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Não foi possível abrir o arquivo %s.\n", argv[1]);
        return 1;
    }

    // Abre/cria o arquivo de saída
    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        fclose(input);
        printf("Não foi possível criar o arquivo %s.\n", argv[2]);
        return 1;
    }

    // Converte o argumento de fator (string) para float
    float factor = atof(argv[3]);

    // Lê e copia o cabeçalho (44 bytes)
    uint8_t header[HEADER_SIZE];
    fread(header, sizeof(uint8_t), HEADER_SIZE, input);
    fwrite(header, sizeof(uint8_t), HEADER_SIZE, output);

    // Buffer para armazenar cada amostra de áudio
    int16_t buffer;

    // Enquanto houver amostras no arquivo
    while (fread(&buffer, sizeof(int16_t), 1, input))
    {
        // Multiplica pelo fator para ajustar volume
        buffer = buffer * factor;

        // Grava no arquivo de saída
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }

    // Fecha os arquivos
    fclose(input);
    fclose(output);

    return 0;
}
