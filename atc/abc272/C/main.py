import random

len = 10

filename = "in"

with open(filename, "w+") as f:
    f.write(f"{len}\n")
    for i in range(len):
        f.write(str(random.randint(0, 10000)) + " ")
