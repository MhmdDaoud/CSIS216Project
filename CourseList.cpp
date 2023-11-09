#include "CourseList.h"

bool CourseList::dropByCourseId(const string &courseID)
{
    if (!isEmpty())
    {
        int coursePos = searchByCourseId(courseID);
        if (coursePos != -1)
        {
            return removeAtPosition(coursePos);
        }
    }
    return false;
}

bool CourseList::containsCourse(const string &courseID) const
{
    if (!isEmpty())
    {
        int coursePos = searchByCourseId(courseID);
        return coursePos != -1;
    }
    return false;
}
int CourseList::searchByCourseId(const string &courseID) const
{
    if (!isEmpty())
    {
        int counter = 0;
        while (counter < mySize)
        {
            Course currCourse = getDataAtPosition(counter);
            if (currCourse.getCourseCode() == courseID)
            {
                return counter;
            }
            counter++;
        }
    }
    return -1;
}