# calls the get_int funcntion from cs50 library
from cs50 import get_string

# main method of the program


def main():
    text = get_string("Text: ")
    print_result(calculate_readability(text))


# calculates the readability of the given text according to Coleman-Liau index, returns an int


def calculate_readability(text):
    counter = [0, 1, 0]  # letters, words, sentences
    check_text(counter, text)
    return coleman_liau_index(counter)

# iterates though the text & count the letters, words, & sentences


def check_text(counter, text):
    for x in text:
        if x.isalpha():
            counter[0] += 1
        elif x.isspace():
            counter[1] += 1
        elif ord(x) == 33 or ord(x) == 46 or ord(x) == 63:
            counter[2] += 1

# calculate the index grade


def coleman_liau_index(counter):
    l = float(counter[0] / counter[1] * 100)
    s = float(counter[2] / counter[1] * 100)
    index = 0.0588 * l - 0.296 * s - 15.8
    return round(index * 1)

# prints the result accordingly


def print_result(index):
    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print("Grade {}".format(index))


# calls the main function
main()