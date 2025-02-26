class Shape:
    def draw(self):
        print("Drawing a generic shape.")

class Circle(Shape):
    def draw(self):
        print("Drawing a circle.")

class Rectangle(Shape):
    def draw(self):
        print("Drawing a rectangle.")

class Triangle(Shape):
    def draw(self):
        print("Drawing a triangle.")

# Demonstrate polymorphism
shapes = [Circle(), Rectangle(), Triangle()]

for shape in shapes:
                print(type(shape))
