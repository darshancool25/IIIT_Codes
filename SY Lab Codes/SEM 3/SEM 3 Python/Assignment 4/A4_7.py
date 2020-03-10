print("Enter elements of list")
mylist,newlist = [int(i) for i in input().split(' ')],0
for item in mylist:
    if (item not in newlist):
        newlist.append(item)
print(newlist)
