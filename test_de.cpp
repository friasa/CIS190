#include <list>
#include <iostream>
#include "obs.hpp"
#include "de_alg.hpp"
using namespace std;

int main(int argc, const char* argv[]){
  Course *c1  = new Course("CIS110", 100);
  Course *c2  = new Course("CIS120", 100);
  Course *c3  = new Course("CIS130", 100);
  Course *c4  = new Course("CIS140", 100);
  Course *c5  = new Course("CIS150", 100);
  Course *c6  = new Course("CIS160", 100);
  Course *c7  = new Course("CIS170", 100);
  Course *c8  = new Course("CIS180", 100);
  Course *c9  = new Course("CIS190", 100);
  Course *c10 = new Course("CIS200", 100);
  Course *c11 = new Course("CIS210", 100);
  Course *c12 = new Course("CIS220", 100);
  Course *c13 = new Course("CIS230", 100);
  Course *c14 = new Course("CIS240", 100);
  Course *c15 = new Course("CIS2500", 100);
  list<Course*> a_pref;
  list<Course*> b_pref;
  list<Course*> c_pref;
  list<Course*> d_pref;
  //
  a_pref.push_front(c5);
  a_pref.push_front(c4);
  a_pref.push_front(c3);
  a_pref.push_front(c2);
  a_pref.push_front(c1);
  //
  b_pref.push_front(c7);
  b_pref.push_front(c6);
  b_pref.push_front(c5);
  b_pref.push_front(c4);
  b_pref.push_front(c3);
  //
  c_pref.push_front(c7);
  c_pref.push_front(c6);
  c_pref.push_front(c8);
  c_pref.push_front(c9);
  c_pref.push_front(c10);
  //
  d_pref.push_front(c11);
  d_pref.push_front(c12);
  d_pref.push_front(c13);
  d_pref.push_front(c14);
  d_pref.push_front(c15);
  //
  Student *alex = new Student("Alex", a_pref, 0, 4.00);
  Student *bob = new Student("Bob", b_pref, 0, 3.73);
  Student *carl = new Student("Carl", c_pref, 0, 3.33);
  Student *david = new Student("David", d_pref, 0, 3.89);
  list<Student*> full_s;
  list<Course*> full_c;
  full_s.push_back(alex);
  full_s.push_back(bob);
  full_s.push_back(carl);
  full_s.push_back(david);
  full_c.push_back(c1);
  full_c.push_back(c2);
  full_c.push_back(c3);
  full_c.push_back(c4);
  full_c.push_back(c5);
  full_c.push_back(c6);
  full_c.push_back(c7);
  full_c.push_back(c8);
  full_c.push_back(c9);
  full_c.push_back(c10);
  full_c.push_back(c11);
  full_c.push_back(c12);
  full_c.push_back(c13);
  full_c.push_back(c14);
  full_c.push_back(c15);

  cout << full_s.size() << "\n";

  // here be problems
  deferred_acceptance(full_s, full_c);
 
  cout << full_s.size() << "\n";
  
  


  cout << "print\n";
  // here be answers
  for (auto it = full_s.begin(); it != full_s.end(); ++it){
    cout << (*it)->getName() << ": ";
    for (auto it2 = (*it)->getCourses().begin(); it2 != (*it)->getCourses().end(); ++it){
      cout << (*it2)->getName() << ", ";
    }
    cout << "\n";
  }
 
  return 0;
}
