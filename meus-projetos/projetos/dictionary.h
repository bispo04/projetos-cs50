#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

#define LENGTH 45

// Funções obrigatórias
bool check(const char *word);
bool load(const char *dictionary);
unsigned int size(void);
bool unload(void);
unsigned int hash(const char *word);

#endif
