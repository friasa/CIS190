/*
 * Student class
 * Authors: Alex Frias and Alex Peckman
 * Description: The class encompasses the student, his prefernces, and blah
 */

#pragma once
#include <string>
#include <list>

using namespace std;

class Student {
private:
  string name;
  list<Course> prefs;
  list<Course> courses;
public:
  void setPreferences(list<Course> _courses);
  list<Course> getPreferences();
  void setName(string _name);
  string getName();
  void setCourses(list<Course> _courses);
  list<Course> getCourses();
  Student(string _name, list<Course> _courses);
};


