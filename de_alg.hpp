/*
 * Header File for the Deferred Acceptance Algorithm 
 * Authors: Alex Frias and Alex Peckman
 */
#pragma once
#include "obs.hpp"
#include <list>

list<Student*> deferred_acceptance(list<Student*> students, 
				   list<Course*> courses);
