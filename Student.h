/* Students.h --------------------------------------------------------------
   Header file for a class Student that encapsulates the attributes common
   to all students.
   Operations are:
    init: 		Constructs a student with default data
    getters:	Retrieve data from the class data fields
    setters: 	Mutators of the data fields
    display:	Display the student's information
--------------------------------------------------------------------------*/
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
    /******** Function Members ********/
    /***** Class constructor *****/
    void Init(const string studentId, const string firstName, const string lastName,
              const string major, const float gpa);
    /*----------------------------------------------------------------------
     Constructs a student object with default data values.

     Precondition:  None
     Postcondition: A Student with default data values has been constructed.
     studentId is set to "N/A", firstName is set to "N/A",
     lastName is set to "N/A", major is set to "N/A", gpa is set to 0,
     and academicStatus is set to "NORMAL" or "PROBATION" based on GPA.
    -----------------------------------------------------------------------*/

    string getStudentId() const;
    /*----------------------------------------------------------------------
     Retrieves the student ID data field.

     Precondition:  None
     Postcondition: returns the ID of the student.
    -----------------------------------------------------------------------*/

    string getStudentName() const;
    /*----------------------------------------------------------------------
     Retrieves the student's full name.

     Precondition:  None
     Postcondition: returns the firstName and lastName of a student in the form:
     "lastName, firstName".
    -----------------------------------------------------------------------*/

    string getStudentMajor() const;
    /*----------------------------------------------------------------------
     Retrieves the student major data field.

     Precondition:  None
     Postcondition: returns the major of the student.
    -----------------------------------------------------------------------*/

    float getStudentGpa() const;
    /*----------------------------------------------------------------------
     Retrieves the student GPA data field.

     Precondition:  None
     Postcondition: returns the GPA of the student.
    -----------------------------------------------------------------------*/

    string getStudentAcademicStatus() const;
    /*----------------------------------------------------------------------
     Retrieves the student academic status data field.

     Precondition:  None
     Postcondition: returns the academicStatus of the student.
    -----------------------------------------------------------------------*/

    CourseList &getRegisteredCourses();
    /*----------------------------------------------------------------------
     Retrieves a list of the courses that the student is registered in.

     Precondition:  None
     Postcondition: returns a CourseList const reference containing the Course elements.
    -----------------------------------------------------------------------*/

    void setStudent(const string, const string, const string, const string, const float);
    /*----------------------------------------------------------------------
     Sets the Student object.

     Precondition:  ID must be valid
                    firsName must be alphabetic
                    lastName must be alphabetic
                     0 < gpa <= 4.0
     Postcondition: sets the Student data fields to the respective parameters.
    -----------------------------------------------------------------------*/

    void setStudentId(const string);
    /*----------------------------------------------------------------------
     Sets the Student ID data field.

     Precondition:  ID must be valid
     Postcondition: sets the Student ID to the given parameter.
    -----------------------------------------------------------------------*/

    void setStudentFirstName(const string &);
    /*----------------------------------------------------------------------
     Sets the Student first name data field.

     Precondition:  firstName must be valid (alphabetic)
     Postcondition: sets the Student firstName to the given parameter.
    -----------------------------------------------------------------------*/

    void setStudentLastName(const string &);
    /*----------------------------------------------------------------------
     Sets the Student last name data field.

     Precondition:  lastName must be valid (alphabetic)
     Postcondition: sets the Student lastName to the given parameter.
    -----------------------------------------------------------------------*/

    void setStudentMajor(const string);
    /*----------------------------------------------------------------------
     Sets the Student major data field.

     Precondition: none
     Postcondition: sets the Student major to the given parameter.
    -----------------------------------------------------------------------*/

    void setGpa(const float);
    /*----------------------------------------------------------------------
     Sets the Student GPA data field.

     Precondition: 0 < gpa <= 4.0
     Postcondition: sets the Student gpa to the given parameter.
    -----------------------------------------------------------------------*/

    void setAcademicStatus();
    /*----------------------------------------------------------------------
     Sets the Student academic status data field.

     Precondition: none.
     Postcondition: sets the Student academicStatus to the NORMAL if GPA > 2.0,
     PROBATION otherwise.
    -----------------------------------------------------------------------*/

    void setRegisteredCourses(const CourseList &);
    /*----------------------------------------------------------------------
     Sets the Student registered courses data field.

     Precondition: valid CourseList const reference parameter
     Postcondition: sets the Student registeredCourses to the given
     CourseList object reference.
    -----------------------------------------------------------------------*/

    /***** Utility functions *****/
    void displayStudentInfo() const;
    /*-----------------------------------------------------------------------
     Display student information

     Precondition:  ostream out is open.
     Postcondition: detailed info about the student has been output to out.
    -----------------------------------------------------------------------*/

    string simpleDisplay() const;
    /*-----------------------------------------------------------------------
     Display simple student information

     Precondition:  none.
     Postcondition: returns a string with the format: "ID - lastName, firstName".
    -----------------------------------------------------------------------*/

    void displayCourseInfo() const;
    /*-----------------------------------------------------------------------
     Display values stored in the CourseList registeredCourses data field.

     Precondition:  ostream out is open.
     Postcondition: List's contents, from beginning to end, have been
     output to out.
    -----------------------------------------------------------------------*/

private:
    string studentId;             // Student ID
    string firstName;             // Student first name
    string lastName;              // Student last name
    string major;                 // Student major
    float gpa;                    // Student major
    CourseList registeredCourses; // CourseList used to store registeredCourses for a Student
    string academicStatus;        // Student academic status

    bool validateId(const string) const;
    /*-----------------------------------------------------------------------
     Validate a string containing an ID.

     Precondition:  none.
     Postcondition: returns true if the ID is of length 8 characters
     and having the first character as 'A' (non case-sensitive), false otherwise.
    -----------------------------------------------------------------------*/
};

/******* Non-member functions *******/
//--- Declaration of overloaded output operator
ostream &operator<<(ostream &, const Student &);

#endif //--- End of class declaration
