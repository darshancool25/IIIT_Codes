def my_map(func, cont):
    new_list = []
    for item in cont:
        new_list.append(func(item))
    return new_list
s = [1, 3, 5, 7, 9]
def sqr(x): return x ** 2
print (my_map(sqr,s))
