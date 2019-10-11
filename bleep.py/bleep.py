from cs50 import get_string
from sys import argv, exit

# checks prompt for only dictionary
if len(argv) != 2:
    print("Usage: python bleep.py dictionary")
    exit(1)

# asks for user input
input = get_string("What message would you like to censor?\n")

dict = argv[1]
file = open(dict, "r")

# stripps words from spaces or indents
stripped = []
for t in file:
    stripped.append(t.strip())

bleep = ""

# loops through phrase and banned words dictionary
for i in input.split():
    if i.lower() in stripped:
        for x in range(len(i)):
            bleep += "*"
        input = input.replace(i, bleep)
        bleep = ""

print(input)
