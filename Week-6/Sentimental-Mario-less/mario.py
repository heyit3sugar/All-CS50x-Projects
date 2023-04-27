# Prompt user for height, ensuring it's a positive integer between 1 and 8 inclusive
while True:
    try:
        height = int(input("Height: "))
        if 1 <= height <= 8:
            break
        else:
            print("Height must be between 1 and 8 inclusive.")
    except ValueError:
        print("Invalid input. Please enter an integer.")

# Generate pyramid of hashes
for i in range(height):
    # Print spaces before the hashes
    for j in range(height - i - 1):
        print(" ", end="")

    # Print hashes
    for j in range(i + 1):
        print("#", end="")

    # Print newline
    print()
