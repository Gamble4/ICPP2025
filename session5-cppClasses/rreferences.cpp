#include <iostream>


typedef struct Point
{
    double x;
    double y;
} Point;

Point construcPoint(double x, double y)
{
    Point p{x, y};
    return p;
}

void printPoint(Point& Point)
{
    std::cout << "x: " << Point.x << " y: " << Point.y << "\n";
}

/*
  POint&& <-- referenz zu einem r-Value
  was besonders ist an r-references, ist dass die referenz des von der funktion 
  ausgegebenen objekts verwendet wird, und nicht der output kopiert wird
*/
void acceptRPoint(Point&& rvalue)
{
    std::cout << "found rvalue " << " \n";
    printPoint(rvalue);
}

int get_num()
{
    return 2;
}


int main()
{    
    acceptRPoint(construcPoint(1, 2));
    // rreferences erlauben es, Teferenzen zu einem temporary zu erzeugen, die mutable bleiben
    int&& a = get_num();
    a += 1;
    std::cout << a << "\n";
}
