#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(void)
{
    int num1, num2;
    cout << "Enter 2 numbers: ";
    cin >> num1 >> num2;

    try
    {
        if (num2 == 0)
            throw num2;
        cout << "Quotient: " << num1 / num2 << endl;
        cout << "Remainder: " << num1 % num2 << endl;
    }
    catch (int expn)
    {
        cout << "Divisor cannot be " << expn << endl;
        cout << "Please re-run program." << endl;
    }

    cout << "end of main" << endl;
    return 0;
}
