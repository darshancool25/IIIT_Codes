list1 = [1,2,3,4,5]
list2 = [7,8,9,10]
list1.pop()
list1[len(list1):] = list2
print(list1)
