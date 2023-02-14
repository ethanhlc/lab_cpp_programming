// Operator overloading

#include <iostream>

using std::cout;
using std::endl;

class Point
{
public:
    Point(int x = 0, int y = 0): xpos(x), ypos(y)
    { }

    void ShowPosition() const
    {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }
    Point &operator++()
    {
        xpos += 1;
        ypos += 1;
        return *this;
    }
    friend Point &operator--(Point &ref);
private:
    int xpos, ypos;
};

Point &operator--(Point &ref)
{
    ref.xpos -= 1;
    ref.ypos -= 1;
    return ref;
}

int main(void)
{
    Point pos1(3, 4);
    ++pos1;
    pos1.ShowPosition();
    --pos1;
    pos1.ShowPosition();
    ++(++pos1);
    pos1.ShowPosition();
    --(--pos1);
    pos1.ShowPosition();

    return 0;
}
