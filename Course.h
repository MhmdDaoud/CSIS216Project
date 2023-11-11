/* Course.h --------------------------------------------------------------
   Header file for a class Course that encapsulates the attributes common
   to all courses.
   Operations are:
	init: 		Constructs a course with default data
	getters:	Retrieve data from the class data fields
	setters: 	Mutators of the data fields
	display:	Display the course information
--------------------------------------------------------------------------*/
#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
class Course
{
public:
	/***** Constructors *****/
	void Init(const string, const string, const int, const int);
	/*----------------------------------------------------------------------
	Constructs a student object with default data values.

	 Precondition:  None
	 Postcondition: A Student with default data values has been constructed.
	 studentId is set to "N/A", firstName is set to "N/A",
	 lastName is set to "N/A", major is set to "N/A", gpa is set to 0,
	 and academicStatus is set to "N/A".
	-----------------------------------------------------------------------*/

	/***** Getters *****/
	string getCourseCode() const;
	/*----------------------------------------------------------------------
	 Retrieves the course code data field.

	 Precondition:  None
	 Postcondition: returns the code of the course.
	-----------------------------------------------------------------------*/

	string getCourseTitle() const;
	/*----------------------------------------------------------------------
	 Retrieves the course title data field.

	 Precondition:  None
	 Postcondition: returns the title of the course.
	-----------------------------------------------------------------------*/

	int getNbOfCredits() const;
	/*----------------------------------------------------------------------
	 Retrieves the number of credits data field.

	 Precondition:  None
	 Postcondition: returns the number of credits of the course.
	-----------------------------------------------------------------------*/

	int getNbOfEnrolled() const;
	/*----------------------------------------------------------------------
	 Retrieves the unmber of enrolled data field.

	 Precondition:  None
	 Postcondition: returns the number of enrolled stuednts in the course.
	-----------------------------------------------------------------------*/

	int getCapacity() const;
	/*----------------------------------------------------------------------
	 Retrieves the capacity data field.

	 Precondition:  None
	 Postcondition: returns the maximum capacity of the course.
	-----------------------------------------------------------------------*/

	/***** Setters *****/
	void setCourseCode(const string);
	/*----------------------------------------------------------------------
	 Sets the course code data field.

	 Precondition:  none
	 Postcondition: sets the course code to the given parameter.
	-----------------------------------------------------------------------*/

	void setCourseTitle(const string);
	/*----------------------------------------------------------------------
	 Sets the course code title field.

	 Precondition:  none
	 Postcondition: sets the course title to the given parameter.
	-----------------------------------------------------------------------*/

	void setNbOfCredits(const int);
	/*----------------------------------------------------------------------
	 Sets the course number of credits data field.

	 Precondition:  nbOfCredits > 0
	 Postcondition: sets the course number of credits to the given parameter.
	-----------------------------------------------------------------------*/

	void setCapacity(const int);
	/*----------------------------------------------------------------------
	 Sets the course capacity data field.

	 Precondition:  capacity > 0
	 Postcondition: sets the course maximum capacity to the given parameter.
	-----------------------------------------------------------------------*/

	void setCourse(const string, const string, const int, const int);
	/*----------------------------------------------------------------------
	 Sets the Course object.

	 Precondition: nbOfCredits > 0 and capacity > 0
	 Postcondition: sets the Student data fields to the respective parameters.
	-----------------------------------------------------------------------*/

	/***** Utility functions *****/
	void incrementEnrolled();
	/*----------------------------------------------------------------------
	 Increments the number of enrolled students.

	 Precondition: none.
	 Postcondition: the number of enrolled students has increased by 1.
	-----------------------------------------------------------------------*/

	void decrementEnrolled();
	/*----------------------------------------------------------------------
	 Decrements the number of enrolled students.

	 Precondition: nbOfEnrolled > 0.
	 Postcondition: the number of enrolled students has decreased by 1.
	-----------------------------------------------------------------------*/

	void display() const;
	/*-----------------------------------------------------------------------
	 Display course information

	 Precondition:  ostream out is open.
	 Postcondition: detailed info about the course has been output to out.
	-----------------------------------------------------------------------*/

	string simpleDisplay() const;
	/*-----------------------------------------------------------------------
	 Display course information

	 Precondition:  none.
	 Postcondition: returns a string with the format: "courseCode - courseTitle".
	-----------------------------------------------------------------------*/

private:
	/***** Data Fields *****/
	string courseCode;	// Course code
	string courseTitle; // Course title
	int nbOfCredits;	// Number of credits of the course
	int nbOfEnrolled;	// Number of enrolled students in the course
	int capacity;		// Maximum student capacity of the course
};

/***** Non-member functions *****/
//--- Declaration of overloaded output operator
ostream &operator<<(ostream &, const Course &);

#endif //--- End of class declaration
