#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// verify if the argument has alphabets only
int check_alpha(string argv);

// verify if the argument has no duplicates
int check_double(string argv);

// applies the cipher protocol
string cipher_text(string key, string pt);

int main(int argc, string argv[])
{
    // check of there is an argument given
    if (argc != 2)
    {
        printf("Error: missing argument.\n");
        return 1;
    }
    // check if it has 26 char
    else if (strlen(argv[1]) != 26)
    {
        printf("Error: argument must contain exactly 26 unique alphabetic characters.\n");
        return 1;
    }
    // check if it has alphabet char
    else if (check_alpha(argv[1]) == 0)
    {
        printf("Error: argument must contain exactly 26 unique alphabetic characters only.\n");
        return 1;
    }
    // check if it has no duplicates
    else if (check_double(argv[1]) == 0)
    {
        printf("Error: argument must be unique.\n");
        return 1;
    }

    string plaintxt = get_string("plaintext: ");
    printf("ciphertext: %s\n", cipher_text(argv[1], plaintxt));
    return 0;
}

// verify if the argument has alphabets only
int check_alpha(string text)
{
    int status = 1, i = 0;
    while (status != 0 && i < 26)
    {
        status = isalpha(text[i]);
        i++;
    }
    return status;
}

// verify if the argument has no duplicates
int check_double(string text)
{
    int status = 1, i = 0;

    // temporary array to list down all the checked characters
    char temp[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    // for every character, check if it has duplicates
    while (status != 0 && i < 26)
    {
        int x = ((int) toupper(text[i])) - 65;
        if (temp[x] == '0')
        {
            status = 0;
        }
        else
        {
            temp[x] = '0';
            i++;
        }
    }
    return status;
}

// applies the cipher protocol
string cipher_text(string key, string pt)
{
    for (int i = 0, l = strlen(pt); i < l; i++)
    {
        int t = (int) pt[i];
        if (t >= 65 && t <= 90)
        {
            int pos = t - 65;
            pt[i] = toupper(key[pos]);
        }
        else if (t >= 97 && t <= 122)
        {
            int pos = t - 97;
            pt[i] = tolower(key[pos]);
        }
        else
        {
            pt[i] = t;
        }
    }
    return pt;
}