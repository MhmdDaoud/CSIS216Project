#ifndef CourseList_H
#define CourseList_H

#include "LinkedListWithDummy.h"
#include "Course.h"

class CourseList :public LinkedListWithDummy<Course>
{
    public:
        bool dropByCourseId(const string &courseID);
        bool containsCourse(const string &courseID) const;
        int searchByCourseId(const string &courseID) const;
        Course retrieveCourse(const string &courseCode);
};
#endif