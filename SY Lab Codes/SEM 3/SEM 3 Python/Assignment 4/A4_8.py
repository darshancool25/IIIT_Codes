print("Enter elements of list : ")
mylist = [int(i) for i in input().split(' ')]
unique = list(set(mylist))
unique.sort()
print("Largest number in list is : ",unique[len(unique)-2])
