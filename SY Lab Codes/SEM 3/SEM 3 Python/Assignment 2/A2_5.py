mystr = input("Input a string : ")
acount,dcount = 0,0
for i in mystr:
    if(i.isdigit()):
        dcount = dcount + 1
    elif(i.isalpha()):
        acount = acount + 1
print("Digits = ",dcount , "Alphabets : ",acount)
