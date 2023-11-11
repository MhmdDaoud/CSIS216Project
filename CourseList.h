/* CourseList.h ------------------------------------------------------------
   Header file for a child class CourseList that encapsulates the utility
   functions common to all course lists.
   Operations are:
    drop:                   Remove a Course object from the list
    specific search: 		Retrieve the index or const reference of a specific object
    contains:               Check if a Course exists in the list or not
--------------------------------------------------------------------------*/
#ifndef CourseList_H
#define CourseList_H

#include "LinkedListWithDummy.h"
#include "Course.h"

class CourseList : public LinkedListWithDummy<Course>
{
public:
    /******** Function Members ********/
    bool dropByCourseId(const string &);
    /*----------------------------------------------------------------------
     Delete a Course with a specific code from the list.

     Precondition: none.
     Postcondition: Returns true if the Course with the desired courseCode was
     deleted sucessfully, false otherwise.
    -----------------------------------------------------------------------*/

    bool containsCourse(const string &) const;
    /*----------------------------------------------------------------------
	 Check if a Course with a specific code exists in the list

	 Precondition: none.
	 Postcondition: Returns true if the Course with the desired courseCode 
     exists in the list, false otherwise.
	-----------------------------------------------------------------------*/

    int searchByCourseId(const string &) const;
    /*----------------------------------------------------------------------
	 Search for a Course with a specific code in the list.

	 Precondition: none.
	 Postcondition: Returns the index of the desired course if found,
     -1 otherwise.
	-----------------------------------------------------------------------*/

    Course &retrieveCourse(const string &);
    /*----------------------------------------------------------------------
	 Retrieve a Course object from the list.

	 Precondition: none.
	 Postcondition: Returns a const reference to a Course object if found, 
     throws runtime_error exception otherwise.
	-----------------------------------------------------------------------*/
};

#endif //--- End of class declaration
