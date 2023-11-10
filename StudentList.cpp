#include "StudentList.h"

int StudentList::searchById(const string &studentID) const {
    if (!isEmpty()) {
        for (int i = 0; i < mySize; i++) {
            Student currStd = getDataAtPosition(i);
            if (currStd.getStudentId() == studentID) {
                return i;
            }
        }
    }
    return -1;
}

Student& StudentList::retrieveStudent(const string &studentID) {
    if (!isEmpty()) {
        for (int i = 0; i < mySize; ++i) {
            Student currStd = getDataAtPosition(i);
            if (currStd.getStudentId() == studentID) {
                return currStd;
            }
        }
    }
    throw runtime_error("Student not found");
}

CourseList StudentList::getRegCoursesForStud(const string &studentID) {
    CourseList g;
    if (!isEmpty()) {
        int studPos = searchById(studentID);
        if (studPos != -1) {
            Student s = getDataAtPosition(studPos);
            return s.getRegisteredCourses();
        }
    }
    cout << "Could not find student courses" << endl;
    return g;
}

StudentList StudentList::getStudRegInCourse(const string &courseID) {
    StudentList students;
    if (!isEmpty()) {
        for (int i = 0; i < mySize; i++) {
            Student currStd = getDataAtPosition(i);
            CourseList currStdRegCourses = currStd.getRegisteredCourses();
            if (currStdRegCourses.containsCourse(courseID)) {
                students.insertAtEnd(currStd);
            }
        }
        return students;
    }
    return students;
}


bool StudentList::removeById(const string &studentID) {
    if (!isEmpty()) {
        int studPos = searchById(studentID);
        if (studPos != -1) {
            return removeAtPosition(studPos);
        }
    }
    return false;
}