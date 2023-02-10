// Ex02 Using classes & inheritance
// for lecture & student management
// By: Ethan Baik

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class CLecture
{
public:
    // constructors & destructors
    CLecture(char *lect, int grd): grade(grd)
    {
        int len = strlen(lect) + 1;
        lecture_name = new char[len];
        strcpy(lecture_name, lect);
    }
    CLecture() = default;
    // ~CLecture()     // destructor to release allocated memory
    // {
    //     delete[] lecture_name;
    // }

    // public methods
    void SetLecture(char *lect, int grd)
    {
        int len = strlen(lect) + 1;
        lecture_name = new char[len];
        strcpy(lecture_name, lect);
        grade = grd;
    }

protected:
    char *lecture_name;
    int grade;
};

class CStudent: public CLecture
{
public:
    // constructors & destructors
    // ~CStudent()     // destructor to release allocated memory
    // {
    //     delete[] name;
    //     delete[] major;
    // }

    // public methods
    void SetStudent(int id_in, const char *name_in, const char *major_in,
                    char *lecture, int grade)
    {
        id = id_in;

        int name_len = strlen(name_in) + 1;
        int major_len = strlen(major_in) + 1;
        strcpy(name, name_in);
        strcpy(major, major_in);

        SetLecture(lecture, grade);
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

    int id, grade;
    string name, major, lecture;

    for (int i = 0; i < students; i++)
    {
        cout << "Enter Student ID, Name, Major, Lecture, Grade: ";

        bool dupe = false;
        while (dupe == false)
        {
            cin >> id >> name >> major >> lecture >> grade;

            // check duplicate id
            for (int j = 0; j < i; j++)
            {
                if (list[j].GetID() == id)
                {
                    // duplicate
                    cout << "Duplicate ID. Please re-enter information." << endl;
                    dupe = true;
                    break;
                }
            }
        }
    }


    delete[] list;
    return 0;
}
