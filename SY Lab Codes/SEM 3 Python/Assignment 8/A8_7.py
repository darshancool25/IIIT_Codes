class Person:
    def __init__(self ,n,a):
        self.name=n
        self.age=a
    
class Address:
    def __init__(self,add,pin):
        self.add=add
        self.pin=pin

class Contact(Person,Address):
    def __init__(self,n,a,add,pin,m):
        Person.__init__(self,n,a)
        Address.__init__(self,add,pin)
        self.m=m

    def show(self):
        print(self.name,self.age,self.add,self.pin,self.m)


C=Contact("ABC",18,"XYZ",455455,9456564456)
C.show()
