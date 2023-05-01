#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "student.h"

using namespace std;

void student::viewCurrentCourses()
{
}

void student::viewPreviousCourses()
{
}

void student::viewAccount()
{
}

void student::viewCurrentGrades()
{
}

void student::viewPreviousGrades()
{
}

void student::viewTranscript()
{
}

void student::registerforCourses()
{
}

student::student()
{
   // If a faculty member is instantiated without assignement, their properties are shown as "Unassigned"
}

student::student(string usnIn, string passwordIn, string fnameIn, string lnameIn, int utypeIn): user(usnIn, passwordIn, fnameIn, lnameIn,utypeIn)
{
}
