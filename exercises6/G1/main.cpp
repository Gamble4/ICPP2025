#include "src/CompShape.hpp"
#include "src/shape.hpp"
#include <algorithm>
#include <vector>



int main()
{
    Rectangle r1{1, 281};    
    Rectangle r2{81, 232};    
    Rectangle r3{8, 1};    
    Triangle t1 (7, 12);
    Triangle t2 (3.1, 12);
    Triangle t3 (71, 92.1);
    Circle c1{5};
    Circle c2{6};
    Circle c3{3.8};
    

    std::cout << "unsorted: \n";
    std::vector<Shape*> v{&r1, &r2, &r3, &t1, &t2, &t3, &c1, &c2, &c3};
    for (Shape* sptr : v)
    {
        std::cout << sptr->getInfo() << "\n";
    }

    std::cout << "sorted: \n";
    std::sort(v.begin(), v.end(), compShape::compareAreas);
    for (Shape* sptr : v)
    {
        std::cout << sptr->getInfo() << "\n";
    }

    std::cout << "explicit: \n";
    Rectangle* rptr = new Rectangle(1, 2);
    Circle* cptr = new Circle(5.12);
    std::cout << rptr->getInfo() << "\n" << cptr->getInfo() << "\n";
    delete rptr;
    delete cptr;
}