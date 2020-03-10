mylist = [2,3,3,4,6,7,8,8,5,5]
newlist = []
for item in mylist:
    if(item not in newlist):
        newlist.append(item)
for item in newlist:
    print("Frequency of ",item," : ",mylist.count(item))
