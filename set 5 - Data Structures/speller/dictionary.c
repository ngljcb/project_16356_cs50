// Implements a dictionary's functionality

#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 1;

// Hash table
node *table[N];

int wordCounter = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Hash word to obtain a hash value
    int hashValue = hash(word);

    // Get initial pointer
    node *pointer = table[hashValue];

    // Check if the word is the dictionary, until NULL is reached
    while (pointer != NULL)
    {
        if (strcasecmp(word, pointer->word) == 0)
        {
            return true;
        }
        pointer = pointer->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Init sum value as integer
    int sum = 0;

    // Get the total ASCII value of the word
    for (int i = 0; i < strlen(word); i++)
    {
        sum = sum + tolower(word[i]);

    }

    // Return sum mod N as hash value
    return (sum % N);
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Return false if parameter value is NULL
    if (dictionary == NULL)
    {
        printf("Error: dictionary has NULL value.");
        return false;
    }

    // Open dictionary file
    FILE *dict = fopen(dictionary, "r");

    // Char array init
    char tempWord[LENGTH + 1];

    // Read strings from file one at a time
    while (fscanf(dict, "%s", tempWord) != EOF)
    {
        // Create a new node for each word
        node *tempNode = malloc(sizeof(node));

        // Return false if new node value is NULL
        if (tempNode == NULL)
        {
            printf("Error: New node has NULL value.");
            return false;
        }

        // Copy current word into node
        strcpy(tempNode->word, tempWord);

        // Set next node to NULL
        tempNode->next = NULL;

        // Hash word to obtain a hash value
        int hashValue = hash(tempWord);

        // Insert node into hash table at that location
        tempNode->next = table[hashValue];

        // Insert node into hash table at that location
        if (table[hashValue] == NULL)
        {
            table[hashValue] = tempNode;
        }
        else
        {
            tempNode->next = table[hashValue];
            table[hashValue] = tempNode;
        }

        // Increment dictionary size by one
        wordCounter++;
    }

    // Close file
    fclose(dict);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // Returns number of words in dictionary
    return wordCounter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Free nodes in each linked list
    for (int i = 0; i < N; i++)
    {
        // Get initial pointer
        node *pointer = table[i];

        // Iterate through the linked list and free memory
        while (pointer != NULL)
        {
            // Set temp node before freeing the memory
            node *tempNode = pointer;

            // Set pointer to next element
            pointer = pointer->next;

            // Free temp node memory
            free(tempNode);
        }

        // Return true if all nodes are freed
        if (pointer == NULL && i == N - 1)
        {
            return true;
        }
    }
    return false;
}
