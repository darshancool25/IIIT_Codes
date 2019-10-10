import time
t1 = time.time()
#print(list(filter(lambda x :True if sum(j if x%j==0 else 0 for j in range(1, x-1))==x else False, [x for x in range(2, 5000)])))
print([num for num in range(1,5001) if(sum((i for i in range(1,int(num/2)+1) if(num%i==0)))==num)])
t2 = time.time()
print(t2-t1)


