#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "faculty.h"
#include "user.h"

using namespace std;

int main()
{
   faculty user1;
   string username = user1.getUSN();
   cout << username << endl;
   
   bool passCheckGood = user1.checkPassword("password");
   cout << passCheckGood << endl;

   bool passCheckBad = user1.checkPassword("drowssap");
   cout << passCheckBad << endl;

   return 0;
}
