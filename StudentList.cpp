#include "StudentList.h"
int StudentList::searchById(const string& studentID)const{
    if(!isEmpty()){
        for(int i = 0; i < mySize; i++){
            Student currStd = getDataAtPosition(i);
            if(currStd.getStudentId() == studentID){
                return i;
            }
        }
    }
    return -1;
}

CourseList StudentList::getRegCoursesForStud(const string& studentID)const{
    if(!isEmpty()){
        int studPos = searchById(studentID);
        if(studPos != -1){
            Student s = getDataAtPosition(studPos);
            return s.getRegisteredCourses();
        }
    }
    CourseList g;
    return g;
}

StudentList StudentList::getStudRegInCourse(const string& courseID)const{
    if(!isEmpty()){
        StudentList students;
        for(int i = 0; i < mySize; i++){
            Student currStd = getDataAtPosition(i);
            CourseList currStdRegCourses = currStd.getRegisteredCourses();
            if((currStdRegCourses).containsCourse(courseID)){
                students.insertAtEnd(currStd);
            }
        }
        return students;
    }
    StudentList g;
    return g;
}

bool StudentList::removeById(const string& studentID){
    if(!isEmpty()){
        int studPos = searchById(studentID);
        if(studPos != -1){
            return removeAtPosition(studPos);
        }
    }
    return false;
}