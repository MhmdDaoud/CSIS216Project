/*-- Student.cpp-----------------------------------------------------------
   This file implements Student member functions.
-------------------------------------------------------------------------*/

#include "Student.h"

/***** Constructor *****/
//--- Definition of Init()
void Student::Init(const string studentId = "N/A", const string firstName = "N/A", const string lastName = "N/A",
                   const string major = "N/A", const float gpa = -1)
{
    setStudent(studentId, firstName, lastName, major, gpa);
}

/***** Getters *****/
//--- Definition of getStudentId()
string Student::getStudentId() const
{
    return studentId;
}

//--- Definition of getStudentName()
string Student::getStudentName() const
{
    return lastName + ", " + firstName;
}

//--- Definition of getStudentMajor()
string Student::getStudentMajor() const
{
    return major;
}

//--- Definition of getStudentGpa()
float Student::getStudentGpa() const
{
    return gpa;
}

//--- Definition of getAcademicStatus()
string Student::getStudentAcademicStatus() const
{
    return academicStatus;
}

//--- Definition of getRegisteredCourses()
CourseList &Student::getRegisteredCourses()
{
    return registeredCourses;
}

/***** Setters *****/
//--- Definition of setStudentId()
void Student::setStudentId(const string studentId)
{
    if (validateId(studentId))
    {
        this->studentId = studentId;
    }
    else
    {
        cerr << "Invalid ID.";
    }
}

//--- Definition of setStudentFirstName()
void Student::setStudentFirstName(const string &name)
{
    for (int i = 0; i < name.length(); ++i)
    {
        if (isalpha(name[i]))
        {
            firstName = name;
        }
        else
        {
            cerr << "Name cannot contain numbers or special characters.";
        }
    }
}

//--- Definition of setStudentLastName()
void Student::setStudentLastName(const string &name)
{
    for (int i = 0; i < name.length(); ++i)
    {
        if (isalpha(name[i]))
        {
            lastName = name;
        }
        else
        {
            cerr << "Name cannot contain numbers or special characters.";
        }
    }
}

//--- Definition of setStudentMajor()
void Student::setStudentMajor(const string major)
{
    this->major = major;
}

//--- Definition of setGpa()
void Student::setGpa(const float gpa)
{
    if (gpa > 0)
    {
        this->gpa = gpa;
    }
    else
    {
        cerr << "Invalid GPA.";
    }
}

//--- Definition of setAcademicStatus()
void Student::setAcademicStatus()
{
    if (gpa <= 2)
    {
        academicStatus = "PROBATION";
    }
    else
    {
        academicStatus = "NORMAL";
    }
}

//--- Definition of setStudent()
void Student::setStudent(const string studentId, const string firstName, const string lastName,
                         const string major, const float gpa)
{
    setStudentId(studentId);
    setStudentFirstName(firstName);
    setStudentLastName(lastName);
    setStudentMajor(major);
    setGpa(gpa);
    setAcademicStatus();
}

//--- Definition of setRegisteredCourses()
void Student::setRegisteredCourses(const CourseList &courseList)
{
    this->registeredCourses = courseList;
}

//--- Definition of displayStudentInfo()
void Student::displayStudentInfo() const
{
    string name = lastName + ", " + firstName;
    cout << left << setw(15) << studentId
         << setw(20) << name
         << setw(8) << gpa
         << setw(15) << academicStatus;
}

//--- Definition of simpleDisplay()
string Student::simpleDisplay() const
{
    return studentId + " - " + lastName + ", " + firstName + '\n';
}

//--- Definition of displayCourseInfo()
void Student::displayCourseInfo() const
{
    for (int i = 0; i < registeredCourses.size(); ++i)
    {
        cout << registeredCourses.getDataAtPosition(i);
    }
}

//--- Definition of private function validateId()
bool Student::validateId(const string studentId) const
{
    if (studentId.length() != 8 || toupper(studentId[0]) != 'A')
    {
        return false;
    }

    for (int i = 1; i < studentId.length(); ++i)
    {
        if (!isdigit(studentId[i]))
        {
            return false;
        }
    }
    return true;
}

/*------------------------------------------------------------------------
    Implementation of non-member functions
-------------------------------------------------------------------------*/

//--- Definition of overloaded output operator
ostream &operator<<(ostream &out, const Student &ref)
{
    ref.displayStudentInfo();
    out << endl;
    ref.displayCourseInfo();
    return out;
}
