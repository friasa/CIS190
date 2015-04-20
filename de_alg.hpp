/*
 * Header File for the Deferred Acceptance Algorithm 
 * Authors: Alex Frias and Alex Peckman
 */
#pragma once
#include <list>
#include "obs.hpp"

list<Student*> deferred_acceptance(list<Student*> students, 
				   list<Course*> courses);
