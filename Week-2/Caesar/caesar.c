#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to encrypt a character using Caesar's cipher
char encrypt(char c, int key)
{
    char encrypted;
    if (isupper(c))
    {
        encrypted = (c - 'A' + key) % 26 + 'A';
    }
    else if (islower(c))
    {
        encrypted = (c - 'a' + key) % 26 + 'a';
    }
    else
    {
        encrypted = c;
    }
    return encrypted;
}

int main(int argc, char *argv[])
{
    // Check if correct number of command-line arguments provided
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Get key from command-line argument
    int key = atoi(argv[1]);

    // Check if key is a non-negative integer
    if (key < 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Get plaintext from user
    char plaintext[1000];
    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // Encrypt plaintext using Caesar's cipher
    printf("ciphertext: ");
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        char encrypted = encrypt(plaintext[i], key);
        printf("%c", encrypted);
    }

    return 0;
}
