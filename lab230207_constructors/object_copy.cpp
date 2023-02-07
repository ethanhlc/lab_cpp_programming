// Copy constructor call timing
// By: Ethan Baik

#include <iostream>
using namespace std;

class SoSimple
{
public:
    SoSimple(int n): num(n) {}
    SoSimple(const SoSimple &copy): num(copy.num)
    {
        cout << "Called SoSimple(copy)" << endl;
    }

    SoSimple &AddNum(int n)
    {
        num += n;
        return *this;
    }
    void ShowData()
    {
        cout << "num: " << num << endl;
    }
private:
    int num;
};

// calls copy constructor on return (returns class)
SoSimple SimpleFuncObj(SoSimple ob)
{
    cout << "before return" << endl;
    return ob;
}

int main()
{
    SoSimple obj(7);
    SimpleFuncObj(obj).AddNum(30).ShowData();
    obj.ShowData();

    return 0;
}
