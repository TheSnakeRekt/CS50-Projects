#include <stdio.h>
#include <stdlib.h>

#define BLOCK 512 //defines block size

int main(int argc, char *argv[])
{
    if (argc != 2)
    {

        printf("usage: ./recover <file>");
        return 1;
    } // checks argument count

    char *raw_file = argv[1];
    FILE *file_pntr = fopen(raw_file, "r");

    if (file_pntr == NULL)
    {
        fprintf(stderr, "Couldn't open file %s.\n", raw_file);
        return 2;
    }// checks if file was open

    unsigned char *buffer = malloc(BLOCK); //allocate memory to buffer
    char filename[8];
    int jpg_number = 0 ;
    FILE *img = NULL;


    while (fread(buffer, BLOCK, 1, file_pntr)) //loop through
    {

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) // check if its a JPEG
        {
            if (jpg_number > 0 && img != NULL) //closes previous file
            {
                fclose(img);
            }

            sprintf(filename, "%03i.jpg", jpg_number); //gives filenames as 001, 002, 003 etc

            img = fopen(filename, "w"); //opens given file

            if (img != NULL) //checks for succesfull file creation
            {
                jpg_number++;
            }
            else
            {
                fclose(file_pntr);
                fprintf(stderr, "Could not create output JPG %s", filename);
                free(buffer);
                return 3;
            }
        }
        if (!jpg_number)
        {
            continue;
        }

        fwrite(buffer, BLOCK, 1, img);
    }

    fclose(file_pntr);
    fclose(img);
    free(buffer);
    return 0;
}