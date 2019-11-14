class Subsets:
    def __init__(self,A):
        self.A=A
        self.B=[]
    def getSubset(self):
        for i in range(len(self.A)):
            for j in range(i,len(self.A)):
                self.B.append(self.A[i:j+1])
    def showSubset(self):
        print(self.B)


ss1=Subsets([4,5,6])
ss1.getSubset()
ss1.showSubset()
        
