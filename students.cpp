/*
 * Students class
 * Authors: Alex Frias and Alex Peckman
 * 
 */

#include "students.hpp"
#include "courses.hpp"

using namespace std;

Student::Student(string _name, list<Course> _course) {
  name = _name;
  prefs = _course;
}

void Student::setPreferences(list<Course> _courses){
  prefs = _courses;
}

list<Course> Student::getPreferences(){
  return prefs;
}

void Student::setName(string _name){
  name = _name;
}

string Student::getName(){
  return name;
}

void Student::setCourses(list<Course> _courses){
  courses = _courses;
}

list<Courses> Student::getCourses(){
  return courses;
}
