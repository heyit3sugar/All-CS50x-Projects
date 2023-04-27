from cs50 import get_string

# Prompt user for text
text = get_string("Text: ")

# Initialize counters
letters = 0
words = 1
sentences = 0

# Count letters, words, and sentences
for c in text:
    if c.isalpha():
        letters += 1
    elif c.isspace():
        words += 1
    elif c in [".", "!", "?"]:
        sentences += 1

# Calculate average letters and sentences per 100 words
L = letters / words * 100
S = sentences / words * 100

# Calculate Coleman-Liau index
index = round(0.0588 * L - 0.296 * S - 15.8)

# Print grade level
if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")
