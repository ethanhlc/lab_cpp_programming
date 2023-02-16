#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string str1 = "I like ";
    string str2 = "string class";
    string str3 = str1 + str2;

    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl;

    str1 += str2;
    if (str1 == str3)
        cout << "Equivalent string!" << endl;
    else
        cout << "Not Equivalent string!" << endl;

    string str4;
    cout << "String input: ";
    cin >> str4;
    cout << "Input string: " << str4 << endl;

    return 0;
}