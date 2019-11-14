class Rectangle:
    def __init__(self,l,r):
        self.l=l
        self.r=r
    def findArea(self):
        self.Area=self.l*self.r
    def showArea(self):
        print(self.Area)

C=Rectangle(10,20)
C.findArea()
C.showArea()
