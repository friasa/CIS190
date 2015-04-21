/* Deferred Acceptance Algorithm
 * Authors: Alex Frias and Alex Peckman
 * Description: The deferred acceptance algorithm is a matching 
 *     algorithm that takes in a two groups, x and y, and a list of 
 *     preferences from x over the other group, y. It then 
 *     computes the socially optimal stable matching for x. 
 * Dependencies:
 *     A list x 
 *     A list y
 */
#pragma once
#include "de_alg.hpp"
#include "obs.hpp"
#include <list>

using namespace std;

list<Student*> deferred_acceptance(list<Student*> students,
				   list<Course*> courses) {
  // optimal matching to return
  list<Student*> matching;
  Student *stud = new Student("Alex", courses, 0);
  // first iteration
  for (auto it = students.begin(); it != students.end(); it++){
    //students.getPreferences().front();
  }
  return matching;
}
