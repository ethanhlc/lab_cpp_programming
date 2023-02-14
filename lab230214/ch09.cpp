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
    void SimpleFunc1()
    {
        cout << "BaseTwo" << endl;
    }
};

class MultiDerived: public BaseOne, protected BaseTwo
{
public:
    void ComplexFunc()
    {
        BaseOne::SimpleFunc1();
        BaseTwo::SimpleFunc1();
    }
};

int main(void)
{
    MultiDerived mdr;
    mdr.ComplexFunc();

    return 0;
}
