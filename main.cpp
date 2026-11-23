
#include <iostream>
#include "Student.h"

using namespace std;

int main()
{
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid number of students!" << endl;
        return 1;
    }

    Student* students = createStudents(n);

    inputStudents(students, n);

    printStudents(students, n);

    int count5 = 0;
    int count4 = 0;
    int count3 = 0;

    countPhysicsGrades(students, n, count5, count4, count3);

    cout << "\nTask 1. Physics grades:" << endl;
    cout << "Grade 5: " << count5 << endl;
    cout << "Grade 4: " << count4 << endl;
    cout << "Grade 3: " << count3 << endl;

    int goodStudents = countStudentsWithGoodGrades(students, n);

    cout << "\nTask 2. Students with grades 4 or 5 in Physics and Mathematics: "
        << goodStudents << endl;

    delete[] students;

    return 0;
}
