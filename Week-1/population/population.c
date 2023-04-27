#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for start size
    int startSize;
    do
    {
        startSize = get_int("Start size: ");
    } while (startSize < 9); // Ensure start size is greater than or equal to 9

    // Prompt for end size
    int endSize;
    do
    {
        endSize = get_int("End size: ");
    } while (endSize < startSize); // Ensure end size is greater than or equal to start size

    // Calculate number of years until we reach threshold
    int years = 0;
    while (startSize < endSize)
    {
        int born = startSize / 3;
        int passedAway = startSize / 4;
        startSize += born - passedAway;
        years++;
    }

    // Print number of years
    printf("Years: %d\n", years);

    return 0;
}
