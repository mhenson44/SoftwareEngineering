#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "admin.h"

using namespace std;

void admin::changeRegistration()
{
}

admin::admin()
{
   // If a faculty member is instantiated without assignement, their properties are shown as "Unassigned"
}

admin::admin(string usnIn, string passwordIn, string fnameIn, string lnameIn, int utypeIn): user(usnIn, passwordIn, fnameIn, lnameIn,utypeIn)
{
   // Set faculty values equal to faculty inputs
}
