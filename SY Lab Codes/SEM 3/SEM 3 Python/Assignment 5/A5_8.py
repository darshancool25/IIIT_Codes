x,y = 0,0
while(True):
    a = input()
    if(a):
        new = a.split()
        if(new[0]=='UP'):
            y += int(new[1])
        if(new[0]=='DOWN'):
            y -= int(new[1])
        if(new[0]=='LEFT'):
            x -= int(new[1])
        if(new[0]=='RIGHT'):
            x += int(new[1])
    else:
        break
print(int((x**2 + y**2)**(1/2)))
    
