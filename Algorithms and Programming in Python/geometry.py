from abc import ABC, abstractmethod
import math

class Figure(ABC):
    @abstractmethod
    def area(self):
        pass
    @abstractmethod
    def perimeter(self):
        pass

class Rectangle(Figure):
    def __init__(self, width, height):
        self.width = width
        self.height = height
    def area(self):
        return self.width * self.height
    def perimeter(self):
        return 2 * (self.width + self.height)

class Square(Rectangle):
    def __init__(self, side):
        super().__init__(side, side)

class Circle(Figure):
    def __init__(self, radius):
        self.radius = radius
    def area(self):
        return math.pi * self.radius ** 2
    def perimeter(self):
        return 2 * math.pi * self.radius

class Triangle(Figure):
    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c
    def area(self):
        s = self.perimeter() / 2
        return math.sqrt(s * (s - self.a) * (s - self.b) * (s - self.c))
    def perimeter(self):
        return self.a + self.b + self.c
        
def main():
    figures = []
    num_figures = int(input("Podaj liczbę figur do wczytania: "))

    for _ in range(num_figures):
        figure_type = input("Podaj typ figury (R - prostokąt, S - kwadrat, C - koło, T - trójkąt): ").strip().upper()
        if figure_type == "R":
            width = float(input("Podaj szerokość prostokąta: "))
            height = float(input("Podaj wysokość prostokąta: "))
            figures.append(Rectangle(width, height))
        elif figure_type == "S":
            side = float(input("Podaj długość boku kwadratu: "))
            figures.append(Square(side))
        elif figure_type == "C":
            radius = float(input("Podaj promień koła: "))
            figures.append(Circle(radius))
        elif figure_type == "T":
            a = float(input("Podaj długość pierwszego boku trójkąta: "))
            b = float(input("Podaj długość drugiego boku trójkąta: "))
            c = float(input("Podaj długość trzeciego boku trójkąta: "))
            figures.append(Triangle(a, b, c))
        else:
            print("Nieznany typ figury. Spróbuj ponownie.")
    for i, figure in enumerate(figures, start=1):
        print(f"Figura {i}:")
        print(f"  Pole: {figure.area():.2f}")
        print(f"  Obwód: {figure.perimeter():.2f}")

if __name__ == "__main__":
    main()