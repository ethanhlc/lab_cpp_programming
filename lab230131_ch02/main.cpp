#include <iostream>

using namespace std;

int& RefRetFuncOne(int& ref)
{
    ref++;
    return ref;
}

int main(void)
{
    int num1 = 10;
    int num2 = RefRetFuncOne(num1);
    cout << "RefRetFunc(num1)" << endl;
    cout << endl;

    num1++;
    cout << "num1++" << endl;
    cout << "num1: " << num1 << endl;
    cout << "num2: " << num2 << endl;
    cout << endl;

    num2 += 10;
    cout << "num2 += 10" << endl;
    cout << "num1: " << num1 << endl;
    cout << "num2: " << num2 << endl;

    return 0;
}
