// Area calcuation using templates
// 2023.02.21
// By: Ethan Baik

#include <iostream>
#include <string>

using namespace std;

template <typename T1, typename T2>
void GetArea()
{
    T1 w;
    T2 h;
    cout << "사각형의 넓이를 구하시오." << endl;
    cout << "A: ";
    cin >> w;
    cout << "B: ";
    cin >> h;
    cout << w * h;
}
// template<>
// char *GetArea(char *a, char *b)
// {
//     cout;
// }

/// Checks if input string is an integer, float, or char/string
/// @param str input string
/// @retval 0 if int
/// @retval 1 if float
/// @retval -1 if char/string
int isNumber(const string &str)
{
    if (str.find_first_not_of("0123456789") == string::npos)
    {
        // cout << "Input is int." << endl << endl;
        return 0;   // if int return 0
    }
    else if (str.find_first_not_of(".0123456789") == string::npos)
    {
        // cout << "Input is float." << endl << endl;
        return 1;   // if float return 1
    }
    else
    {
        // cout << "Input is not a number." << endl << endl;
        return -1;  // if char/string return -1
    }
}

int main(void)
{
    string strA, strB;
    int typeA, typeB;
    cout << "Calculate Area of Rectangle." << endl;
    bool isNum;
    do
    {
        isNum = true;
        cout << "A: ";
        cin >> strA;
        typeA = isNumber(strA);
        if (typeA == -1)
        {
            cout << "Please enter a number." << endl;
            isNum = false;
        }
    } while (isNum == false);
    do
    {
        isNum = true;
        cout << "B: ";
        cin >> strB;
        typeB = isNumber(strB);
        if (typeB == -1)
        {
            cout << "Please enter a number." << endl;
            isNum = false;
        }
    } while (isNum == false);

    // define variable A with correct type
    if (typeA == 0)
        int A = stoi(strA);
    else    // typeA == 1 (float)
        float A = stof(strA);

    // define variable B with correct type
    if (typeB == 0)
        int B = stoi(strB);
    else    // typeA == 1 (float)
        float B = stof(strB);

    return 0;
}
