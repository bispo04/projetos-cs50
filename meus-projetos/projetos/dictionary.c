#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

// Estrutura de um nó (elemento da lista)
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Define o tamanho da tabela hash (quantidade de "gavetas")
#define N 10000

// A tabela hash em si (array de ponteiros para nós)
node *table[N];

// Contador de palavras carregadas
unsigned int word_count = 0;

// Função hash (você pode ajustar ou melhorar depois)
unsigned int hash(const char *word)
{
    unsigned long hash = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        hash = (hash * 31 + tolower(word[i])) % N;
    }
    return hash;
}

// Carrega o dicionário na memória
bool load(const char *dictionary)
{
    // Abre o arquivo
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    // Variável temporária para guardar cada palavra lida
    char word[LENGTH + 1];

    // Lê palavra por palavra
    while (fscanf(file, "%s", word) != EOF)
    {
        // Cria um novo nó
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            fclose(file);
            return false;
        }

        // Copia a palavra para o nó
        strcpy(new_node->word, word);
        new_node->next = NULL;

        // Descobre o índice pela função hash
        int index = hash(word);

        // Insere o nó no início da lista encadeada
        new_node->next = table[index];
        table[index] = new_node;

        // Incrementa o número de palavras
        word_count++;
    }

    fclose(file);
    return true;
}

// Verifica se a palavra está no dicionário
bool check(const char *word)
{
    // Converte a palavra para minúsculo
    char temp[LENGTH + 1];
    int i = 0;
    while (word[i] && i < LENGTH)
    {
        temp[i] = tolower(word[i]);
        i++;
    }
    temp[i] = '\0';

    // Gera o índice
    int index = hash(temp);

    // Percorre a lista procurando a palavra
    node *cursor = table[index];
    while (cursor != NULL)
    {
        if (strcmp(cursor->word, temp) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }

    return false;
}

// Retorna o número de palavras no dicionário
unsigned int size(void)
{
    return word_count;
}

// Libera toda a memória alocada
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}
