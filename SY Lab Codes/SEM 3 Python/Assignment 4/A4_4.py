import itertools
print("Enter elements of list : ")
print(list(itertools.permutations([int(i) for i in input().split(' ')])))
