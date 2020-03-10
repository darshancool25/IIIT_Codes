def myfun(d):
    return int(((2*50*d)/30)**(1/2))
inp = input().split(',')
anslist = []
for item in inp:
    anslist.append(myfun(int(item)))
print(anslist)
    
