// Area calcuation using templates
// read input (A.txt, B.txt) & write output (result.txt)
// 2023.02.21
// By: Ethan Baik

#include <iostream>
#include <string>
#include <fstream>

using namespace std;
// using std::cout;
// using std::endl;
// using std::string;

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

    // open input files
    ifstream file_A("A.txt");
    if (!file_A.is_open())
    {
        cerr << "File open error!" << endl;
        return -1;
    }

    ifstream file_B("B.txt");
    if (!file_B.is_open())
    {
        cerr << "File open error!" << endl;
        return -1;
    }

    // open output file
    ofstream file_out("result.txt");

    if (!file_out.is_open())
    {
        cerr << "File open error!" << endl;
        return -1;
    }

    cout << "Calculate Area of Rectangle." << endl;
    bool end_of_input = false;
    while (!end_of_input)
    {
        getline(file_A, strA);
        typeA = isNumber(strA);
        getline(file_B, strB);
        typeB = isNumber(strB);

        if (typeA == -1 || typeB == -1)
        {
            cout << "Non-valid input." << endl;
            file_out << "Non-valid input." << endl;
            continue;
        }

        cout << "A: " << strA << endl;
        cout << "B: " << strB << endl;

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

        end_of_input = file_A.eof() || file_B.eof();
    }

    file_A.close();
    file_B.close();
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
