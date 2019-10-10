inplist = input("Enter list elements : ").split(" ")
new = []
for item in inplist:
    if(item not in new):
        new.append(item)
print(new)
