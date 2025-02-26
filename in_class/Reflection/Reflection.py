class Fraction:
    def __init__(self,x,y):
        self.num = x
        self.den = y
    def sum(self):
        return self.x+self.y

type(Fraction(2,4)) == Fraction

obj = Fraction(3,4)
print(vars(obj)) #{'num': 3, 'den': 4}
print(vars(obj)['num']) #3

for a in vars(obj):
    print('Attribute: ',a, ' -> ',getattr(obj,a))
# Attribute:  num  ->  3
# Attribute:  den  ->  4

print("\n", "---Fraction---","\n",dir(Fraction),"\n") # List attributes of the class
print("\n", "---obj 3, 4---","\n",dir(obj),"\n")  # List attributes of the objec
print("\n", vars(obj))
print( "\n----Globals----\n",dir(globals()))
print( "\n----Globals----\n",globals())

x = Fraction(4,5)
y = Fraction(1,1)
f = getattr(x, 'sum')
print(f)
# f(y).show() #calls sum for the obj fraction
# g = getattr(Fraction, 'sum') #sum(self,x)
# g(x,y) 
class_name = "Fraction" 
# Dynamically get the class reference (constructor)
# from the module and instantiate it 
for a in dir(Fraction):
    if a=="Fraction":
        print("\n",a)
# ClassRef = getattr(Fraction, class_name) 
# obj = ClassRef(1, 2)
# print(obj.show()) # Output "1/2"  
