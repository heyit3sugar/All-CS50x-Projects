#include <stdio.h>
#include <cs50.h>

// Function prototypes
int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    int cents = get_cents();

    // Calculate number of each coin
    int quarters = calculate_quarters(cents);
    cents = cents - (quarters * 25);
    int dimes = calculate_dimes(cents);
    cents = cents - (dimes * 10);
    int nickels = calculate_nickels(cents);
    cents = cents - (nickels * 5);
    int pennies = calculate_pennies(cents);

    // Calculate total number of coins
    int total_coins = quarters + dimes + nickels + pennies;

    printf("%d\n", total_coins);

    return 0;
}

// Function to get input from user for number of cents owed
int get_cents(void)
{
    int cents;

    do
    {
        cents = get_int("Change owed: ");
    } while (cents < 0);

    return cents;
}

// Function to calculate number of quarters
int calculate_quarters(int cents)
{
    return cents / 25;
}

// Function to calculate number of dimes
int calculate_dimes(int cents)
{
    return cents / 10;
}

// Function to calculate number of nickels
int calculate_nickels(int cents)
{
    return cents / 5;
}

// Function to calculate number of pennies
int calculate_pennies(int cents)
{
    return cents;
}
