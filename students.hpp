/*
 * Student class
 * Authors: Alex Frias and Alex Peckman
 * Description: The class encompasses the student, his prefernces, and blah
 */

#pragma once
#include <string>
#include <list>
#include "courses.hpp"

using namespace std;

class Student {
private:
  string name;
  list<Course> prefs;
  list<Course> courses;
  unsigned int credits;
public:
  void setPreferences(list<Course> _courses);
  list<Course> getPreferences();
  void setName(string _name);
  string getName();
  void setCourses(list<Course> _courses);
  list<Course> getCourses();
  void removeCourses(Course _course);
  void setCredits(unsinged int _credits);
  unsigned int getCredits();
  void addCourse(Course _course);
  Student(string _name, list<Course> _prefs, unsigned int _credits);
};


