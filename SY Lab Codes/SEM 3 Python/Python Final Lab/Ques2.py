def Reduce_Char(inplist):
    if(len(inplist)==1):
        return inplist[0]
    ans = ""
    if(inplist[len(inplist)-1]!= inplist[len(inplist)-2]):
        ans  = ans + inplist[len(inplist)-1]
    inplist.pop()
    ans  = Reduce_Char(inplist) + ans
    return ans

def Reduce_Num(inplist,num,pcnt,i):
    if(inplist[i] == inplist[i-1]):
        pcnt += 1
    else:
        num += str(pcnt)
        pcnt  = 1
    
    if(len(inplist)-1==i):
        num += str(pcnt)
        return num
    i +=1
    return Reduce_Num(inplist,num,pcnt,i)
    

inpstr = input()
num,ans = "",""
pcnt,i = 1,1
inplist = list(inpstr)
char = Reduce_Char(inplist)
inplist = list(inpstr)
num = Reduce_Num(inplist,num,pcnt,i)
for i in range(len(char)):
    ans += char[i]
    ans += num[i]
print(ans)
    
