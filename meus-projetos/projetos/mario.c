#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //ask for user
    int answer = get_int("How tall do you want the pyramid to be?");

    while (answer <1 || answer >8)
    {
        //ask again
        answer = get_int("How tall do you want the pyramid to be?");
    }

    for (int line = 1; line <= answer; line++)
    {
        // imprimir espaços
       for(int space = 0; space < answer - line; space++)
       {
        printf(" ");
       }
       //imprimir hashes
        for (int j = 1; j <= line; j++)
        {
            printf("#");
        }
        // espaco no meio
        printf("  ");
        //segunda hashes
        for (int p = 1; p <= line; p++)
        {
            printf("#");
        }
        // oular para a proxima linha
        printf("\n");
     }
}
