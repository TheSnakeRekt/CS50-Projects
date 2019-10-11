from nltk.tokenize import sent_tokenize


def lines(a, b):
    """Return lines in both a and b"""
    wordsA = a.split("\n")
    wordsB = b.split("\n")

    tmp = []

    for x in wordsA:
        for y in wordsB:
            if x == y:
                tmp.append(x)

    # creating a set to eliminate duplicate
    words = set(tmp)

    # TODO
    return words


def sentences(a, b):
    """Return sentences in both a and b"""

    wordsA = sent_tokenize(a)
    wordsB = sent_tokenize(b)
    tmp = []

    # iterating through the list to check for equal tokens
    for x in wordsA:
        for y in wordsB:
            if x == y:
                tmp.append(x)

    # creating a set to eliminate duplicate
    words = set(tmp)

    # TODO
    return words


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""

    subsA = toSub(a, n)
    subsB = toSub(b, n)
    tmp = []

    # iterating through the list to check for equal substrings
    for x in subsA:
        for y in subsB:
            if x.strip() == y.strip():
                tmp.append(x)

    # creating a set to eliminate duplicate
    words = set(tmp)

    return words


def toSub(str, n):
    sub = []

    for i in range(len(str) - n + 1):
        sub.append(str[i:i + n])

    return sub