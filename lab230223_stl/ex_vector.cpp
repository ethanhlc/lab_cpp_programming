#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector<string> v_string;
    string in_str;
    cout << "Enter values:" << endl;

    while (true)
    {
        cin >> in_str;
        if (in_str == "end")
        {
            cout << endl;
            break;
        }

        v_string.push_back(in_str);
    }

    cout << "Output:" << endl;
    for (vector<string>::iterator it = v_string.begin(); it != v_string.end(); it++)
    {
        cout << *it << endl;
    }

    cout << "size(): " << v_string.size();
    cout << ", front(): " << v_string.front();
    cout << ", empty(): " << v_string.empty() << endl;

    cout << endl;
    cout << "Clear vector." << endl;
    cout << "empty(): " << v_string.empty() << endl;

    return 0;
}
