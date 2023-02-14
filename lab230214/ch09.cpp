#include <iostream>

using std::cout;
using std::endl;

class AAA
{
public:
    virtual void Func1()
    {
        cout << "Func1" << endl;
    }
    virtual void Func2()
    {
        cout << "Func2" << endl;
    }
private:
    int num1;
};

class BBB: public AAA
{
public:
    virtual void Func1()
    {
        cout << "BBB::Func1" << endl;
    }
    void Func3()
    {
        cout << "Func3" << endl;
    }
private:
    int num2;
};

int main(void)
{
    AAA *aptr = new AAA();
    aptr->Func1();

    BBB *bptr = new BBB();
    bptr->Func1();

    return 0;
}
