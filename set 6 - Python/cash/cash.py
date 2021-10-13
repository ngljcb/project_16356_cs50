# calls the get_int funcntion from cs50 library
from cs50 import get_float

# main method of the program


def main():
    change = get_change()
    coins = count_coins(round_to_cents(change))
    print(coins)

# prompt for change, which is a non-negative float number


def get_change():
    while True:
        n = get_float("Change owed: ")
        if n >= 0:
            break
    return n

# converts the float value to int


def round_to_cents(dollar):
    return round(dollar * 100)

# count the number of coins to be used as change


def count_coins(change):
    coins = 0
    cents = [25, 10, 5, 1]
    i = 0
    while change > 0:
        coins += int(change / cents[i])
        change %= cents[i]
        i += 1
    return coins


# calls the main function
main()