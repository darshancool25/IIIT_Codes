inp = [i for i in input().split(',')]
ans = []
for item in inp:
    if(int(item,2)%5==0):
        ans.append(int(item))
print(ans)

