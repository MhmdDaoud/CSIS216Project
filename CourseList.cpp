#include "CourseList.h"

bool CourseList::dropByCourseId(const string &courseID) {
    if (!isEmpty()) {
        int coursePos = searchByCourseId(courseID);
        if (coursePos != -1) {
            return removeAtPosition(coursePos);
        }
    }
    return false;
}

bool CourseList::containsCourse(const string &courseID) const {
    if (!isEmpty()) {
        int coursePos = searchByCourseId(courseID);
        return coursePos != -1;
    }
    return false;
}

int CourseList::searchByCourseId(const string &courseID) const {
    if (!isEmpty()) {
        int counter = 0;
        while (counter < mySize) {
            Course currCourse = getDataAtPosition(counter);
            if (currCourse.getCourseCode() == courseID) {
                return counter;
            }
            counter++;
        }
    }
    return -1;
}

Course CourseList::retrieveCourse(const std::string &courseCode) {
    if (!isEmpty()) {
        int counter = 0;
        while (counter < mySize) {
            Course currCourse = getDataAtPosition(counter);
            if (currCourse.getCourseCode() == courseCode) {
                return currCourse;
            }
            counter++;
        }
    }
    Course g;
    cout << "Course not found" << endl;
    return g;
}
