/*
 * Students class
 * Authors: Alex Frias and Alex Peckman
 * 
 */

#include "students.hpp"
#include "courses.hpp"

using namespace std;

Student::Student(string _name, list<Course> _prefs, unsigned int _credits) {
  name = _name;
  prefs = _prefs;
  credits = _credits;
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

list<Course> Student::getCourses(){
  return courses;
}

void Student::removeCourses(Course _courses){
  courses.remove(_courses);
}

void Student::setCredits(unsigned int _credits){
  credits = _credits;
}

unsigned int Student::getCredits(){
  return credits;
}

void Student::addCourse(Course _course){
  courses.add(_course);
}
