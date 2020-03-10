a,c = [],[]
a = input().split(" ")
for x in a:
    c.append(tuple(x.split(",")))
print(sorted(c,key = lambda element : (element[0],element[1], element[2])))
