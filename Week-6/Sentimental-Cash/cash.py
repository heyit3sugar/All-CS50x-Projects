from cs50 import get_float

# Prompt user for change owed
while True:
    dollars = get_float("Change owed: ")
    if dollars > 0:
        break

# Convert dollars to cents
cents = round(dollars * 100)

# Initialize coin counters
quarters = 0
dimes = 0
nickels = 0
pennies = 0

# Calculate minimum number of coins
while cents > 0:
    if cents >= 25:
        cents -= 25
        quarters += 1
    elif cents >= 10:
        cents -= 10
        dimes += 1
    elif cents >= 5:
        cents -= 5
        nickels += 1
    else:
        cents -= 1
        pennies += 1

# Print minimum number of coins
print(f"{quarters + dimes + nickels + pennies}")
