def func(*args):
    sum = 0
    for item in args:
        sum +=item
    return sum
print(func(10,20,30))
