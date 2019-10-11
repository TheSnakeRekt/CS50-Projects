#include <cs50.h>
#include <stdio.h>
#include <string.h>

//trying to not use any other libs
//Jorge Guimaraes - 13/09/2019

int main(int argc, string argv[])
{
    if (argc != 2) // checking number of arguments
    {
        printf("Usage: ./vigenere <keyword>\n");
        return 1 ;
    }

    int key[strlen(argv[1]) + 1];
    int i = 0;

    while (argv[1][i] != '\0')
    {
        char c = argv[1][i]; //storing current char
        //verifing if its alphabetical letter according to ASCII table

        if ((c >= 48 && c <= 57)  || (c <= 64 && c >= 92)  || (c <= 96 && c >= 123))
        {
            printf("Usage: ./vigenere <keyword> only alphabetical characters\n");
            return 1 ;
        }
        else if (c > 64 && c < 91)  // making A or a = 0 and Z or z = 25
        {
            key[i] = (int) argv[1][i] - 65 ;
        }
        else
        {
            key[i] = (int) argv[1][i] - 97 ;
        }
        i++ ;
    }

    i--;
    int keyMax = i;
    int h = 0;
    int j = 0;

    string text = get_string("plaintext: "); //retrieving message to encode
    printf("ciphertext: ") ;

    while (text[j] != '\0')
    {
        if (text[j] > 64 && text[j] < 91) //checking if char to encode is shifted
        {
            printf("%c", 'A' + (text[j] - 'A' + key[h]) % 26); //final offset
        }
        else if (text[j] > 95 && text[j] < 122)
        {
            printf("%c", 'a' + (text[j]  - 'a' + key[h]) % 26); //final offset
        }
        else
        {
            printf("%c", text[j]);
            h++ ;
        }

        if (h >= keyMax) // reseting array of key to repeat through msg
        {
            h = 0 ;
        }
        else
        {
            h++ ;
        }


        j++ ;
    }
    printf("\n") ;

    return 0;
}
