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

  // parse input
  string s_file_name, c_file_name;
  s_file_name = argv[1];
  c_file_name = argv[2];

  // parse files
  list<Student*> students;
  list<Course*> courses;
  ifstream s_file, c_file;
  s_file.open(s_file_name);
  while (s_file.good()){
    // read in the file and make students
  }
  s_file.close();
  c_file.open(c_file_name);
  while (c_file.good()){
    // read in the file and make course
  }
  c_file.close();

  // run matching algorithm
  students = deferred_acceptance(students, courses);
  
  // TODO: make a print method to print out the students and courses
  

  return 0;
}
