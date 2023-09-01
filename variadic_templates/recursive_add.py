# Demonstrates python parameter unpacking using recursion
def add(a, *args):
    if len(args) == 0:
        return a
    return a + add(*args)


print("Add result:")
print(add(1, 4, 9))
