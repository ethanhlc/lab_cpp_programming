#include <iostream>
#include <cstring>

using namespace std;

template <typename T>
T Add(T num1, T num2)
{
    return num1 + num2;
}

template <class T1, class T2>
void ShowData(double num)
{
    cout << (T1)num << ", " << (T2)num << endl;
}

template <typename T>
T Max(T a, T b)
{
    return a > b ? a : b;
}
template <>
// char *Max<char*>(char *a, char *b)
char *Max(char *a, char *b)
{
    cout << "char *Max<char*>(char *a, char *b)" << endl;
    return strlen(a) > strlen(b) ? a : b;
}
template <>
// const char *Max<const char*>(const char *a, const char *b)
const char *Max(const char *a, const char *b)
{
    cout << "const char *Max<char*>(const char *a, const char *b)" << endl;
    return strcmp(a, b) > 0 ? a : b;    // if a after b: a, else: b
}

template <typename T>
class Point
{
public:
    Point(T x = 0, T y = 0): xpos(x), ypos(y)
    { }
    void ShowPosition() const
    {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }
private:
    T xpos, ypos;
};

int main(void)
{
    // cout << Max(11, 15) << endl;
    // cout << Max('T', 'Q') << endl;
    // cout << Max(3.5, 7.5) << endl;
    // cout << Max("Simple", "Best") << endl;

    // char str1[] = "Simple";
    // char str2[] = "Best";
    // cout << Max(str1, str2) << endl;

    Point<int> pos1(3, 4);
    pos1.ShowPosition();

    Point<double> pos2(2.4, 3.6);
    pos2.ShowPosition();

    Point<char> pos3('P', 'F');
    pos3.ShowPosition();

    return 0;
}
