# How you would normally sum integers in python
#x = [1, 2, 3]
#print("Normal python summation:")
#print(sum(x))


# Demonstrates python parameter packing
def add(*args):
    return sum(args)


print("Add result:")
print(add(1, 2, 3))

