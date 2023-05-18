from asyncore import read
import csv
import sys


def main():
    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python tournament.py DATABASE SAMPLE")

    # TODO: Read database file into a variable
    with open(sys.argv[1], 'r') as file1:
        reader = csv.DictReader(file1)
        # database is a list contains all of the dna sequence information
        database = []
        width = len(reader.fieldnames)
        for row in reader:
            # each person dna information is a dictionary
            personDNA = {}
            for i in range(width):
                item = reader.fieldnames[i]
                personDNA.update({item: row[item]})
            database.append(personDNA)

    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2], 'r') as file2:
        sampleDNA = file2.read()

    # TODO: Find longest match of each STR in DNA sequence
    matchCounts = {}
    for i in range(1, width):
        item = reader.fieldnames[i]
        matchCounts.update({item: 0})
        matchCounts[item] = longest_match(sampleDNA, item)

    # TODO: Check database for matching profiles
    for dataDNA in database:
        flag = True
        for i in range(1, width):
            item = reader.fieldnames[i]
            flag &= (int(dataDNA[item]) == matchCounts[item])
            if flag == False:
                continue
        if flag == True:
            break

    if flag:
        print(f"%s " % dataDNA['name'])
    else:
        print('Not match')

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
