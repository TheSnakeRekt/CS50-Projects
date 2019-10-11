#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float m ;
    int changeOwed ;
    do
    {
        m = get_float("Change owed: "); //stores user input
        changeOwed = round(m * 100); //rounds it to int to not have errors on comparision
    }
    while (changeOwed <= 0) ; //waits for input of user and verifies if its not negative or = to 0 or empty or string


    int nq = 0;

    while (changeOwed >= 25)
    {
        changeOwed = changeOwed - 25 ;
        nq++;

        if (changeOwed == 0)
        {
            printf("%i\n", nq);
            return 0;
        }
    } //checks for how many quarters

    int nd = 0;

    while (changeOwed >= 10)
    {
        changeOwed = changeOwed - 10 ;
        nd ++;

        if (changeOwed == 0)
        {
            printf("%i\n", nq + nd);
            return 0;
        }
    } //checks for how many dimes

    int nn = 0;

    while (changeOwed >= 5)
    {
        changeOwed = changeOwed - 5 ;
        nn ++;

        if (changeOwed == 0)
        {
            printf("%i\n", nq + nd + nn);
            return 0;
        }
    } //checks for how many niquels

    int np = 0;

    while (changeOwed > 0)
    {
        changeOwed = changeOwed - 1 ;
        np ++;

        if (changeOwed == 0)
        {
            printf("%i\n", nq + nd + nn + np);
            return 0;
        }
    } //checks for how many pennies
}
