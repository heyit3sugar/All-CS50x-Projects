// Implements a dictionary's functionality
#include <strings.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Number of words in dictionary
unsigned int word_count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Hash word to get bucket index
    unsigned int index = hash(word);

    // Traverse linked list at that index
    for (node *cursor = table[index]; cursor != NULL; cursor = cursor->next)
    {
        // If word is found in linked list, return true
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
    }

    // Word was not found
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Simple hash function that hashes based on first letter of word
    return tolower(word[0]) - 'a';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    // Buffer for storing word
    char word[LENGTH + 1];

    // Scan through dictionary file, adding words to hash table
    while (fscanf(file, "%s", word) != EOF)
    {
        // Allocate memory for new node
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            fclose(file);
            return false;
        }

        // Copy word into new node
        strcpy(new_node->word, word);

        // Hash word to get bucket index
        unsigned int index = hash(word);

        // Insert node into hash table
        new_node->next = table[index];
        table[index] = new_node;

        // Increment word count
        word_count++;
    }

    // Close dictionary file
    fclose(file);

    // Dictionary was loaded successfully
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Iterate over hash table
    for (int i = 0; i < N; i++)
    {
        // Free linked list at current index
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
        table[i] = NULL;
    }

    // Reset word count
    word_count = 0;

    // Dictionary was unloaded successfully
    return true;
}