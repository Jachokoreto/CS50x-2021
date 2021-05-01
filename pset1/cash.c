#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    float change_owed;
    int cents;
    do
    {
        change_owed = get_float("Change owed :");
        cents = round(change_owed * 100);
    }
    while (change_owed <= 0);
    
    int coins = 0;
    
    //count quater use
    if (cents >= 25)
    {
        coins += cents / 25;
        cents = cents % 25;
        //printf("%i\n", cents);
    }
    //count dime use
    if (cents >= 10)
    {
        coins += cents / 10;
        cents = cents % 10;
        //printf("%i\n", cents);
    }
    //count nickel use
    if (cents >= 5)
    {
        coins += cents / 5;
        cents = cents % 5;
        //printf("%i\n", cents);
    }
    //count penny use
    if (cents >= 1)
    {
        coins += cents / 1;
        //printf("%i\n", cents);
    }
    printf("%i\n", coins);
}