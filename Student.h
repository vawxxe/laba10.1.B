#pragma once

#include <string>

using namespace std;

// Перелік спеціальностей
enum Specialty
{
    ComputerScience,
    Informatics,
    MathEconomics,
    PhysicsInformatics,
    LaborTraining
};

// Об'єднання для третьої оцінки
union ThirdGrade
{
    int programming;
    int numericalMethods;
    int pedagogy;
};

// Структура студента
struct Student
{
    string surname;
    int course;
    Specialty specialty;
    int physics;
    int mathematics;
    ThirdGrade thirdGrade;
};

// Оголошення функцій
Student* createStudents(int n);
void inputStudents(Student* students, int n);
void printStudents(const Student* students, int n);
void countPhysicsGrades(const Student* students, int n,
    int& count5, int& count4, int& count3);
int countStudentsWithGoodGrades(const Student* students, int n);
string getSpecialtyName(Specialty specialty);
int getThirdGrade(const Student& student);
string getThirdSubjectName(Specialty specialty);
#pragma once
