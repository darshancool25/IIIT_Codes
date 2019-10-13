new,inplist = [],input("Enter list elements : ").split(" ")
for item in inplist:
    if(item not in new):
        new.append(item)
print(new)
