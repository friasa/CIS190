// defines the courses class

#pragma once

#include <string>
#include <list>
#include "students.hpp"

using namespace std;

class Course {

private:
  string name;
  int capacity;
  list<Student*> students;

public:
  void getName();
  string setName(string course_name);
  void setCapacity(int capacity);
  int getCapacity();
  void setStudents(list<Student*> student_list);
  void addStudent(Student* student_ptr);
  list<Student*> getStudents();
  Course(string course_name, int capacity);

};
