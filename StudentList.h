#ifndef STUDENT_L
#define STUDENT_L

#include "DoublyLinkedList.h"
#include "Student.h"
class StudentList : public DoublyLinkedList<Student>
{
public:
    int searchById(const string &) const;
    Student retrieveStudent(const string &);
    bool removeById(const string &);
    CourseList getRegCoursesForStud(const string &) const;
    StudentList getStudRegInCourse(const string &) const;
};
#endif