import cs50
import csv
import sys

# Open that file for SQLite
db = cs50.SQL("sqlite:///students.db")

# Read file prompted through command-line argument
with open(sys.argv[1], "r") as studs:

    # Read each line in the file
    reader = csv.DictReader(studs)

    # For every line, save informations to the database
    for row in reader:
        name = row["name"].split()
        if len(name) == 3:
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)",
                       name[0], name[1], name[2], row["house"], row["birth"])
        else:
            db.execute("INSERT INTO students (first, last, house, birth) VALUES (?, ?, ?, ?)",
                       name[0], name[1], row["house"], row["birth"])