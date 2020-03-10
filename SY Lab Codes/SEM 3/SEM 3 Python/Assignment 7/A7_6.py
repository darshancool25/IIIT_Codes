def func1(x):
    def func2(y):
        return x*y
    return func2
num1 = func1(5)
print(num1(3))
