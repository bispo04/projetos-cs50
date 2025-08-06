#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

int POINTS[ALPHABET_SIZE] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8,
                             5, 1, 3, 1, 1, 3, 10, 1, 1, 1,
                             1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    string player1 = get_string("Player 1, escreva uma palavra: ");
    string player2 = get_string("Player 2, escreva outra palavra: ");

    int score1 = compute_score(player1);
    int score2 = compute_score(player2);

    // Mostrar pontuação de cada jogador
    printf("Pontuação do Player 1: %i\n", score1);
    printf("Pontuação do Player 2: %i\n", score2);

    if (score1 > score2)
    {
        printf("Parabéns, Player 1 venceu!\n");
    }
    else if (score2 > score1)
    {
        printf("Parabéns, Player 2 venceu!\n");
    }
    else
    {
        printf("Empate! Ninguém venceu.\n");
    }
}

int compute_score(string word)
{
    int score = 0;
    int length = strlen(word);

    for (int i = 0; i < length; i++)
    {
        char c = word[i];

        if (isalpha(c))
        {
            int index = toupper(c) - 'A';
            score += POINTS[index];
        }
    }

    return score;
}
