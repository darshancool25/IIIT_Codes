num = int(input("Enter a number : "))
mylist = [i for i in input().split(' ')]
print([i for i in mylist if (len(i)>num)])

