#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;



int main(int argc, const char** argv) {
  ifstream file;
  file.open(argv[1]);

  // get and print the name
  string str = "";
  char* c = new char [1];
  while (1) {
    file.read(c, 1);
    if (strcmp(c, ":") == 0) {
      break;
    }
    str.append(c);
  }
  cout << str << "\n";

  // get and print the GPA
  float gpa;
  int i = 0;
  char gpa_str[10] = "";
  while (1) {
    file.read(c, 1);
    if (strcmp(c, ",") == 0) {
      break;
    }
    gpa_str[i] = *c;
    i++;
  }
  gpa = stof(gpa_str);
  cout << gpa_str << "\n"; 
  cout << "GPA = " << gpa << "\n";


  // get the course preferences
  

  

  
}
