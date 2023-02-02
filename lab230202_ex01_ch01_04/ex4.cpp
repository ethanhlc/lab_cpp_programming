// Area calculation using w & h
// function call-by-reference
// By: Ethan Baik

#include <iostream>
using namespace std;

int &GetArea(int &x, int &y, int &area)
{
    area = x * y;
    return area;
}

int main(void)
{
    int a, b;
    int area;
    cout << "A: ";
    cin >> a;
    cout << "B: ";
    cin >> b;

    if (a < 0 || b < 0)
    {
        cout << "Error: Negative number was input." << endl;
        return -1;
    }

    int &c = GetArea(a, b, area);
    cout << "Area of Rectangle (c) = " << c << endl;
    cout << "Area of Rectangle (area) = " << area << endl;

    return 0;
}
