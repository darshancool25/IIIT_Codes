n = int(input("Enter a number : "))
print(" ","*"*n,sep="")
for i in range(1,n-1):
    print("*")
print(" ","*"*(n-1),sep="")
for i in range(1,n-1):
    print(" "*(n),"*",sep="")
print("*"*n)
