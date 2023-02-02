// Area calculation using w & h
// function call-by-value
// By: Ethan Baik

#include <iostream>
using namespace std;

int GetArea(int x, int y)
{
    return x * y;
}

int main(void)
{
    int a, b;
    cout << "A: ";
    cin >> a;
    cout << "B: ";
    cin >> b;

    if (a < 0 || b < 0)
    {
        cout << "Error: Negative number was input." << endl;
        return -1;
    }

    int c = GetArea(a, b);
    cout << "Area of Rectangle = " << c << endl;

    return 0;
}
