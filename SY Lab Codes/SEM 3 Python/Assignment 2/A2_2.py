temp = input("Enter temperature : ")
if(temp.endswith('F')):
    f = float(temp[:len(temp)-1])
    c = (5/9) * (f-32)
    print(c)
elif (temp.endswith('C')):
    c = float(temp[:len(temp)-1])
    f = ((9/5) * c) + 32
    print(f)
else:
    print("Invalid Input")
    
    
