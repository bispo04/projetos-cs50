#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: ");

    int letters = 0;
    int words = 1; // Começa em 1 pois há sempre pelo menos uma palavra
    int sentences = 0;

    // Percorre cada caractere do texto
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char c = text[i];

        if (isalpha(c))
        {
            letters++;
        }
        else if (c == ' ')
        {
            words++;
        }
        else if (c == '.' || c == '!' || c == '?')
        {
            sentences++;
        }
    }

    // Calcula L e S
    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;

    // Calcula o índice Coleman-Liau
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // Arredonda para o inteiro mais próximo
    int grade = round(index);

    // Imprime o nível de leitura
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}
