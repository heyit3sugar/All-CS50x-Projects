#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
    // Prompt user for input
    string text = get_string("Text: ");

    // Initialize counters for letters, words, and sentences
    int letters = 0;
    int words = 0;
    int sentences = 0;

    // Iterate over each character in the input text
    for (int i = 0; text[i] != '\0'; i++)
    {
        // Count letters (lowercase and uppercase characters)
        if (isalpha(text[i]))
        {
            letters++;
        }
        // Count words (sequences of characters separated by spaces)
        if (text[i] == ' ' || text[i + 1] == '\0')
        {
            words++;
        }
        // Count sentences (periods, exclamation points, and question marks)
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    // Calculate the average number of letters and sentences per 100 words
    float L = (float)letters / words * 100;
    float S = (float)sentences / words * 100;

    // Calculate the Coleman-Liau index
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Print the grade level
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
        printf("Grade %d\n", index);
    }

    return 0;
}
