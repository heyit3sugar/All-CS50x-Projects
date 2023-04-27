import csv
import sys


def main():

    # Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    # Read database file into a variable
    database_file = sys.argv[1]
    database = read_csv(database_file)

    # Read DNA sequence file into a variable
    sequence_file = sys.argv[2]
    sequence = read_txt(sequence_file)

    # Find longest match of each STR in DNA sequence
    matches = find_matches(database, sequence)

    # Check database for matching profiles
    match_name = check_database(matches, database)

    # Print the matching name or "No match" if no match found
    print(match_name)


def read_csv(file):
    """Reads a CSV file and returns its contents as a list of dictionaries."""
    data = []
    with open(file, "r") as csv_file:
        reader = csv.DictReader(csv_file)
        for row in reader:
            data.append(row)
    return data


def read_txt(file):
    """Reads a text file and returns its contents as a string."""
    with open(file, "r") as txt_file:
        return txt_file.read()


def find_matches(database, sequence):
    """Finds the longest match of each STR in the DNA sequence."""
    matches = {}
    for key in database[0].keys():
        if key != 'name':
            matches[key] = longest_match(sequence, key)
    return matches


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    for i in range(sequence_length):
        count = 0
        while True:
            start = i + count * subsequence_length
            end = start + subsequence_length
            if sequence[start:end] == subsequence:
                count += 1
            else:
                break
        longest_run = max(longest_run, count)
    return longest_run


def check_database(matches, database):
    """Checks the database for matching profiles."""
    for row in database:
        match = True
        for key, value in matches.items():
            if int(row[key]) != value:
                match = False
                break
        if match:
            return row['name']
    return "No match"


if __name__ == "__main__":
    main()
