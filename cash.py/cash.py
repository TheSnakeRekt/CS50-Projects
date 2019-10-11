from cs50 import get_float

# user input
while True:
    owed = get_float("Change owed: ")
    if owed > 0:
        break

# rounds result
x = round(owed * 100)

# array of available coins
coins = [25, 10, 5, 1]

nC = 0

# Starts to loop through the biggest coin and subtracts it only if the owed change is bigger then the coin
for i in coins:
    while i <= x:
        x = x - i
        nC += 1

print(nC)