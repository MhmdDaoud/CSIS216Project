#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <new>
#include "CourseList.h"

using namespace std;

class Student
{
public:
    void Init(const string studentId, const string firstName, const string lastName,
              const string major, const float gpa, const string academicStatus);
    string getStudentId() const;
    string getStudentName() const;
    string getStudentMajor() const;
    float getStudentGpa() const;
    string getStudentAcademicStatus() const;
    CourseList& getRegisteredCourses();

    void setStudent(const string, const string, const string, const string, const float, const string);
    void setStudentId(const string);
    void setStudentFirstName(const string&);
    void setStudentLastName(const string&);
    void setStudentMajor(const string);
    void setGpa(const float);
    void setAcademicStatus(const string);
    void setRegisteredCourses(const CourseList&);
    void displayStudentInfo() const;
    void simpleDisplay() const;
    void displayCourseInfo() const;

private:
    string studentId;
    string firstName;
    string lastName;
    string major;
    float gpa;
    CourseList registeredCourses;
    string academicStatus;

    bool validateId(const string) const;
};
ostream &operator<<(ostream &, const Student &);
#endif