def Check(s):
    low = upp = num = spec = False
    strlen = len(s)
    if(strlen<=12 and strlen >=6):
        for i in range(strlen):
            if(set(s[i]).intersection({'$','#','@'})): spec = True
            elif(s[i].isnumeric()): num = True
            elif(s[i].isupper()): upp = True
            elif(s[i].islower()): low = True
    else:
        return False
    if(low and upp and num and spec): return True
mylist = input("Enter the passwords you wish to check : ").split()
printf("Valid Passwords are : ")
for item in mylist:
    if(Check(item)): print(item)
