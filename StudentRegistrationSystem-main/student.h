#ifndef student_H
#define student_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "user.h"

using namespace std;

class student: public user
{
   private:
      string department; // stores the faculty member's department

   public:
      void viewCurrentCourses();
      void viewPreviousCourses();
      void viewAccount();
      void viewCurrentGrades();
      void viewPreviousGrades();
      void viewTranscript();
      void registerforCourses();
      student(); // default constructor
      student(string, string, string, string,int); // parameterized constructor
};

#endif
