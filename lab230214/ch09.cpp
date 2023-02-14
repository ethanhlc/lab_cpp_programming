#include <iostream>

using std::cout;
using std::endl;

class BaseOne
{
public:
    void SimpleFunc1()
    {
        cout << "BaseOne" << endl;
    }
};

class BaseTwo
{
public:
    void SimpleFunc2()
    {
        cout << "BaseTwo" << endl;
    }
};

class MultiDerived: public BaseOne, protected BaseTwo
{
public:
    void ComplexFunc()
    {
        SimpleFunc1();
        SimpleFunc2();
    }
};

int main(void)
{
    MultiDerived mdr;
    mdr.ComplexFunc();

    return 0;
}
