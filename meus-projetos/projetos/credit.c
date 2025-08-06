#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Solicita o número do cartão
    long number = get_long("What is the card number? ");
    long original_number = number; // salva o número original para checar a bandeira depois

    int position = 1;
    int sum_multiplied = 0;
    int sum_regular = 0;
    int length = 0;
    int first_two_digits = 0;
    int first_digit = 0;

    // Algoritmo de Luhn
    while (number > 0)
    {
        int digit = number % 10;

        if (position % 2 == 0)
        {
            int product = digit * 2;
            if (product > 9)
            {
                sum_multiplied += (product / 10) + (product % 10);
            }
            else
            {
                sum_multiplied += product;
            }
        }
        else
        {
            sum_regular += digit;
        }

        // Captura os dois primeiros dígitos
        if (number < 100 && number > 9)
        {
            first_two_digits = number;
            first_digit = number / 10;
        }

        number /= 10;
        position++;
    }

    int total = sum_multiplied + sum_regular;

    // Checa se o número é válido
    if (total % 10 == 0)
    {
        length = position - 1; // posição começa de 1, então ajustamos

        // Verifica a bandeira do cartão
        if (length == 15 && (first_two_digits == 34 || first_two_digits == 37))
        {
            printf("AMEX\n");
        }
        else if (length == 16 && (first_two_digits >= 51 && first_two_digits <= 55))
        {
            printf("MASTERCARD\n");
        }
        else if ((length == 13 || length == 16) && first_digit == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
