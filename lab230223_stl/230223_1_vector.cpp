#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main(void)
{
    vector<int> vecA;
    for (int i = 0; i < 10; i++)
    {
        vecA.push_back(i);
    }

    // access through 'index'
    for (int i = 0; i < vecA.size(); i++)
    {
        printf("%d", vecA[i]);
    }
    cout << endl;

    for (vector<int>::iterator it = vecA.begin(); it != vecA.end(); it++)
    {
        printf("%d", *it);
    }
    cout << endl;

    cout << "vecA.size(): " << vecA.size();
    cout << ", vecA.empty(): " << vecA.empty() << endl;
    cout << "vecA.front(): " << vecA.front();
    cout << ", vecA.back(): " << vecA.back() << endl;
    cout << "*vecA.begin(): " << *vecA.begin();
    cout << ", *vecA.end(): " << *vecA.end() << endl;

    return 0;
}
