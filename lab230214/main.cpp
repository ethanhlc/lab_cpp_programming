#include <iostream>

using std::cout;
using std::endl;

class First
{
public:
    void FirstFunc()
    {
        cout << "FirstFunc" << endl;
    }
    virtual void SimpleFunc()
    {
        cout << "First's SimpleFunc" << endl;
    }
};

class Second: public First
{
public:
    void SecondFunc()
    {
        cout << "SecondFunc" << endl;
    }
    virtual void SimpleFunc()
    {
        cout << "Second's SimpleFunc" << endl;
    }
};

class Third: public Second
{
public:
    void ThirdFunc()
    {
        cout << "ThirdFunc" << endl;
    }
    virtual void SimpleFunc()
    {
        cout << "Third's SimpleFunc" << endl;
    }
};

int main(void)
{
    Third tobj;
    tobj.FirstFunc();
    tobj.SecondFunc();
    tobj.ThirdFunc();
    tobj.SimpleFunc();

    Second &sref = tobj;
    sref.FirstFunc();
    sref.SecondFunc();
    sref.SimpleFunc();

    First &fref = tobj;
    fref.FirstFunc();
    fref.SimpleFunc();

    return 0;
}
