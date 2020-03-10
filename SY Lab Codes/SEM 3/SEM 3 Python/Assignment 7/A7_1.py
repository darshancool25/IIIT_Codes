def divBySeven(n):
    for i in range (0,n):
        if(i%7==0):
            yield i
for num in divBySeven(100):
    print(num)
