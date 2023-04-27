#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    // Prompt user for height, ensuring it's a positive integer between 1 and 8 inclusive
    do
    {
        height = get_int("Height: ");
    } while (height < 1 || height > 8);

    // Generate pyramid of hashes
    for (int i = 0; i < height; i++)
    {
        // Print spaces before the hashes
        for (int j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }

        // Print hashes
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }

        // Print newline
        printf("\n");
    }

    return 0;
}
