sum=0
while(True):
    a =input()
    if(a):
        new = a.split()
        if(new[0]=='D'):
            sum += int(new[1])
        else:
            sum -=int(new[1])
    else:
        break
print("Balance : ",sum)
