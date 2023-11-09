#include <fstream>
#include "StudentList.h"
#include "CourseList.h"

using namespace std;

void menu() {
    cout << "1. Display the list of non-registered students." << endl
         << "2. Display the list of offered courses." << endl
         << "3. Display the list of registered students with the registered courses." << endl
         << "4. Display the list of offered courses with the registered students." << endl
         << "5. Display the registered courses for a student." << endl
         << "6. Display the list of students registered in a course" << endl
         << "7. Display the information related to a specific student." << endl
         << "8. Register a student." << endl
         << "9. Choose a student to add/drop a course for him/her." << endl
         << "10. Quit the application." << endl
         << endl
         << "Enter your choice: ";
}

int main() {

    // Reading data from Students.txt
    ifstream studentsFile("Students.txt");

    if (!studentsFile.is_open()) {
        cerr << "Unable to open file: Students.txt";
        return 1;
    }

    int nbOfStudents;
    studentsFile >> nbOfStudents;
    studentsFile.ignore(1024, '\n');

    StudentList nonRegisteredStudents;
    for (int stdCounter = 0; stdCounter < nbOfStudents; ++stdCounter) {
        Student s;
        string id, firstName, lastName;
        float gpa;
        studentsFile >> id >> firstName >> lastName >> gpa;
        s.Init(id, firstName, lastName, "N/A", gpa, "N/A");
        nonRegisteredStudents.insertAtEnd(s);
    }
    studentsFile.close();

    // Reading data from Courses.txt
    ifstream coursesFile("Courses.txt");

    if (!coursesFile.is_open()) {
        cerr << "Unable to open file: Courses.txt";
        return 1;
    }

    int nbOfCourses;
    coursesFile >> nbOfCourses;
    coursesFile.ignore(1024, '\n');

    CourseList offeredCourses;
    for (int cCounter = 0; cCounter < nbOfCourses; ++cCounter) {
        Course c;
        string code, title, line;
        int nbOfCredits, capacity;

        coursesFile >> code;
        coursesFile.ignore();

        while (!isdigit(coursesFile.peek())) {
            title += coursesFile.get();
        }

        coursesFile >> nbOfCredits >> capacity;
        c.Init(code, title, nbOfCredits, capacity);
        offeredCourses.insertAtEnd(c);
    }

    cout << nonRegisteredStudents << endl;
    cout << offeredCourses << endl;
    
    return 0;
}
