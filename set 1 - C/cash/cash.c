#include <stdio.h>
#include <cs50.h>
#include <math.h>

// prompt for change
float get_change(void);

// converts pennys to cents
int round_to_cents(float dollar);

// count coins to substitute
int count_coins(int change);

int main(void)
{
    float change = get_change();
    int coins = count_coins(round_to_cents(change));
    printf("%i\n", coins);
}

// prompt for change, which is a non-negative float number
float get_change(void)
{
    float n;
    do
    {
        n = get_float("Change owed: ");
    }
    while (n < 0);
    return n;
}

// converts the float value to int
int round_to_cents(float dollar)
{
    return round(dollar * 100);
}

// count the number of coins to be used as change
int count_coins(int change)
{
    int coins = 0;
    int cents[4] = {25, 10, 5, 1};
    int i = 0;

    while (change > 0)
    {
        coins += (change / cents[i]);
        change %= cents[i];
        i++;
    }
    return coins;
}