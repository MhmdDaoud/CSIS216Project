/*-- StudentList.cpp-------------------------------------------------------
   This file implements Student member functions.
-------------------------------------------------------------------------*/
#include "StudentList.h"

//--- Definition of searchById()
int StudentList::searchById(const string &studentID) const
{
    if (!isEmpty())
    {
        for (int i = 0; i < mySize; i++)
        {
            Student currStd = getDataAtPosition(i);
            if (currStd.getStudentId() == studentID)
            {
                return i;
            }
        }
    }
    return -1;
}

//--- Definition of retrieveStudent()
Student &StudentList::retrieveStudent(const string &studentID)
{
    for (int i = 0; i < mySize; ++i)
    {
        Student &currStudent = getDataAtPosition(i);
        if (currStudent.getStudentId() == studentID)
        {
            return currStudent;
        }
    }
    throw runtime_error("Student Not Found");
}

//--- Definition of getRegCoursesForStud()
CourseList &StudentList::getRegCoursesForStud(const string &studentID)
{
    if (!isEmpty())
    {
        int studPos = searchById(studentID);
        if (studPos != -1)
        {
            Student &s = getDataAtPosition(studPos);
            return s.getRegisteredCourses();
        }
    }
    throw runtime_error("Could not find student courses");
}

//--- Definition of getStudRegInCourse()
StudentList StudentList::getStudRegInCourse(const string &courseID)
{
    if (!isEmpty())
    {
        StudentList students;
        for (int i = 0; i < mySize; i++)
        {
            Student &currStd = getDataAtPosition(i);
            CourseList &currStdRegCourses = currStd.getRegisteredCourses();
            if (currStdRegCourses.containsCourse(courseID))
            {
                students.insertAtEnd(currStd);
            }
        }
        return students;
    }
    throw runtime_error("Student List is Empty.");
}

//--- Definition of removeById()
bool StudentList::removeById(const string &studentID)
{
    if (!isEmpty())
    {
        int studPos = searchById(studentID);
        if (studPos != -1)
        {
            return removeAtPosition(studPos);
        }
    }
    return false;
}
