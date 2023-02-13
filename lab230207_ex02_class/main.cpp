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
    // CLecture(char *lect, int grd): grade(grd)
    // {
    //     int len = strlen(lect) + 1;
    //     lecture_name = new char[len];
    //     strcpy(lecture_name, lect);
    // }
    // CLecture(): grade(0)      // default constructor
    // {
    //     lecture_name = NULL;
    // }
    // ~CLecture()     // destructor to release allocated memory
    // {
    //     if (lecture_name != NULL)
    //         delete[] lecture_name;
    // }

    // public methods
    void SetLecture(string lect, int grd)
    {
        lecture_name = lect;
        grade = grd;
    }

protected:
    string lecture_name;
    int grade;
};

class CStudent: public CLecture
{
public:
    // constructors & destructors
    // CStudent(): id(0)
    // {
    //     name = NULL;
    //     major = NULL;
    // }
    // ~CStudent()     // destructor to release allocated memory
    // {
    //     if (name != NULL)
    //         delete[] name;
    //     if (major != NULL)
    //         delete[] major;
    // }

    // public methods
    void SetStudent(int id_in, string name_in, string major_in,
                    string lecture, int grade)
    {
        id = id_in;
        name = name_in;
        major = major_in;

        SetLecture(lecture, grade);
    }
    void PrintStudent()
    {
        cout << "Student ID: " << id << ", Name: " << name << ", Major: " << major;
        cout << ", Lecture: " << lecture_name << ", Grade: " << grade << endl;
    }
    int GetID()
    {
        return id;
    }

private:
    int id;
    string name;
    string major;
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
        do
        {
            dupe = false;
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
        } while (dupe == true);

        list[i].SetStudent(id, name, major, lecture, grade);
    }

    for (int i = 0; i < students; i++)
    {
        list[i].PrintStudent();
    }

    delete[] list;
    return 0;
}
