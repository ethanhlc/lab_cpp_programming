// Area calculation using w & h
// input output using functions & global vars
// By: Ethan Baik

#include <iostream>
using namespace std;

void GetInput();
void PrintOutput();

int a, b;

int main(void)
{
    GetInput();
    if (a < 0 || b < 0)
    {
        cout << "Error: Negative number was input." << endl;
        return -1;
    }

    PrintOutput();

    return 0;
}

void GetInput()
{
    cout << "A: ";
    cin >> a;
    cout << "B: ";
    cin >> b;
}

void PrintOutput()
{
    cout << "Area of Rectangle = " << a * b << endl;
}
