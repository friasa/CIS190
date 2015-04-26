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
#include "de_alg.hpp"
#include "obs.hpp"
#include <list>
#include <iostream>

using namespace std;

list<Student*> deferred_acceptance(list<Student*> students,
				   list<Course*> courses) {
  // optimal matching to return
  list<Student*> temp;
  Course *fav;
  Student *stud;
  // first iteration 
  for (auto it = students.begin(); it != students.end(); ++it){
    fav = (*it)->getPreferences().front();
    if (fav->getNumStuds() < fav->getCapacity()){
      (*it)->addCourse(fav);
      (fav)->addStudent(*it); // needs to add student into list according to GPA
    } else if ((*it)->getGPA() > fav->getLastStud()->getGPA()){
      fav->removeStud(); // should return removed student
      (*it)->addCourse(fav);
      fav->addStudent(*it); // ditto ^^^^
    }
    (*it)->removePref(); // removes the first preference
  }
  for (auto it = students.begin(); it != students.end(); ++it){
    if ((*it)->getCourses().size() == 5) (*it)->is_full = true;
    else (*it)->is_full = false;
    if ((*it)->getPreferences().empty()) (*it)->is_full = true;
    if (!(*it)->is_full){
      temp.push_front(*it);
    }
  }
  // here we go
  while (temp.size() > 0){
    for (auto it = temp.begin(); it != temp.end(); ++it){
      fav = (*it)->getPreferences().front();
      if (fav->getNumStuds() < fav->getCapacity()){
	(*it)->addCourse(fav);
	(fav)->addStudent(*it);
	if ((*it)->getCourses().size() == 5) (*it)->is_full = true;
      } else if ((*it)->getGPA() > fav->getLastStud()->getGPA()){
	stud = fav->removeStud();
	stud->removeCourses(fav);
	stud->is_full = false;
	fav->addStudent(*it);
	(*it)->addCourse(fav);
	if ((*it)->getCourses().size() == 5) (*it)->is_full = true;
      }
      (*it)->removePref();
      if ((*it)->getPreferences().empty()) (*it)->is_full = true;
      if ((*it)->is_full) temp.remove(*it);
    }
  }
  return students;
}
