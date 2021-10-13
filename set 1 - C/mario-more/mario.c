#include <stdio.h>
#include <cs50.h>

// abstract method that deals with prompting int, range min-max inclusive
int get_int_onRange(int min, int max);

// abstract method, contruct the pyramid of the given height
void build_pyramid(int height);

// abstract method, provides n blocks to put in the line
void put_block(int n);


int main(void)
{
    int height = get_int_onRange(1, 8);
    build_pyramid(height);
}

// method implements get_int_onRange, returns an integer value
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

// method implements build_pyramid, returns no value
void build_pyramid(int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 1; j < height - i; j++)
        {
            printf(" ");
        }
        put_block(i);
        printf("  ");
        put_block(i);
        printf("\n");
    }
}

// method implements put_block, returns no value
void put_block(int n)
{
    for (int i = 0; i < n + 1; i++)
    {
        printf("#");
    }
}