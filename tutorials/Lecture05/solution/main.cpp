#define SOLUTION
#include <memory>
#include <iostream>
#include <vector>
#ifdef SOLUTION 
#include <cmath>
#endif

#ifdef SOLUTION 
#define A1
#define A2
#define A3
#else
//#define A1
//#define A2
//#define A3
#endif

#ifdef SOLUTION
class Shape
{
public:
    virtual double getArea() const = 0;
    virtual ~Shape() = default;
};

class Rectangle: public Shape
{
private:
    double dX;
    double dY;
public:
    Rectangle(double dimX, double dimY): Shape(), dX(dimX), dY(dimY) {}
    double getArea() const override { return this->dX * this->dY; }
};

class Circle: public Shape
{
private:
    double r;
public:
    Circle(double radius): Shape(), r(radius) {}
    double getArea() const override { return M_PI * this->r * this->r; }
};
#endif

#ifdef SOLUTION
void printShape(std::ostream& os, const Shape& s)
{
    if(dynamic_cast<const Circle*>(&s))
        os<<"Circle";
    else if(dynamic_cast<const Rectangle*>(&s))
        os<<"Rectangle";
}
#endif

#ifdef A2
std::ostream& operator<<(std::ostream& os, const Shape& shape)
{
    printShape(os, shape);
    return os;
}
#endif

enum class ShapeType
{
    Circle,
    Rectangle
};

#ifdef SOLUTION
std::vector<std::unique_ptr<Shape>> createShapes(const std::vector<std::tuple<ShapeType, double, double>>& config)
{
    std::vector<std::unique_ptr<Shape>> result;
    for(const auto& t: config)
        if(std::get<0>(t) == ShapeType::Circle)
            result.push_back(std::make_unique<Circle>(std::get<1>(t)));
        else if(std::get<0>(t) == ShapeType::Rectangle)
            result.push_back(std::make_unique<Rectangle>(std::get<1>(t), std::get<2>(t)));
        else
            throw std::runtime_error("Unknown ShapeType detected");
    return result;
}
#endif

int main()
{
#ifdef A1
    Rectangle r{4.0, 5.0};
    Circle    c{3.0};
    std::cout << "Rectangle Area:            " << r.getArea()                      << ", expected: " << 20 << "\n";
    std::cout << "Rectangle Area (as Shape): " << static_cast<Shape&>(r).getArea() << ", expected: " << 20 << "\n";
    std::cout << "Circle Area:               " << c.getArea()                      << ", expected: " << (9 * M_PI) << "\n";
    std::cout << "Circle Area (as Shape):    " << static_cast<Shape&>(c).getArea() << ", expected: " << (9 * M_PI) << "\n\n";
#endif

#ifdef A2
    std::cout << "r: " << r << ", expected: Rectangle\n";
    std::cout << "c: " << c << ",    expected: Circle\n\n";
#endif

#ifdef A3
    auto vec = createShapes({std::make_tuple(ShapeType::Circle, 1.0, 0.0), 
                             std::make_tuple(ShapeType::Rectangle, 1.0, 1.0), 
                             std::make_tuple(ShapeType::Circle, 3.0, 0.0), 
                             std::make_tuple(ShapeType::Rectangle, 2.0, 4.0),
                             std::make_tuple(ShapeType::Rectangle, 0.5, 0.5), 
                             std::make_tuple(ShapeType::Circle, 5.0, 0.0)});
                             
    for(const auto& elem: vec)
        std::cout << *elem << ": " << elem->getArea() << "\n";
        
    std::cout << "\nExpected:\n";
    std::cout << "Circle: "    << (1.0*M_PI) << "\n";
    std::cout << "Rectangle: " << (1.0)  << "\n";
    std::cout << "Circle: "    << (9.0*M_PI) << "\n";
    std::cout << "Rectangle: " << (8.0)  << "\n";
    std::cout << "Rectangle: " << (0.25)  << "\n";
    std::cout << "Circle: "    << (25.0*M_PI) << "\n";
#endif
}
