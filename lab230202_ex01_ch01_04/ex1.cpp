// Area calculation using w & h
// minimal code using cin, cout
// By: Ethan Baik

#include <iostream>
using namespace std;

int main(void)
{
    int a, b;
    cout << "A: ";
    cin >> a;
    cout << "B: ";
    cin >> b;

    // Negative number
    if (a < 0 || b < 0)
    {
        cout << "Error: Negative number was input." << endl;
        return -1;
    }

    cout << "Area of Rectangle = " << a * b << endl;

    return 0;
}
