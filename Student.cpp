#include "Student.h"

void Student::Init(const string studentId = "N/A", const string firstName = "N/A", const string lastName = "N/A",
                   const string major = "N/A", const float gpa = -1, const string academicStatus = "N/A") {
    setStudent(studentId, firstName, lastName, major, gpa, academicStatus);
}

CourseList &Student::getRegisteredCourses() {
    return registeredCourses;
}

string Student::getStudentId() const {
    return studentId;
}

string Student::getStudentName() const {
    return lastName + ", " + firstName;
}

string Student::getStudentMajor() const {
    return major;
}

float Student::getStudentGpa() const {
    return gpa;
}

string Student::getStudentAcademicStatus() const {
    return academicStatus;
}

void Student::setStudent(const string studentId, const string firstName, const string lastName,
                         const string major, const float gpa, const string academicStatus) {
    setStudentId(studentId);
    setStudentFirstName(firstName);
    setStudentLastName(lastName);
    setStudentMajor(major);
    setGpa(gpa);
    setAcademicStatus(academicStatus);
}

void Student::setStudentId(const string studentId) {
    if (validateId(studentId)) {
        this->studentId = studentId;
    } else {
        cerr << "Invalid ID.";
    }
}

void Student::setStudentFirstName(const string &name) {
    for (int i = 0; i < name.length(); ++i) {
        if (isalpha(name[i])) {
            firstName = name;
        } else {
            cerr << "Name cannot contain numbers or special characters.";
        }
    }
}

void Student::setStudentLastName(const string &name) {
    for (int i = 0; i < name.length(); ++i) {
        if (isalpha(name[i])) {
            lastName = name;
        } else {
            cerr << "Name cannot contain numbers or special characters.";
        }
    }
}

void Student::setStudentMajor(const string major) {
    this->major = major;
}

void Student::setGpa(const float gpa) {
    if (gpa > 0) {
        this->gpa = gpa;
    } else {
        cerr << "Invalid GPA.";
    }
}

void Student::setAcademicStatus(const string academicStatus) {
    this->academicStatus = academicStatus;
}

void Student::displayStudentInfo() const {
    string name = lastName + ", " + firstName;
    cout << left << setw(15) << studentId
         << setw(20) << name
         << setw(8) << gpa
         << setw(15) << academicStatus;
}

void Student::simpleDisplay() const {
    cout << studentId << " - " << lastName << ", " << firstName << endl;
}

void Student::displayCourseInfo() const {
    for (int i = 0; i < registeredCourses.size(); ++i) {
        cout << registeredCourses.getDataAtPosition(i);
    }
}

bool Student::validateId(const string studentId) const {
    if (studentId.length() != 8 || toupper(studentId[0]) != 'A') {
        return false;
    }

    for (int i = 1; i < studentId.length(); ++i) {
        if (!isdigit(studentId[i])) {
            return false;
        }
    }

    return true;
}

void Student::setRegisteredCourses(const CourseList &courseList) {
    this->registeredCourses = courseList;
}

ostream &operator<<(ostream &out, const Student &ref) {
    ref.displayStudentInfo();
    out << endl;
    ref.displayCourseInfo();
    return out;
}