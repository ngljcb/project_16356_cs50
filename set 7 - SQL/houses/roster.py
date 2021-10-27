import cs50
import csv
import sys

# Open that file for SQLite
db = cs50.SQL("sqlite:///students.db")

# Prompt the database
house = db.execute("SELECT first, middle, last, birth FROM students WHERE house = ? ORDER BY last, first", sys.argv[1])

# Prints out the result of the query
for stud in house:
    if stud['middle']:
        print(f"{stud['first']} {stud['middle']} {stud['last']}, born {stud['birth']}")
    else:
        print(f"{stud['first']} {stud['last']}, born {stud['birth']}")

