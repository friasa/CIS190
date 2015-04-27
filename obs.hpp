// defines the courses class        

#pragma once

#include <string>
#include <list>

using namespace std;

class Student;

class Course {

private:
  string name;
  int capacity;
  list<Student*> students;

public:
  string getName();
  void setName(string course_name);
  void setCapacity(int capacity);
  int getCapacity();
  void setStudents(list<Student*> student_list);
  void addStudent(Student* student_ptr); // need to update to add according to GPA
  list<Student*> getStudents();
  int getNumStuds(); // new
  Student* getLastStud(); // new
  Student* removeStud(); // new: Should remove last student
  Course(string course_name, int capacity);
  Course();
  ~Course();
};

class Student {
private:
  string name;
  list<Course*> prefs;
  list<Course*> courses;
  unsigned int credits;
  float GPA;
public:
  bool is_full;

  void setPreferences(list<Course*> _courses);
  list<Course*> getPreferences();
  void setName(string _name);
  string getName();
  void setCourses(list<Course*> _courses);
  list<Course*> getCourses();
  void removeCourses(Course *_course);
  void setCredits(unsigned int _credits);
  unsigned int getCredits();
  void addCourse(Course *_course);
  float getGPA(); // new
  Course* removePref(); // new: removes first preference
  void setGPA(float _GPA); // new
  Student(string _name, list<Course*> _prefs, unsigned int _credits, float _GPA); // update
  Student();
  ~Student();
};

