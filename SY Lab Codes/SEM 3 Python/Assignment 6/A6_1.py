def calcletter(mystr) :
    lcnt,ucnt = 0,0
    for char in mystr:
        if(char.isupper()): ucnt +=1
        else : lcnt +=1
    print("The no. Of Upper Case letters are : ",ucnt)
    print("The no. Of Lower Case letters are : ",lcnt)

mystr = input("Enter a string : ")
calcletter(mystr)
