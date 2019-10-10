inp = input()
inplist = inp.split()
new = []
for item in inplist:
    if(item not in new):
        new.append(item)
new.sort()
for item in new:
    print(item,":",inplist.count(item))
