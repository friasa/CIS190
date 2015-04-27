/* 
 * main executable file
 * 
 */

#include "obs.hpp"
#include "de_alg.hpp"
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <list>

using namespace std;

int main(int argc, const char* argv[]){

  // check usage
  if (argc != 3){
    cout << "Usage: ./main [student file] [course file]\n"; 
    exit(-1);
  }

  list<Course*> course_register;
  list<Student*> all_students;
  
  // parse input
  string s_file_name, c_file_name;
  ifstream s_file, c_file;
  s_file_name = argv[1];
  c_file_name = argv[2];

  // parse c_file
  c_file.open(c_file_name);
  int capacity;
  int i;
  string cap_str;
  char* c = new char[1];
  string course_name;
  Course* temp_course;
  while (!c_file.eof()) {
    // read in the file and make course
    course_name = "";
    // get course name
    while(true) {
      c_file.read(c, 1);
      if (strcmp(c, ":") == 0) {
	break;
      }
      course_name.append(c);
    }
    // get capacity
    i = 0;
    cap_str = "";
    c_file.read(c, 1); // skip over the space
    while (true) {
      c_file.read(c, 1);
      if (strcmp(c, ";") == 0) {
	break;
      }
      cap_str.append(c);
      i++;
    }
    capacity = stoi(cap_str);

    temp_course = new Course(course_name, capacity);
    course_register.push_front(temp_course);

    // read chars until get to the beginning of next course
    while (true) {
      c_file.read(c, 1);
      if (strcmp(c, "\n") == 0) {
	break;
      }
      else if (strcmp(c, "#") == 0) {
	goto C_FILE_DONE;
      }
    }
    
  }

 C_FILE_DONE:
  c_file.close();
  
  // parse s_file
  list<Course*> course_prefs;
  list<string> course_names;
  s_file.open(s_file_name);
  string student_name = "";
  string course = "";
  Student* temp;
  float gpa;
  i = 0;
  string gpa_str;
  while (s_file.good()) {
    // read in the file and make students
    student_name = "";
    course_names.clear();
    course_prefs.clear();
    // get student name
    while(true) {
      s_file.read(c, 1);
      if (strcmp(c, ":") == 0) {
	break;
      }
      student_name.append(c);
    }
    // get gpa
    i = 0;
    gpa_str = "";
    s_file.read(c, 1); // read the space
    while (true) {
      s_file.read(c, 1);
      if (strcmp(c, ",") == 0) {
	break;
      }
      gpa_str.append(c);
      i++;
    }
    gpa = stof(gpa_str);
    // get student's preferences
    while (true) {
      s_file.read(c, 1);
      if (strcmp(c, "{") == 0) {
        break;
      }
    }
    
    while (true) {
      s_file.read(c, 1);
      if (strcmp(c, "}") == 0) {
	course_names.push_front(course);
	course = "";
        break;
      }
      if (strcmp(c, " ") == 0) {
	course_names.push_front(course);
	course = "";
	continue;
      }
      course.append(c);
    }
    
    // make a list of courses from the list of strings
    for (auto it1 = course_names.begin(); it1 != course_names.end(); ++it1) {
      for (auto it2 = course_register.begin(); it2 != course_register.end(); ++it2) {
	if (((*it2)->getName()).compare(*it1) == 0) {
	  course_prefs.push_front(*it2);
	}
      }
    }
    
    // make a new student by passing in name, gpa, course list
    temp = new Student(student_name, course_prefs, 0, gpa);
    all_students.push_front(temp);
    // read chars until get to the beginning of next student
    while (true) {
      s_file.read(c, 1);
      if (strcmp(c, "\n") == 0) {
	break;
      }
      else if (strcmp(c, "#") == 0) {
	goto S_FILE_DONE;
      }
    }
    
  }

 S_FILE_DONE:
  s_file.close();
  
  // run matching algorithm
  deferred_acceptance(all_students, course_register);
  
  // print out the students and courses
  for (auto it = all_students.begin(); it != all_students.end(); ++it){
    cout << (*it)->getName() << ":  {";
    while (!(*it)->getCourses().empty()){
      if ((*it)->getCourses().size() == 1) 
	cout << (*it)->getCourses().front()->getName() << "}";
      else cout << (*it)->getCourses().front()->getName() << ", ";
      (*it)->removeCourses((*it)->getCourses().front());
    }
    cout << "\n";
  }

  for (auto it = all_students.begin(); it != all_students.end(); ++it){
    delete *it;
  }
  for (auto it = course_register.begin(); it != course_register.end(); ++it){
    delete *it;
  }

  delete c;

  return 0;
}
