/*
===============================================================================

Description:
This C++ program implements a simple Student Registration System. It utilizes
file I/O to read student and course data from external files, allowing users
to perform various operations, such as displaying lists of students and courses,
registering students for courses, and managing course enrollments.

Usage:
1. Compile and run the program.
2. Choose from the menu options to perform specific tasks related to student
   registration and course management.
3. The program reads initial data from "Students.txt" and "Courses.txt" files.
   Modify these files to update student and course information.

Authors: Elias Matar, Mohamad Daoud, Hadi Skaf, Jason Jamous.
Date: 11 - 11 - 2023
===============================================================================
*/

#include <fstream>
#include <cctype>
#include "StudentList.h"
#include "CourseList.h"
using namespace std;

/***** Utility functions *****/
string toUppercase(string str)
/*----------------------------------------------------------------------
 Transform a string into uppercase.

 Precondition:  None
 Postcondition: returns an uppercase string, numbers and
 special characters are unchanged.
-----------------------------------------------------------------------*/
{
	for (int i = 0; i < str.length(); ++i)
	{
		str[i] = toupper(str[i]);
	}
	return str;
}

void menu()
/*----------------------------------------------------------------------
 Display the main menu of the application.

 Precondition:  None
 Postcondition: the main menu is displayed on screen.
-----------------------------------------------------------------------*/
{
	cout << "1. Display the list of non-registered students." << endl
		 << "2. Display the list of offered courses." << endl
		 << "3. Display the list of registered students with the registered courses." << endl
		 << "4. Display the list of offered courses with the registered students." << endl
		 << "5. Display the registered courses for a student." << endl
		 << "6. Display the list of students registered in a course" << endl
		 << "7. Display the information related to a specific student." << endl
		 << "8. Register a student." << endl
		 << "9. Choose a student to add/drop a course for him/her." << endl
		 << "10. Quit the application." << endl
		 << endl
		 << "Enter your choice:";
}

