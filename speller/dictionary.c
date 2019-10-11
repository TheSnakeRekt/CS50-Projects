// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents number of buckets in a hash table
#define N 26

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Represents a hash table
node *hashtable[N] ;

//function prototype
//Total words in dictionary
int dictTotal = 0 ;

// Hashes word to a number between 0 and 25, inclusive, based on its first letter
unsigned int hash(const char *word)
{
    return tolower(word[0]) - 'a';
}


// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{


    // Initialize hash table
    for (int i = 0; i < N + 1; i++)
    {
        hashtable[i] = NULL;
    }

    // Open dictionary
    FILE *file = fopen(dictionary, "r");

    if (file == NULL)
    {
        unload();
        return false;
    }

    // Buffer for a word
    char word[LENGTH + 1];

    // Insert words into hash table
    while (fscanf(file, "%s", word) != EOF)
    {

        int pos = hash(word);
        node *h = malloc(sizeof(node));

        strncpy(h->word, word, sizeof(word));
        h->next = NULL;

        if (hashtable[pos] != NULL)
        {
            h->next = hashtable[pos];
            hashtable[pos] = h;
        }
        else
        {
            hashtable[pos] = h;
        }

        dictTotal++;
    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return dictTotal;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int l = strlen(word);
    int pos = hash(word);

    char cWord[l + 1];

    for (int i = 0; i < l; i++)
    {
        cWord[i] = tolower(word[i]);
    }

    cWord[l] = '\0';

    node *h = hashtable[pos];

    while (h != NULL)
    {
        if (strcmp(h->word, cWord) == 0)
        {
            return true;
        }
        h = h -> next;

    }


    return false;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = hashtable[i];

        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }

    return true;
}

