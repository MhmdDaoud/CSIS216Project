/* StudentList.h ----------------------------------------------------------
   Header file for a child class StudentList that encapsulates the utility
   functions common to all student lists.
   Operations are:
    drop:                   Remove a Student object from the list
    specific search: 		Retrieve the index or const reference of a specific object
    get info:               Retrieve a list of students registered in a course
                            or courses registered for a student
--------------------------------------------------------------------------*/
#ifndef STUDENT_L
#define STUDENT_L

#include "DoublyLinkedList.h"
#include "Student.h"

class StudentList : public DoublyLinkedList<Student>
{
public:
    /******** Function Members ********/
    int searchById(const string &) const;
    /*----------------------------------------------------------------------
     Search for a Student with a specific ID in the list.

     Precondition: none.
     Postcondition: Returns the index of the desired student if found,
     -1 otherwise.
    -----------------------------------------------------------------------*/

    Student &retrieveStudent(const string &);
    /*----------------------------------------------------------------------
     Retrieve a Student object from the list.

     Precondition: none.
     Postcondition: Returns a const reference to a Student object if found,
     throws runtime_error exception otherwise.
    -----------------------------------------------------------------------*/

    CourseList& getRegCoursesForStud(const string &);
    /*----------------------------------------------------------------------
     Retrieve a copy CourseList object containing the registered courses
     for a specific Student.

     Precondition: none.
     Postcondition: Returns a copy to a CourseList object if found,
     throws runtime_error exception with message "Could not find student courses".
    -----------------------------------------------------------------------*/

    StudentList getStudRegInCourse(const string &);
    /*----------------------------------------------------------------------
     Retrieve a copy StudentList object containing the registered students
     in a specific course.

     Precondition: none.
     Postcondition: Returns a copy to a StudentList object if it's not empty,
     throws runtime_error if is is.
    -----------------------------------------------------------------------*/

    bool removeById(const string &);
    /*----------------------------------------------------------------------
     Delete a Student with a specific ID from the list.

     Precondition: none.
     Postcondition: Returns true if the Student with the desired studentId was
     deleted sucessfully, false otherwise.
    -----------------------------------------------------------------------*/
};

#endif //--- End of class declaration
