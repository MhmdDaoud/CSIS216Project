#include "Course.h"
using namespace std;

void Course::Init(const string courseCode = "N/A", const string courseTitle = "N/A",
                  const int nbOfCredits = 3, const int capacity = 10)
{
    setCourse(courseCode, courseTitle, nbOfCredits, capacity);
    nbOfEnrolled = 0;
}

string Course::getCourseCode() const
{
    return courseCode;
}

string Course::getCourseTitle() const
{
    return courseTitle;
}

int Course::getNbOfCredits() const
{
    return nbOfCredits;
}

int Course::getNbOfEnrolled() const
{
    return nbOfEnrolled;
}

int Course::getCapacity() const
{
    return capacity;
}

void Course::setCourseCode(const string courseCode)
{
    // TODO Check if characters are uppercase
    this->courseCode = courseCode;
}

void Course::setCourseTitle(const string courseTitle)
{
    this->courseTitle = courseTitle;
}

void Course::setNbOfCredits(const int nbOfCredits)
{
    if (nbOfCredits > 0)
    {
        this->nbOfCredits = nbOfCredits;
    }
}

void Course::setCapacity(const int capacity)
{
    if (capacity > 0)
    {
        this->capacity = capacity;
    }
}

void Course::setCourse(const string courseCode, const string courseTitle,
                       const int nbOfCredits, const int capacity)
{
    setCourseCode(courseCode);
    setCourseTitle(courseTitle);
    setNbOfCredits(nbOfCredits);
    setCapacity(capacity);
}

void Course::display() const
{
	cout << left << setw(15) << courseCode
	     << setw(35) << courseTitle
	     << setw(15) << nbOfCredits
	     << setw(15) << nbOfEnrolled
	     << setw(15) << capacity << endl;

}

ostream &operator<<(ostream &out, const Course &rhs)
{
    rhs.display();
    return out;
}

