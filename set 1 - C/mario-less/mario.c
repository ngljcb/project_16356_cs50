#include <stdio.h>
#include <cs50.h>

// abstract method that deals with prompting int, range min-max inclusive
int get_int_onRange(int min, int max);

// abstract method contruct the pyramid of the given height
void build_pyramid(int height);

int main(void)
{
    int height = get_int_onRange(1, 8);
    build_pyramid(height);
}

// method implements get_int_onRange
int get_int_onRange(int min, int max)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < min || n > max);
    return n;
}

// method implements get_int_onRange
void build_pyramid(int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 1; j < height - i; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}