/***** Application entry point *****/
int main()
{
	//--- Reading data from Students.txt
	ifstream studentsFile("Students.txt");

	if (!studentsFile.is_open())
	{
		cerr << "Unable to open file: Students.txt";
		return 1;
	}

	int nbOfStudents;
	studentsFile >> nbOfStudents;
	studentsFile.ignore(1024, '\n'); //--- Ignore remaining characters in the line

	StudentList nonRegisteredStudents;
	for (int stdCounter = 0; stdCounter < nbOfStudents; ++stdCounter)
	{
		Student s;
		string id, firstName, lastName, major;
		float gpa;
		studentsFile >> id >> firstName >> lastName >> gpa;
		studentsFile.ignore();
		getline(studentsFile, major);
		
		s.Init(id, firstName, lastName, major, gpa);
		nonRegisteredStudents.insertAtEnd(s);
	}
	studentsFile.close();

	//--- Reading data from Courses.txt
	ifstream coursesFile("Courses.txt");

	if (!coursesFile.is_open())
	{
		cerr << "Unable to open file: Courses.txt";
		return 1;
	}

	int nbOfCourses;
	coursesFile >> nbOfCourses;
	coursesFile.ignore(1024, '\n'); //--- Ignore remaining characters in the line

	CourseList offeredCourses;
	for (int cCounter = 0; cCounter < nbOfCourses; ++cCounter)
	{
		Course c;
		string code, title, line;
		int nbOfCredits, capacity;

		coursesFile >> code;
		coursesFile.ignore();

		while (!isdigit(coursesFile.peek())) //--- Checking if the next character is a number
		{
			title += coursesFile.get(); //--- Add characters to title if it's not a number
		}

		coursesFile >> nbOfCredits >> capacity; //--- Read the rest of the data
		c.Init(code, title, nbOfCredits, capacity);
		offeredCourses.insertAtEnd(c);
	}
	coursesFile.close();

	StudentList registeredStudents;

	int userChoice;
	do
	{
		menu();

		cin >> userChoice;
		cout << endl;
		if (cin.fail())
		{
			cout << "Invalid input" << endl;
			cin.clear();			//--- Clear the fail state
			cin.ignore(1024, '\n'); //--- Discard invalid input
			continue;
		}
		switch (userChoice)
		{
		case 1:
			//--- Displaying non-registered students
			cout << left << "Students that didn't register yet." << endl
				 << setw(15) << "ID"
				 << setw(20) << "Name"
				 << setw(8) << "GPA"
				 << setw(15) << "Academic Status" << endl
				 << nonRegisteredStudents;
			break;

		case 2:
			//--- Displaying all offered courses
			cout << left << setw(15) << "Course"
				 << setw(35) << "Title"
				 << setw(15) << "# Credits"
				 << setw(15) << "Enrolled"
				 << setw(15) << "Capacity" << endl
				 << offeredCourses;
			break;

		case 3:
			//--- Displaying registered students with the registered courses
			if (registeredStudents.size() == 0)
			{
				cout << "No Registered Students" << endl;
				break;
			}
			for (int i = 0; i < registeredStudents.size(); ++i)
			{
				Student &currentStudent = registeredStudents.getDataAtPosition(i);
				string currentID = currentStudent.getStudentId();
				cout << "Student:" << currentStudent.simpleDisplay() << endl; // "ID - lastName, firstName"
				CourseList &regCourses = registeredStudents.getRegCoursesForStud(currentID);
				if (regCourses.size() > 0)
				{
					for (int j = 0; j < regCourses.size(); ++j)
					{
						Course &currentCourse = regCourses.getDataAtPosition(j);
						cout << '-' << currentCourse.simpleDisplay() << endl; // "courseCode - courseTitle"
					}
				}
				else
				{
					cout << "No registered courses" << endl;
				}
			}
			break;

		case 4:
			//--- Displaying offered courses with the registered students
			for (int i = 0; i < offeredCourses.size(); ++i)
			{
				try
				{
					Course &currentCourse = offeredCourses.getDataAtPosition(i);
					string currentCode = currentCourse.getCourseCode();
					cout << "Course:" << currentCourse.simpleDisplay() << endl; // "courseCode - courseTitle"
					StudentList regStudentsInCourse = registeredStudents.getStudRegInCourse(currentCode);

					if (regStudentsInCourse.size() == 0)
					{
						cout << "No Registered Students" << endl;
					}
					else
					{
						for (int j = 0; j < regStudentsInCourse.size(); ++j)
						{
							cout << regStudentsInCourse.getDataAtPosition(j).simpleDisplay() << endl; // "ID - lastName, firstName"
						}
					}
				}
				catch (const runtime_error &re)
				{
					cerr << "No Registered Students" << endl;
				}
				cout << endl;
			}
			break;

		case 5:
		{
			//--- Displaying registered courses for a student
			string studentId;

			cout << "Enter student ID:";
			cin >> studentId;

			string fStudentId = toUppercase(studentId);

			try
			{
				Student &currentStudent = registeredStudents.retrieveStudent(fStudentId);
				cout << "Student: " << currentStudent.simpleDisplay() << endl
					 << endl; // "ID - lastName, firstName"
				cout << "Courses: " << endl
					 << endl;
				CourseList &regCourses = registeredStudents.getRegCoursesForStud(fStudentId);

				for (int i = 0; i < regCourses.size(); i++)
				{
					cout << "- " << regCourses.getDataAtPosition(i).getCourseCode() << endl;
				}
			}
			catch (const runtime_error &re)
			{
				cerr << re.what() << endl;
			}
			break;
		}

		case 6:
		{
			//--- Displaying students in a registered course
			string courseCode;
			cout << "Enter the course code:";
			cin >> courseCode;
			string fCourseCode = toUppercase(courseCode);
			cout << endl;
			try
			{
				Course &currentCourse = offeredCourses.retrieveCourse(fCourseCode);
				cout << "Course:" << currentCourse.simpleDisplay() << endl
					 << endl; // "courseCode - courseTitle"
				StudentList regStd = registeredStudents.getStudRegInCourse(fCourseCode);

				for (int i = 0; i < regStd.size(); ++i)
				{
					cout << regStd.getDataAtPosition(i).simpleDisplay() << endl; // "ID - lastName, firstName"
				}
			}
			catch (const runtime_error &re)
			{
				cerr << re.what() << endl;
			}
			break;
		}

		case 7:
		{
			//--- Displaying student information
			string studentId;
			cout << "Enter the student ID:";
			cin >> studentId;
			cout << endl;

			string fStudentId = toUppercase(studentId);
			try
			{
				Student &currentStudent = registeredStudents.retrieveStudent(fStudentId);
				if (!currentStudent.getStudentId().empty())
				{
					cout << "Student:" << endl
						 << "\tID: " << currentStudent.getStudentId() << endl
						 << "\tName: " << currentStudent.getStudentName() << endl
						 << "\tMajor: " << currentStudent.getStudentMajor() << endl
						 << "\tGPA: " << currentStudent.getStudentGpa() << endl;
				}
			}
			catch (const runtime_error &e)
			{
				try
				{
					Student &currentStudent = nonRegisteredStudents.retrieveStudent(fStudentId);
					if (!currentStudent.getStudentId().empty())
					{
						cout << "Student:" << endl
							 << "\tID: " << currentStudent.getStudentId() << endl
							 << "\tName: " << currentStudent.getStudentName() << endl
							 << "\tMajor: " << currentStudent.getStudentMajor() << endl
							 << "\tGPA: " << currentStudent.getStudentGpa() << endl;
					}
				}
				catch (const runtime_error &err)
				{
					cerr << e.what() << endl;
				}
			}
			break;
		}

		case 8:
		{
			//--- Registering a student
			char userChar;
			string studentId;
			cout << "Enter the student ID:";
			cin >> studentId;

			string fStudentId = toUppercase(studentId);

			if (nonRegisteredStudents.searchById(toUppercase(fStudentId)) == -1)
			{
				cerr << "Student not found" << endl;
				break;
			}

			Student retrievedStudent = nonRegisteredStudents.retrieveStudent(fStudentId);
			try
			{
				do
				{
					string courseCode;
					cout << "Enter Course Code:";
					cin >> courseCode;
					string fCourseCode = toUppercase(courseCode);

					if (offeredCourses.searchByCourseId(fCourseCode) == -1)
					{
						cout << "Course is not offered." << endl;
						break;
					}
					Course &retrievedCourse = offeredCourses.retrieveCourse(fCourseCode);
					if (retrievedCourse.getNbOfEnrolled() == retrievedCourse.getCapacity())
					{
						cout << "Course is full." << endl;
						break;
					}
					if (retrievedStudent.getRegisteredCourses().containsCourse(fCourseCode))
					{
						cout << "Course already registered." << endl;
						break;
					}

					retrievedStudent.getRegisteredCourses().insertAtEnd(retrievedCourse);
					retrievedCourse.incrementEnrolled();
					cout << "Course added successfully." << endl;
					cout << "Do you need to add more courses [Y] yes or [N] no:";
					cin >> userChar;
					if (toupper(userChar) != 'Y' && toupper(userChar) != 'N')
					{
						cout << "Invalid input" << endl;
						continue;
					}

				} while (toupper(userChar) == 'Y');
			}
			catch (const runtime_error &re)
			{
				cerr << re.what() << endl;
			}
			nonRegisteredStudents.removeById(retrievedStudent.getStudentId());
			registeredStudents.insertAtEnd(retrievedStudent);

			break;
		}

		case 9:
		{
			//--- Choose a student to add/drop course
			string studentId, courseCode;
			cout << "Enter the student ID:";
			cin >> studentId;
			string fStudentId = toUppercase(studentId);
			try
			{
				Student &currentStd = registeredStudents.retrieveStudent(fStudentId);
				CourseList &studentCourses = currentStd.getRegisteredCourses();
				cout << "Courses:" << endl;
				for (int i = 0; i < studentCourses.size(); ++i)
				{
					cout << studentCourses.getDataAtPosition(i).simpleDisplay() << endl;
				}

				char userChar;
				do
				{
					cout << endl
						 << "Add course [A] or Drop course [D]:";
					cin >> userChar;

					cout << "Enter the course code:";
					cin >> courseCode;
					string fCourseCode = toUppercase(courseCode);

					Course &currentCourse = offeredCourses.retrieveCourse(fCourseCode);
					if (!offeredCourses.containsCourse(currentCourse.getCourseCode()))
					{
						cout << "The course is not offered" << endl;
						break;
					}
					int courseIndex = studentCourses.searchByCourseId(fCourseCode);

					switch (toupper(userChar))
					{
					case 'A': // Add
						if (studentCourses.containsCourse(fCourseCode))
						{
							cout << "Course already registered.";
							break;
						}

						if (currentCourse.getNbOfEnrolled() == currentCourse.getCapacity())
						{
							cout << "Course is full." << endl;
							break;
						}

						studentCourses.insertAtEnd(currentCourse);
						currentCourse.incrementEnrolled();
						cout << "Course added successfully" << endl;
						break;

					case 'D': // Drop
						if (studentCourses.containsCourse(fCourseCode))
						{
							studentCourses.removeAtPosition(courseIndex);
							currentCourse.decrementEnrolled();
							cout << "Course dropped successfully" << endl;
							break;
						}
						else
						{
							cout << "Course not registered." << endl;
							break;
						}

					default:
						cout << "Invalid input" << endl;
						break;
					}

					cout << "Do you want to continue [Y] yes or [N] no:";
					cin >> userChar;

				} while (toupper(userChar) != 'N');
			}
			catch (const runtime_error &e)
			{
				cout << e.what() << endl;
			}
			break;
		}

		case 10:
			cout << "Exiting application..." << endl;
			break;

		default:
			cout << "Invalid input" << endl;
		}
		cout << endl;
	} while (userChoice != 10);
	return 0;
}
