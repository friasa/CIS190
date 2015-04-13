
#include "courses.hpp"
#include "students.hpp"

Course::Course(string course_name, int capacity) {
  name = course_name;
  capacity = capacity;
}

void Course::getName() {
  return name;
}

string Course::setName(string course_name) {
  name = course_name;
}

void Course::setCapacity(int capacity) {
  this.capacity = capacity;
}

int Course::getCapacity() {
  return capacity;
}

void Course::setStudents(list<Student*> student_list) {
  students = student_list;
}
void Course::addStudent(Student* student_ptr) {
  students.push_front(student_ptr);
}

list<Student*> Course::getStudents() {
  return students;
}
