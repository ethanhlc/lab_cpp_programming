#include <iostream>

using std::cout;
using std::endl;

class First
{
public:
    virtual void myFunc()
    {
        cout << "FirstFunc" << endl;
    }
};

class Second: public First
{
public:
    virtual void myFunc()
    {
        cout << "SecondFunc" << endl;
    }
};

class Third: public Second
{
public:
    virtual void myFunc()
    {
        cout << "ThirdFunc" << endl;
    }
};

int main(void)
{
    Third *tptr = new Third();
    Second *sptr = tptr;
    First *fptr = sptr;

    tptr->myFunc();
    sptr->myFunc();
    fptr->myFunc();

    return 0;
}
