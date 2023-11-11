/*-- Course.cpp-----------------------------------------------------------
   This file implements Course member functions.
-------------------------------------------------------------------------*/
#include "Course.h"

using namespace std;

/***** Constructor *****/
//--- Definition of Init()
void Course::Init(const string courseCode = "N/A", const string courseTitle = "N/A",
				  const int nbOfCredits = 3, const int capacity = 10)
{
	setCourse(courseCode, courseTitle, nbOfCredits, capacity);
	nbOfEnrolled = 0;
}

/***** Getters *****/
//--- Definition of getCourseCode()
string Course::getCourseCode() const
{
	return courseCode;
}

//--- Definition of getCourseTitle()
string Course::getCourseTitle() const
{
	return courseTitle;
}

//--- Definition of getNbOfCredits()
int Course::getNbOfCredits() const
{
	return nbOfCredits;
}

//--- Definition of getNbOfEnrolled()
int Course::getNbOfEnrolled() const
{
	return nbOfEnrolled;
}

//--- Definition of getCapacity()
int Course::getCapacity() const
{
	return capacity;
}

/***** Setters *****/
//--- Definition of setCourseCode()
void Course::setCourseCode(const string courseCode)
{
	this->courseCode = courseCode;
}

//--- Definition of setCourseTitle()
void Course::setCourseTitle(const string courseTitle)
{
	this->courseTitle = courseTitle;
}

//--- Definition of setNbOfCredits()
void Course::setNbOfCredits(const int nbOfCredits)
{
	if (nbOfCredits > 0)
	{
		this->nbOfCredits = nbOfCredits;
	}
}

//--- Definition of setCapacity()
void Course::setCapacity(const int capacity)
{
	if (capacity > 0)
	{
		this->capacity = capacity;
	}
}

//--- Definition of setCourse()
void Course::setCourse(const string courseCode, const string courseTitle,
					   const int nbOfCredits, const int capacity)
{
	setCourseCode(courseCode);
	setCourseTitle(courseTitle);
	setNbOfCredits(nbOfCredits);
	setCapacity(capacity);
}

/***** Utility functions *****/
//--- Definition of incrementEnrolled()
void Course::incrementEnrolled()
{
	nbOfEnrolled++;
}

//--- Definition of decrementEnrolled()
void Course::decrementEnrolled()
{
	if (nbOfEnrolled > 0)
	{
		nbOfEnrolled--;
	}
}

//--- Definition of dsiplay()
void Course::display() const
{
	cout << left << setw(15) << courseCode
		 << setw(35) << courseTitle
		 << setw(15) << nbOfCredits
		 << setw(15) << nbOfEnrolled
		 << setw(15) << capacity << endl;
}

//--- Definition of simpleDisplay()
string Course::simpleDisplay() const
{
	return courseCode + " - " + courseTitle + '\n';
}

/*------------------------------------------------------------------------
	Implementation of non-member functions
-------------------------------------------------------------------------*/

//--- Definition of overloaded output operator
ostream &operator<<(ostream &out, const Course &rhs)
{
	rhs.display();
	return out;
}
