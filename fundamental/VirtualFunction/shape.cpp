#include <assert.h>
#include <cmath>

#define PI 3.1415926

class Shape {
public:
    // Append the declarations with = 0 to specify pure virtual functions
    virtual double Area() const = 0;
    virtual double Perimeter() const = 0;
};

class Rectangle : public Shape {
public:
    Rectangle(double width, double height) 
        : width(width), height(height) {}
    double Area() const {
        return width * height;
    }
    double Perimeter() const {
        return 2 * (width + height);
    }

private:
    double width;
    double height;
};


// TODO: Define Circle to inherit from Shape
class Circle : public Shape {
public:
    Circle(double radius) : radius(radius) {};
    double Area() const {
        return PI * pow(radius, 2);
    }
    double Perimeter() const {
        return 2 * PI * radius;
    }
private:
    double radius;
};


// Test in main()
int main() {
  double epsilon = 0.1; // useful for floating point equality

  // Test circle
  Circle circle(12.31);
  assert(abs(circle.Perimeter() - 77.35) < epsilon);
  assert(abs(circle.Area() - 476.06) < epsilon);

  // Test rectangle
  Rectangle rectangle(10, 6);
  assert(rectangle.Perimeter() == 32);
  assert(rectangle.Area() == 60);
}