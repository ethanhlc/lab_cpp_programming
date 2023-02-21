// Area calcuation using templates
// write result into result.txt
// 2023.02.21
// By: Ethan Baik

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Function Declarations
int isNumber(const string &str);

template <typename T>
class Rect
{
public:
    Rect(T x = 0, T y = 0): width(x), height(y)
    { }

    void SetWidth(T x)
    {
        width = x;
    }
    void SetHeight(T y)
    {
        height = y;
    }
    T GetArea()
    {
        return height * width;
    }

private:
    T width;
    T height;
};

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
            cout << "Please enter a valid number." << endl;
            isNum = false;
        }
    } while (isNum == false);

    // open file
    ofstream file_out("result.txt");

    if (!file_out.is_open())
    {
        cerr << "File open error!" << endl;
        return -1;
    }

    // define Rect r1 with correct type
    if (typeA == 0 && typeB == 0)
    {
        Rect <int>r1(stoi(strA), stoi(strB));
        file_out << "A: " << stoi(strA) << "\tB: " << stoi(strB);
        cout << "Area of Rectangle: " << r1.GetArea() << endl;
        file_out << "\tArea: " << r1.GetArea() << endl;
    }
    else    // type == 1 (float)
    {
        Rect <float>r1(stof(strA), stof(strB));
        file_out << "A: " << stof(strA) << "\tB: " << stof(strB);
        cout << "Area of Rectangle: " << r1.GetArea() << endl;
        file_out << "\tArea: " << r1.GetArea() << endl;
    }

    file_out.close();
    return 0;
}

/// Checks if input string is an integer, float, or char/string
/// @param str input string
/// @returns 0 if int, 1 if float, -1 if char/string
int isNumber(const string &str)
{
    // if no non-number found
    if (str.find_first_not_of("0123456789") == string::npos)
    {
        // cout << "Input is int." << endl << endl;
        return 0;   // if int return 0
    }
    // if no non-number & '.' found
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
