#include <stdio.h>
#include <stdlib.h>

// Set buffer size
#define BUFFER_SIZE 512

int main(int argc, char *argv[])
{
    // Check if number of arguments are acceptable
    if (argc != 2)
    {
        printf("Usage: ./recover card.raw");
        return 1;
    }

    // Open file
    FILE *file = fopen(argv[1], "r");

    // Check if file is not null
    if (file == NULL)
    {
        printf("Could not open file");
        return 2;
    }

    // Declare & init jpeg counter
    int jpeg_counter = 0;

    // Declare buffer char of size 512
    unsigned char buffer[BUFFER_SIZE];

    // Declare & init new jpeg file name
    char *new_jpeg_name = malloc(8 * sizeof(char));

    // Declare & init new jpeg pointer
    FILE *new_jpg = NULL;

    // Iterate through the file and fetch jpeg files
    while (fread(buffer, BUFFER_SIZE, 1, file))
    {
        // Check for jpeg header
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Create new jpeg file
            sprintf(new_jpeg_name, "%03i.jpg", jpeg_counter);

            // Set new jpeg file for writing
            new_jpg = fopen(new_jpeg_name, "w");

            // Increment jpeg counter
            jpeg_counter++;
        }

        // If new jpeg is found, continue writing
        if (new_jpg != NULL)
        {
            fwrite(buffer, BUFFER_SIZE, 1, new_jpg);
        }
    }

    // Close file
    fclose(file);

    // Close new_jpg
    fclose(new_jpg);

    // Free allocated mem for new_jpeg_name
    free(new_jpeg_name);

    return 0;
}