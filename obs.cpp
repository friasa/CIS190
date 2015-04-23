#pragma once
#include "obs.hpp"
#include <list>
#include <string>

using namespace std;

Student::Student(string _name, list<Course*> _prefs, unsigned int _credits) {
  name = _name;
  prefs = _prefs;
  credits = _credits;
}

Student::Student(){
  list<Course*> _prefs;
  name = "";
  prefs = _prefs;
  credits = 0;
}

void Student::setPreferences(list<Course*> _courses){
  prefs = _courses;
}

list<Course*> Student::getPreferences(){
  return prefs;
}

void Student::setName(string _name){
  name = _name;
}

string Student::getName(){
  return name;
}

void Student::setCourses(list<Course*> _courses){
  courses = _courses;
}

list<Course*> Student::getCourses(){
  return courses;
}

void Student::removeCourses(Course *_courses){
  courses.remove(_courses);
}

void Student::setCredits(unsigned int _credits){
  credits = _credits;
}

unsigned int Student::getCredits(){
  return credits;
}

void Student::addCourse(Course *_course){
  courses.push_front(_course);
}

Course::Course(string course_name, int capacity) {
  name = course_name;
  this->capacity = capacity;
}

Course::Course(){
  name = "";
  capacity = 0;
}

string Course::getName() {
  return name;
}

void Course::setName(string course_name) {
  name = course_name;
}

void Course::setCapacity(int capacity) {
  this->capacity = capacity;
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
