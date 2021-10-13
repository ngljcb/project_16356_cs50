# calls the get_int funcntion from cs50 library
from cs50 import get_int

# main method of the program


def main():
    height = get_int_onRange(1, 8)
    build_pyramid(height)

# deals with prompting int, range min-max inclusive


def get_int_onRange(min, max):
    while True:
        n = get_int("Height: ")
        if n >= min and n <= max:
            break
    return n

# contruct the pyramid of the given height


def build_pyramid(height):
    for i in range(height):
        for j in range(height - i - 1):
            print(" ", end="")
        put_block(i)
        print("  ", end="")
        put_block(i)
        print()

# provides n blocks to put in the line


def put_block(n):
    for i in range(n + 1):
        print("#", end="")


# calls the main function
main()