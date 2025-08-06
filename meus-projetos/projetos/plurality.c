#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Número máximo de candidatos
#define MAX 9

// Cada candidato tem nome e número de votos
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array de candidatos
candidate candidates[MAX];

// Número de candidatos
int candidate_count;

// Funções que você precisa implementar
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Verifica uso inválido
    if (argc < 2)
    {
        printf("Usage: ./plurality [candidate ...]\n");
        return 1;
    }

    // Popula o array de candidatos
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop sobre todos os eleitores
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Verifica se voto é válido
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Exibe o vencedor da eleição
    print_winner();
}

// Implementação da função vote
bool vote(string name)
{
    // Percorrer todos os candidatos
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Implementação da função print_winner
void print_winner(void)
{
    int max_votes = 0;

    // Descobrir o maior número de votos
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max_votes)
        {
            max_votes = candidates[i].votes;
        }
    }

    // Imprimir todos que têm o maior número de votos
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}
