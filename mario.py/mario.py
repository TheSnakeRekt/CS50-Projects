from cs50 import get_int


def main(h):

    # Asks for input while h is smaller or equal to 0 or bigger then 8
    while h <= 0 or h > 8:
        h = get_int("Height: ")

    # determine width
    w = h

    # create piramid
    for i in range(1, h+1):
        space = w - i
        print(" " * space, end="")
        print("#" * i, end="")

        print("  ", end="")

        print("#" * i)


if __name__ == "__main__":
    main(0)