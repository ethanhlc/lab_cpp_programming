// C++ style initialization
// By: Ethan Baik

#include <iostream>
using namespace std;

class SoSimple
{
public:
    SoSimple(int n1, int n2): num1(n1), num2(n2)
    {}
    void ShowSimpleData()
    {
        cout << "num1: " << num1 << endl;
        cout << "num2: " << num2 << endl;
    }
private:
    int num1;
    int num2;
};

int main()
{
    SoSimple sim1(15, 20);
    SoSimple sim2 = sim1;
    sim2.ShowSimpleData();

    return 0;
}
