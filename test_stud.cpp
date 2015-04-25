#include <list>
#include <iostream>
#include "obs.hpp"
using namespace std;

int main(int argc, const char* argv[]){
  Course *c1 = new Course("CIS110", 100);
  Course *c2 = new Course("CIS120", 100);
  Course *c3 = new Course("CIS130", 100);
  Course *c4 = new Course("CIS140", 100);
  Course *c5 = new Course("CIS150", 100);
  Course *c6 = new Course("CIS160", 100);
  Course *c7 = new Course("CIS170", 100);
  list<Course*> a_pref;
  list<Course*> b_pref;
  list<Course*> c_pref;
  a_pref.push_front(c3);
  a_pref.push_front(c2);
  a_pref.push_front(c1);
  b_pref.push_front(c5);
  b_pref.push_front(c4);
  b_pref.push_front(c3);
  c_pref.push_front(c7);
  c_pref.push_front(c6);
  Student *alex = new Student("Alex", a_pref, 0, 4.00);
  Student *bob = new Student("Bob", b_pref, 0, 3.73);
  Student *carl = new Student("Carl", c_pref, 0, 3.33);
  list<Student*> full_s;
  full_s.push_front(alex);
  full_s.push_front(bob);
  full_s.push_front(carl);
  Student *david = new Student("David", a_pref, 0, 3.89);


  // let the tests begin
  cout << c1->getName() << "\n"; // CIS110
  c1->setName("NEW NAME");
  cout << c1->getName() << "\n"; // NEW NAME
  cout << c1->getCapacity() << "\n"; // 100
  c1->setCapacity(123);
  c2->setCapacity(190);
  cout << c1->getCapacity() << "\n"; // 123
  c1->setStudents(full_s); 
  cout << c1->getStudents().front()->getName() << "\n"; // Carl
  cout << c1->getStudents().back()->getName() << "\n"; // Alex
  //addStudent needs to be tested, not ready yet
  cout << c1->getNumStuds() << "\n"; // 3
  cout << c1->getLastStud()->getName() << "\n"; // Alex
  cout << c1->removeStud()->getName() << "\n"; // Alex
  cout << c1->getNumStuds() << "\n"; // 2
  c2->addStudent(david);
  c2->addStudent(bob);
  c2->addStudent(alex);
  c2->addStudent(carl);
  cout << c2->removeStud()->getName() << "\n"; // Carl
  cout << c2->removeStud()->getName() << "\n"; // Bob
  cout << c2->removeStud()->getName() << "\n"; // David
  cout << c2->removeStud()->getName() << "\n"; // Alex



  // test student
  alex->setName("ALEX2");
  cout << alex->getName() << "\n"; // ALEX2
  alex->setPreferences(c_pref);
  cout << alex->getPreferences().front()->getName() << "\n"; // CIS160
  alex->setCourses(a_pref);
  cout << alex->getCourses().front()->getNumStuds() << "\n"; // 123
  alex->setCredits(8);
  cout << alex->getCredits() << "\n"; // 8
  alex->addCourse(c7);
  cout << alex->getCourses().front()->getName() << "\n"; // CIS 170
  alex->removeCourses(c7);
  cout << alex->getCourses().front()->getName()<< "\n"; // NEW NAME
  alex->setGPA(3.99);
  cout << alex->getGPA() << "\n"; // 3.99
  cout << alex->removePref()->getName() << "\n"; // CIS160 

  return 0;
}
