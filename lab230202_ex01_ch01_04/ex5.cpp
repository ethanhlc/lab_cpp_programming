// Area calculation using w & h
// class Rectangle (hide member vars)
// By: Ethan Baik

#include <iostream>
using namespace std;

class Rectangle
{
    int width;
    int height;

public:
    void SetWidth()
    {
        cout << "A: ";
        cin >> width;
    }

    void SetHeight()
    {
        cout << "B: ";
        cin >> height;
    }

    int GetArea()
    {
        return width * height;
    }
};

int main(void)
{
    Rectangle a;
    a.SetWidth();
    a.SetHeight();

    cout << "Area of Rectangle = " << a.GetArea() << endl;

    return 0;
}
