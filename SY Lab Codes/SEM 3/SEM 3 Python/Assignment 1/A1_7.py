mystr = input("Enter a string : ")
strlen = len(mystr)
if(strlen < 3):
    print(mystr)
else:
    if(mystr.endswith("ing")):
        mystr = mystr + "ly"
        print(mystr)
    else:
        mystr = mystr + "ing"
        print(mystr)
