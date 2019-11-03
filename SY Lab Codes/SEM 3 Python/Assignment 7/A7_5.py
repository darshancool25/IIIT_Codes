def palincheck(mystr):
    if(mystr == mystr[::-1]):
        return True
    else:
        return False
mystr = input("Enter a string : ")
if(palincheck(mystr)):
    print("Entered string is a palindrome")
else:
    print("Entered string is not a palindrome")
