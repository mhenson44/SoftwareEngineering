#ifndef admin_H
#define admin_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "user.h"

using namespace std;

class admin: public user
{
   private:
      string department; // stores the faculty member's department

   public:
      void changeRegistration(); // prints the roster of a specified course

      admin(); // default constructor
      admin(string, string, string, string,int); // parameterized constructor
};

#endif
