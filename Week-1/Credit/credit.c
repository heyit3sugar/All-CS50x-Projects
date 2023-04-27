#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Get credit card number from user
    long card_number;
    do
    {
        card_number = get_long("Number: ");
    } while (card_number <= 0);

    // Count number of digits in card number
    int num_digits = 0;
    long temp = card_number;
    while (temp > 0)
    {
        temp /= 10;
        num_digits++;
    }

    // Check if the number of digits is valid for a credit card
    if (num_digits != 13 && num_digits != 15 && num_digits != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    // Convert card number to array of digits
    int digits[16];
    for (int i = num_digits - 1; i >= 0; i--)
    {
        digits[i] = card_number % 10;
        card_number /= 10;
    }

    // Apply Luhn's Algorithm
    int sum = 0;
    for (int i = 1; i < num_digits; i += 2)
    {
        int product = digits[i] * 2;
        sum += product % 10 + product / 10;
    }

    for (int i = 0; i < num_digits; i += 2)
    {
        sum += digits[i];
    }

    // Check if the sum's last digit is 0
    if (sum % 10 == 0)
    {
        // Check if the card number belongs to a specific credit card company
        if (num_digits == 15 && (digits[0] == 3 && (digits[1] == 4 || digits[1] == 7)))
        {
            printf("AMEX\n");
        }
        else if (num_digits == 16 && digits[0] == 5 && (digits[1] >= 1 && digits[1] <= 5))
        {
            printf("MASTERCARD\n");
        }
        else if ((num_digits == 13 || num_digits == 16) && digits[0] == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}
