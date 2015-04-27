#include "obs.hpp"
#include <list>
#include <iterator>
#include <string>
#include <iostream>

using namespace std;

// updated
Student::Student(string _name, list<Course*> _prefs, unsigned int _credits, float _GPA) {
  name = _name;
  prefs = _prefs;
  credits = _credits;
  GPA = _GPA;
}

Student::Student(){
  list<Course*> _prefs;
  name = "";
  prefs = _prefs;
  credits = 0;
}

/*Student::~Student(){
  delete &name;
  delete &credits;
  delete &GPA;
  delete &is_full;
  for (auto it = prefs.begin(); it != prefs.end(); ++it){
    delete *it;
  }
  for (auto it = courses.begin(); it != courses.end(); ++it){
    delete *it;
  }
  }*/

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

float Student::getGPA(){ // new
  return GPA;
}

void Student::setGPA(float _GPA){ // new
  GPA = _GPA;
}

Course* Student::removePref(){ // new
  Course *temp;
  temp = prefs.front(); // need to check this
  prefs.pop_front();
  return temp;
}

Course::Course(string course_name, int capacity) {
  name = course_name;
  this->capacity = capacity;
}

Course::Course(){
  name = "";
  capacity = 0;
}

/*Course::~Course(){
  delete &name;
  delete &capacity;
  }*/

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
  // should insert according to GPA, assumes sorted list
  bool inserted = false;
  if (students.empty()) {
    students.push_front(student_ptr);
    return;
  } 
  for (auto it = students.begin(); it != students.end(); ++it){
    if ((*it)->getGPA() > student_ptr->getGPA()) continue;
    students.insert(it, student_ptr);
    inserted = true;
    break;
  }
  if (!inserted) students.push_back(student_ptr);
}

list<Student*> Course::getStudents() {
  return students;
}

int Course::getNumStuds(){ // new
  return students.size();
}

Student* Course::getLastStud(){ // new
  return students.back();
}

Student* Course::removeStud(){ // new
  Student *temp;
  temp = students.back();
  students.remove(*prev(students.end()));
  return temp;
}
