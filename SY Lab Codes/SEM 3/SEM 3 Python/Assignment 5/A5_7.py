import operator
inp = []
while(True):
    a = input()
    if(a):
        new = tuple(a.split(','))
        inp.append(new)
    else:
        break
inp.sort()
print(inp)
