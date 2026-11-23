#include <iostream>
#include <iomanip>
#include "Student.h"

using namespace std;

// Створення динамічного масиву студентів
Student* createStudents(int n)
{
    return new Student[n];
}

// Введення даних студентів
void inputStudents(Student* students, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nStudent " << i + 1 << endl;

        cout << "Surname: ";
        cin >> students[i].surname;

        cout << "Course: ";
        cin >> students[i].course;

        int specialty;
        cout << "Specialty:" << endl;
        cout << "1 - Computer Science" << endl;
        cout << "2 - Informatics" << endl;
        cout << "3 - Math and Economics" << endl;
        cout << "4 - Physics and Informatics" << endl;
        cout << "5 - Labor Training" << endl;
        cout << "Choose specialty (1-5): ";
        cin >> specialty;

        while (specialty < 1 || specialty > 5)
        {
            cout << "Invalid choice. Enter a number from 1 to 5: ";
            cin >> specialty;
        }

        students[i].specialty = static_cast<Specialty>(specialty - 1);

        cout << "Physics grade: ";
        cin >> students[i].physics;

        cout << "Mathematics grade: ";
        cin >> students[i].mathematics;

        switch (students[i].specialty)
        {
        case ComputerScience:
            cout << "Programming grade: ";
            cin >> students[i].thirdGrade.programming;
            break;

        case Informatics:
            cout << "Numerical Methods grade: ";
            cin >> students[i].thirdGrade.numericalMethods;
            break;

        default:
            cout << "Pedagogy grade: ";
            cin >> students[i].thirdGrade.pedagogy;
            break;
        }
    }
}

// Отримання назви спеціальності
string getSpecialtyName(Specialty specialty)
{
    switch (specialty)
    {
    case ComputerScience: return "Computer Science";
    case Informatics: return "Informatics";
    case MathEconomics: return "Math and Economics";
    case PhysicsInformatics: return "Physics and Informatics";
    case LaborTraining: return "Labor Training";
    default: return "Unknown";
    }
}

// Отримання назви третього предмета
string getThirdSubjectName(Specialty specialty)
{
    switch (specialty)
    {
    case ComputerScience: return "Programming";
    case Informatics: return "Numerical Methods";
    default: return "Pedagogy";
    }
}

// Отримання третьої оцінки з об'єднання
int getThirdGrade(const Student& student)
{
    switch (student.specialty)
    {
    case ComputerScience:
        return student.thirdGrade.programming;

    case Informatics:
        return student.thirdGrade.numericalMethods;

    default:
        return student.thirdGrade.pedagogy;
    }
}

// Виведення таблиці студентів
void printStudents(const Student* students, int n)
{
    cout << "\nSTUDENT INFORMATION\n\n";

    cout << left
        << setw(5) << "No."
        << setw(15) << "Surname"
        << setw(8) << "Course"
        << setw(25) << "Specialty"
        << setw(10) << "Physics"
        << setw(10) << "Math"
        << setw(15) << "Programming"
        << setw(20) << "Numerical Methods"
        << setw(12) << "Pedagogy" << endl;

    cout << string(120, '-') << endl;

    for (int i = 0; i < n; i++)
    {
        cout << left
            << setw(5) << i + 1
            << setw(15) << students[i].surname
            << setw(8) << students[i].course
            << setw(25) << getSpecialtyName(students[i].specialty)
            << setw(10) << students[i].physics
            << setw(10) << students[i].mathematics;

        if (students[i].specialty == ComputerScience)
        {
            cout << setw(15) << students[i].thirdGrade.programming
                << setw(20) << ""
                << setw(12) << "";
        }
        else if (students[i].specialty == Informatics)
        {
            cout << setw(15) << ""
                << setw(20) << students[i].thirdGrade.numericalMethods
                << setw(12) << "";
        }
        else
        {
            cout << setw(15) << ""
                << setw(20) << ""
                << setw(12) << students[i].thirdGrade.pedagogy;
        }

        cout << endl;
    }
}

// Підрахунок оцінок з фізики
void countPhysicsGrades(const Student* students, int n,
    int& count5, int& count4, int& count3)
{
    for (int i = 0; i < n; i++)
    {
        if (students[i].physics == 5)
            count5++;
        else if (students[i].physics == 4)
            count4++;
        else if (students[i].physics == 3)
            count3++;
    }
}

// Підрахунок студентів з оцінками 4 або 5
// одночасно з фізики та математики
int countStudentsWithGoodGrades(const Student* students, int n)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if ((students[i].physics == 4 || students[i].physics == 5) &&
            (students[i].mathematics == 4 || students[i].mathematics == 5))
        {
            count++;
        }
    }

    return count;
}
