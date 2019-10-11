from cs50 import get_string

# waits for user input
while True:
    s = get_string("Whats your name: ")

    if s != "":
        break

# prints user input with hello
print(f"Hello,{s}")