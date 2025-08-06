#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // loop tamanho inicial
    int isize;

    do
    {
        isize = get_int("Tell me what is the initial population size? ");
    }
    while (isize < 9);

    // loop tamanho final
    int esize;

    do
    {
        esize = get_int("Tell me what is the end population size? ");
    }
    while (esize < isize);

    // contagem dos anos
    int years = 0;

    while (isize < esize)
    {
        int born = isize / 3;
        int dead = isize / 4;
        isize = isize + born - dead;
        years++;
    }

    printf("Years: %i\n", years);
}

