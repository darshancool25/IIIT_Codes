class String:
    def __init__(self):
        self.strval=""

    def getString(self,s):
        self.strval=s

    def printString(self):
        print(self.strval)

str1= String()
s=input("Enter String:")
str1.getString(s)
str1.printString()
