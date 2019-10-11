#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int j ;
    do
    {
        j = get_int("Height: ");
    }
    while (j <= 0 || j > 8); //retrieves user input

    for (int i = 0; i < j; i++) //loops through input to generat piramid
    {

        if (j > 1) //generates left spaces
        {
            for (int p = 1; p <= j - i - 1; p++)
            {
                printf(" ");
            }
        }

        for (int x = j - i - 1 ; x < j; x++) //generates left #'s
        {
            printf("#");
        }

        printf("  "); //generates middle space

        for (int x = j - i - 1 ; x < j; x++) //generates right #'s
        {
            printf("#");
        }

        printf("\n"); //goes to next line
    }
}
