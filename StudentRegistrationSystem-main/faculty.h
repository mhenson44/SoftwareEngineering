#ifndef faculty_H
#define faculty_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "user.h"

using namespace std;

class faculty: public user
{
   private:
      string department; // stores the faculty member's department

   public:
      void viewSections(); // prints the sections a faculty member is assigned to
      void viewRoster(string); // prints the roster of a specified course
      faculty(); // default constructor
      faculty(string, string, string, string,int); // parameterized constructor
};

#endif
