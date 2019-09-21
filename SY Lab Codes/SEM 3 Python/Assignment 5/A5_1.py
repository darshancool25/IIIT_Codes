print("Enter numbers : ")
mylist = [int(i) for i in input().split(' ')]
factlist = []
for item in mylist:
    temp = 1
    for i in range(1,item+1):
        temp = temp*i
    factlist.append(temp)
print(factlist)
