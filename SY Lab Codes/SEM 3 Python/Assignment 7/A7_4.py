def unielem(mylist):
    return list(set(mylist))
mylist = input("Enter list elements : ").split(" ")
newlist = unielem(mylist)
print("Unique elements are : ",newlist)
    
