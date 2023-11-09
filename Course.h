#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
class Course
{
public:
	void Init(const string, const string, const int, const int);

	string getCourseCode() const;
	string getCourseTitle() const;
	int getNbOfCredits() const;
	int getNbOfEnrolled() const;
	int getCapacity() const;

	void setCourseCode(const string);
	void setCourseTitle(const string);
	void setNbOfCredits(const int);
	void setCapacity(const int);
	void setCourse(const string, const string, const int, const int);

	void display() const;
    void simpleDisplay() const;

private:
	string courseCode;
	string courseTitle;
	int nbOfCredits;
	int nbOfEnrolled;
	int capacity;
};

ostream &operator<<(ostream &, const Course &);

#endif