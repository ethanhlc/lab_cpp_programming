// Ex02 Using classes & inheritance
// for lecture & student management
// By: Ethan Baik

#include <iostream>
using namespace std;

class CLecture
{
public:
    CLecture(char *lect, int grd): grade(grd)
    {
        int len = strlen(lect) + 1;
        lecture_name = new char[len];
        strcpy(lecture_name, lect);
    }
    CLecture() = default;
    ~CLecture()     // destructor to release allocated memory
    {
        delete lecture_name;
    }

protected:
    char *lecture_name;
    int grade;
};

class CStudent: public CLecture
{
public:

    ~CStudent()     // destructor to release allocated memory
    {
        delete name;
        delete major;
    }

    void SetStudent(int id_in, const char *name_in, const char *major_in)
    {
        id = id_in;

        int name_len = strlen(name_in) + 1;
        int major_len = strlen(major_in) + 1;
        strcpy(name, name_in);
        strcpy(major, major_in);
    }
    void PrintStudent()
    {
        cout << "Student ID: " << id << endl;
        cout << "Student name: " << name << endl;
        cout << "Student major: " << major << endl;
    }
    int GetID()
    {
        return id;
    }

private:
    int id;
    char *name;
    char *major;
};

int main(void)
{
    int students;
    cout << "Enter number of students: ";
    cin >> students;

    CStudent *list = new CStudent[students];

    delete list;
    return 0;
}
