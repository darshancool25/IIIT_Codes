class Gen:
    def __init__(self,n):
        self.n=n
    def genclass(self):
        for i in range(self.n):
            if(i%7==0):
                yield (i)

G= Gen(18)
for i in G.genclass():
    print(i)
    
        
