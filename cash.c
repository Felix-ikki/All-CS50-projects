#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float dollars;

    do
    {
        dollars = get_float("Enter cash: ");
    }
    while (dollars <= 0);

    int cents = round(dollars * 100);
    int totalcoins = 0;

    //counting coins number 25
    while (cents >= 25)
    {
        cents -= 25;
        totalcoins++;
    }

    //counting coins number 10
    while (cents >= 10)
    {
        cents -= 10;
        totalcoins++;
    }

    //counting coins number 5
    while (cents >= 5)
    {
        cents -= 5;
        totalcoins++;
    }

    //counting coins number 1
    while (cents >= 1)
    {
        cents -= 1;
        totalcoins++;
    }

    printf("%i\n", totalcoins);
}