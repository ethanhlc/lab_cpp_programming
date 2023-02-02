#include <iostream>

using namespace std;

class Point
{
public:
    int x;  // 0~100
    int y;  // 0~100
};

class Rectangle
{
public:
    Point upLeft;
    Point lowRight;

public:
    void ShowRectInfo()
    {
        cout << "UpLeft: " << '[' << upLeft.x << ", ";
        cout << upLeft.y << ']' << endl;
        cout << "LowRight: " << '[' << lowRight.x << ", ";
        cout << lowRight.y << ']' << endl;
    }
};

int main(void)
{
    Point pos1 = {-2, 4};
    Point pos2 = {5, 9};
    Rectangle rec = {pos2, pos1};

    rec.ShowRectInfo();

    return 0;
}
