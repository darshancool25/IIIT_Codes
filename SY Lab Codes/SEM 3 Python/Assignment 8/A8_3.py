class Circle:
    def __init__(self,r):
        self.r=r
    def findArea(self):
        self.Area=3.14*self.r*self.r
    def showArea(self):
        print(self.Area)

C=Circle(10)
C.findArea()
C.showArea()
