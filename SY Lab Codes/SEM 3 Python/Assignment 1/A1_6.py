str1,str2 = input().split(" ")
st1 = str1[0:2]
st2 = str2[0:2]
mystr = st2 + str1[2:] + st1 + str2[2:]
print(mystr)
