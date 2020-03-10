print("Enter elements of the list : ")
mylist = [int(i) for i in input().split(' ')]
print([i for i in mylist if i%2==1])
