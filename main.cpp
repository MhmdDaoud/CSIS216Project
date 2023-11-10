#include <fstream>
#include "StudentList.h"
#include "CourseList.h"
#include <cctype>

using namespace std;

string toUppercase(string str) {
    for (char &c: str) {
        c = toupper(c);
    }
    return str;
}

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
         << "Enter your choice:";
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
    coursesFile.close();

    StudentList registeredStudents;

    int userChoice;
    do {
        menu();
        cin >> userChoice;

        switch (userChoice) {
            case 1: // WORKING AS INTENDED
                // Displaying non-registered students
                cout << left << "Students that didn't register yet." << endl
                     << setw(15) << "ID"
                     << setw(20) << "Name"
                     << setw(8) << "GPA"
                     << setw(15) << "Academic Status" << endl
                     << nonRegisteredStudents;
                break;

            case 2: // WORKING AS INTENDED
                // Displaying all offered courses
                cout << left << setw(15) << "Course"
                     << setw(35) << "Title"
                     << setw(15) << "# Credits"
                     << setw(15) << "Enrolled"
                     << setw(15) << "Capacity" << endl
                     << offeredCourses;
                break;

            case 3:
                // Displaying registered students with the registered courses
                for (int i = 0; i < registeredStudents.size(); ++i) {
                    Student currentStudent = registeredStudents.getDataAtPosition(i);
                    string currentID = currentStudent.getStudentId();
                    cout << "Student:" << currentStudent.simpleDisplay(); // "ID - lastName, firstName"
                    CourseList regCourses = registeredStudents.getRegCoursesForStud(currentID);
                    if (regCourses.size() > 0) {
                        cout << "Registered Courses:" << endl;

                        for (int j = 0; j < regCourses.size(); ++j) {
                            Course currentCourse = regCourses.getDataAtPosition(j);
                            cout << currentCourse.simpleDisplay() << endl; // "courseCode - courseTitle"
                        }
                    } else {
                        cout << "\tNo registered courses" << endl;
                    }
                }
                break;

            case 4:
                // Displaying offered courses with the registered students
                for (int i = 0; i < offeredCourses.size(); ++i) {
                    Course currentCourse = offeredCourses.getDataAtPosition(i);
                    string currentCode = currentCourse.getCourseCode();
                    cout << "Course:" << currentCourse.simpleDisplay(); // "courseCode - courseTitle"
                    StudentList regStudents = registeredStudents.getStudRegInCourse(currentCode);
                    for (int j = 0; j < regStudents.size(); ++j) {
                        regStudents.getDataAtPosition(j).simpleDisplay(); // "ID - lastName, firstName"
                    }
                }
                break;

            case 5: {
                // Displaying registered courses for a student
                string studentId;
                cout << "Enter the students ID:";
                cin >> studentId;
                Student currentStudent = registeredStudents.retrieveStudent(studentId);
                cout << "Student:" << currentStudent.simpleDisplay(); // "ID - lastName, firstName"
                CourseList regCourses = registeredStudents.getRegCoursesForStud(studentId);
                for (int i = 0; i < regCourses.size(); ++i) {
                    regCourses.getDataAtPosition(i).simpleDisplay(); // "courseCode - courseTitle"
                }
                break;
            }

            case 6: {
                // Displaying students in a registered course
                string courseCode;
                cout << "Enter the course code:";
                cin >> courseCode;
                Course currentCourse = offeredCourses.retrieveCourse(toUppercase(courseCode));
                cout << "Course:" << currentCourse.simpleDisplay(); // "courseCode - courseTitle"
                StudentList regStd = registeredStudents.getStudRegInCourse(toUppercase(courseCode));
                for (int i = 0; i < regStd.size(); ++i) {
                    regStd.getDataAtPosition(i).simpleDisplay(); // "ID - lastName, firstName"
                }
                break;
            }

            case 7: { // WORKING AS INTENDED
                // Displaying student information
                string studentId;
                cout << "Enter the student ID:";
                cin >> studentId;
                Student currentStudent = registeredStudents.retrieveStudent(studentId);
                cout << currentStudent.getStudentId();
                if (!currentStudent.getStudentId().empty()) {
                    cout << "Student:" << endl
                         << "\tID: " << currentStudent.getStudentId() << endl
                         << "\tName: " << currentStudent.getStudentName() << endl
                         << "\tMajor: " << currentStudent.getStudentMajor() << endl
                         << "\tGPA: " << currentStudent.getStudentGpa() << endl;
                }
                break;
            }

            case 8: { // WORKING AS INTENDED
                // Registering a student
                char userChar;
                string studentId;
                cout << "Enter the student ID:";
                cin >> studentId;
                if (nonRegisteredStudents.searchById(studentId) == -1) {
                    cerr << "Student not found" << endl;
                    break;
                }
                Student currentStudent = nonRegisteredStudents.retrieveStudent(studentId);
                nonRegisteredStudents.removeById(studentId);
                registeredStudents.insertAtEnd(currentStudent);
                CourseList regCourses = currentStudent.getRegisteredCourses();

                do {
                    string courseCode;
                    cout << endl << "Enter the course code:";
                    cin >> courseCode;
                    if (offeredCourses.searchByCourseId(toUppercase(courseCode)) == -1) {
                        cout << "Course is not offered." << endl;
                        break;
                    } else {
                        Course currentCourse = offeredCourses.retrieveCourse(toUppercase(courseCode));
                        regCourses.insertAtEnd(currentCourse);
                        cout << "Student registered" << endl;
                        currentStudent.setRegisteredCourses(regCourses);
                        cout << currentStudent.getRegisteredCourses();
                    }
                    cout << "Do you need to add more courses [Y] yes or [N] no:";
                    cin >> userChar;

                } while (toupper(userChar) == 'Y');
                break;
            }

            case 9: {
                // Choose a student to add/drop course
                string studentId, courseCode;
                cout << "Enter the student ID:";
                cin >> studentId;
                Student currentStd = registeredStudents.retrieveStudent(studentId);
                if (currentStd.getStudentId() != studentId) break;
                cout << "Student:" << currentStd.simpleDisplay();
                CourseList studentCourses = currentStd.getRegisteredCourses();
                cout << "Courses:" << endl;
                for (int i = 0; i < studentCourses.size(); ++i) {
                    studentCourses.getDataAtPosition(i).simpleDisplay();
                }

                char userChar;
                do {
                    cout << endl << "Add course [A] or Drop course [D]:";
                    cin >> userChar;

                    cout << "Enter the course code:";
                    cin >> courseCode;

                    Course currentCourse = offeredCourses.retrieveCourse(toUppercase(courseCode));
                    if (currentCourse.getCourseCode() != courseCode) break;
                    int courseIndex = studentCourses.searchByCourseId(courseCode);

                    switch (toupper(userChar)) {
                        case 'A': // Add
                            studentCourses.insertAtEnd(currentCourse);
                            cout << "Course added successfully" << endl;
                            break;

                        case 'D':  // Drop
                            studentCourses.removeAtPosition(courseIndex);
                            break;

                        default:
                            cout << "Invalid input" << endl;
                            break;
                    }

                    cout << "Do you want to continue [Y] yes or [N] no:";
                    cin >> userChar;
                } while (toupper(userChar) != 'N');
                break;
            }

            case 10:
                cout << "Exiting application..." << endl;
                break;

            default:
                cout << "Invalid input" << endl;
        }
    } while (userChoice != 10);
    return 0;
}
