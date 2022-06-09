#include <memory>
#include <iostream>
#include <vector>

//#define A1
//#define A2
//#define A3

/* Teilaufgabe 1 */
// TODO: Write classes Shape, Rectangle and Circle!

/* Teilaufgabe 2 */
// TODO: Write function printShape

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

/* Teilaufgabe 3 */
// TODO: createShapes!

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
