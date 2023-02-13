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
    // public methods
    void SetStudent(int id_in, string name_in, string major_in,
                    string lecture, int grade)
    {
        id = id_in;
        name = name_in;
        major = major_in;

        SetLecture(lecture, grade);
    }
    // set CLecture separately
    void SetStudent(int id_in, string name_in, string major_in)
    {
        id = id_in;
        name = name_in;
        major = major_in;
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
        bool dupe = false;
        do
        {
            cout << "Enter Student ID, Name, Major, Lecture, Grade: ";
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
                dupe = false;   // re-init dupe for loop
            }
        } while (dupe == true);

        // list[i].SetStudent(id, name, major, lecture, grade);
        list[i].SetStudent(id, name, major);
        list[i].SetLecture(lecture, grade);
    }

    for (int i = 0; i < students; i++)
    {
        cout << i + 1 << ") ";
        list[i].PrintStudent();
    }

    delete[] list;
    return 0;
}
