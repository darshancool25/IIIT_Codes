print("Enter elements of list : ")
mylist,count = [int(i) for i in input().split(' ')],0
l,r = input("Enter the bounds for range : ").split(' ')
for item in mylist:
    if (item<=int(r) and item>=int(l)):
        count = count+1
print("Number of elements in the given range : ",count)
