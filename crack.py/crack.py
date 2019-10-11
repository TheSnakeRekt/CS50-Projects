from sys import argv, exit
from crypt import crypt


def main():
    # checks total arguments
    if len(argv) != 2:
        print("Usage: crack <hash>")
        exit(1)

    # retrieves full hash
    userInput = argv[1]

    # retrieves salt
    salt = userInput[0:2]

    # declaring alphabet splited to find lower case passwords faster
    lower_abc = "abcdefghijklmnopqrstuvwxyz"
    higher_abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

    # i am aware that this will check again for the uppercases but there is 2/3 chance that it will find sooner
    all_abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"

    # declaring array of alphabets
    alphabets = [lower_abc, higher_abc, all_abc]

    # looping array of alphabets into function that returns true if the test string is == to the hash
    for t in alphabets:
        if solver(t, userInput, salt):
            break

# hash finder


def solver(alphabet, userInput, salt):
    for i in alphabet:
        for j in alphabet:
            for k in alphabet:
                for l in alphabet:
                    for m in alphabet:
                        test = f"{m}{l}{k}{j}{i}".strip()
                        print(test)
                        if crypt(test, salt) == userInput:
                            print(f"this might be the password: {test}")
                            return True


if __name__ == "__main__":
    main()