#include <iostream>
using namespace std;

class SoBase
{
public:
    SoBase()
    {
        cout << "SoBase()" << endl;
    }
    SoBase(int n): baseNum(n)
    {
        cout << "SoBase(int n)" << endl;
    }

    void ShowBaseData()
    {
        cout << baseNum << endl;
    }

private:
    int baseNum = 20;
};

class SoDerived: public SoBase
{
public:
    SoDerived()
    {
        cout << "SoDerived()" << endl;
    }
    SoDerived(int n): derivNum(n)
    {
        cout << "SoDerived(int n)" << endl;
    }
    SoDerived(int n1, int n2): SoBase(n1), derivNum(n2)
    {
        cout << "SoDerived(int n1, int n2)" << endl;
    }

    void ShowDerivData()
    {
        ShowBaseData();
        cout << derivNum << endl;
    }

private:
    int derivNum = 30;
};

int main(void)
{
    cout << "case1..." << endl;
    SoDerived dr1;
    dr1.ShowDerivData();
    cout << "----------" << endl;

    cout << "case2..." << endl;
    SoDerived dr2(12);
    dr2.ShowDerivData();
    cout << "----------" << endl;

    cout << "case3..." << endl;
    SoDerived dr3(23, 24);
    dr3.ShowDerivData();

    return 0;
}
