n = int(input("Enter a number : "))
print("*"*n)
for i in range(2,n):
    print(" "*(n-i),"*",sep="")
print("*"*n)
