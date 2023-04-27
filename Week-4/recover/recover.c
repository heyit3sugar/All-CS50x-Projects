#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check command line arguments
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Open input file
    FILE *infile = fopen(argv[1], "r");
    if (infile == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    // Create buffer to store block of data
    BYTE buffer[512];

    // Initialize variables
    int count = 0;
    FILE *outfile = NULL;
    char filename[8];

    // Read blocks of data from input file
    while (fread(buffer, sizeof(BYTE), 512, infile) == 512)
    {
        // Check if block is the start of a new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Close previous JPEG file if open
            if (outfile != NULL)
            {
                fclose(outfile);
            }

            // Create new JPEG file
            sprintf(filename, "%03i.jpg", count);
            outfile = fopen(filename, "w");
            if (outfile == NULL)
            {
                fclose(infile);
                printf("Could not create %s.\n", filename);
                return 1;
            }

            // Increase JPEG count
            count++;
        }

        // Write data to current JPEG file
        if (outfile != NULL)
        {
            fwrite(buffer, sizeof(BYTE), 512, outfile);
        }
    }

    // Close input and output files
    fclose(infile);
    if (outfile != NULL)
    {
        fclose(outfile);
    }

    return 0;
}
