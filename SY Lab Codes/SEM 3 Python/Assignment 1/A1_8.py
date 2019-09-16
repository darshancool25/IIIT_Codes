mystr = input("Enter a string : ")
strlen = len(mystr)
newstr = mystr[strlen-1] + mystr[1:strlen-1] + mystr[0]
print(newstr)
