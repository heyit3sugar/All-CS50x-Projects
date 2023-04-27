#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Asking the user for his name
    string name = get_string("What's your name? ");
    // Greetings
    printf("hello, %s\n", name);
}