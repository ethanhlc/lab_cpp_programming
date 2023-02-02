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
    bool SetWidth()
    {
        cout << "A: ";
        cin >> width;
        if (width < 0)
        {
            cout << "Error: Negative number was input." << endl;
            return false;
        }
        return true;
    }

    bool SetHeight()
    {
        cout << "B: ";
        cin >> height;
        if (height < 0)
        {
            cout << "Error: Negative number was input." << endl;
            return false;
        }
        return true;
    }

    int GetArea()
    {
        return width * height;
    }
};

int main(void)
{
    Rectangle a;
    if (a.SetWidth() == false)
        return -1;
    if (a.SetHeight() == false)
        return -1;

    cout << "Area of Rectangle = " << a.GetArea() << endl;

    return 0;
}
