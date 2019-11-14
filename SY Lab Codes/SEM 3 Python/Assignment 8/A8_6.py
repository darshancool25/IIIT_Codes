class Shape():
    def __init__(self):
        self.Area=0
        self.r=0
    def area(self):
        print(self.Area)

class Square(Shape):
    def __init__(self,l):
        Shape.__init__(self)
        self.l=l

    def area(self):
        self.Area=self.l**2
        print(self.Area)


S=Square(5)
S.area()
