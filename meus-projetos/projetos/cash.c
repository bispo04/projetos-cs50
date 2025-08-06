#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float cash = get_float("what is the value you want to exchanger?");

    while (cash < 0)
    {
        cash = get_float("what is the value you want to exchanger?");
    }
    int cents = round(cash * 100);
    int v = cents / 25;
    cents = cents % 25;
    int d = cents / 10;
    cents = cents % 10;
    int c = cents / 5;
    cents = cents % 5;
    int u = cents / 1;
    cents = cents % 1;
    printf("Used %i coin(s) of 25 cents.\n", v);
    printf("Used %i coin(s) of 10 cents.\n", d);
    printf("Used %i coin(s) of 5 cents.\n", c);
    printf("Used %i coin(s) of 1 cent.\n", u);
    printf("Were used, %i coins in total.\n", v + d + c + u);

}
