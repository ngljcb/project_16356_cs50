#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// calculates the readability of the given text according to Coleman-Liau index
int calculate_readability(string text);

// iterates though the text & count the letters, words, & sentences
void check_text(int counter[], string text);

// calculate the index grade
int coleman_liau_index(int counter[]);

// prints the result accordingly
void print_result(int index);

int main(void)
{
    string text = get_string("Text: ");
    print_result(calculate_readability(text));
}

// calculates the readability of the given text according to Coleman-Liau index, returns an int
int calculate_readability(string text)
{
    int counter[3] = {0, 1, 0}; // letters, words, sentences
    check_text(counter, text);
    return coleman_liau_index(counter);
}

// iterates though the text & count the letters, words, & sentences
void check_text(int counter[], string text)
{
    for (int i = 0, lenght = strlen(text); i < lenght; i++)
    {
        if (isalpha(text[i]) != 0)
        {
            ++counter[0];
        }
        else if (isspace(text[i]) != 0)
        {
            ++counter[1];
        }
        else if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            ++counter[2];
        }
    }
}

// calculate the index grade
int coleman_liau_index(int counter[])
{
    float l = (float) counter[0] / counter[1] * 100;
    float s = (float) counter[2] / counter[1] * 100;
    float index = 0.0588 * l - 0.296 * s - 15.8;
    return round(index * 1);
}

// prints the result accordingly
void print_result(int index)
{
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}