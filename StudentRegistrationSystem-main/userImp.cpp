#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "user.h"

using namespace std;

string user::getUSN()
{
   return USN;
}

string user::getpassword()
{
   return password;
}

string user::getfname()
{
   return fname;
}

string user::getlname()
{
   return lname;
}

int user::getutype()
{

return utype;
}


bool user::checkPassword(string passwordIn)
{
   bool check = false;
   if(password == passwordIn)
   {
       check = true;
   }
   return check;
}

void user::setUSN(string usnIn)
{
   USN = usnIn;
}

void user::setPWD(string pwdIn)
{
   password = pwdIn;
}

void user::setfname(string fnameIn)
{
   fname = fnameIn;
}

void user::setlname(string lnameIn)
{
   lname = lnameIn;
}

void user::set(string u, string p, string fn, string ln)
{

}

user::user()
{
   USN = "jdoe";
   password = "password";
   fname = "John";
   lname = "Doe";
}

user::user(string usnIn, string passwordIn, string fnameIn, string lnameIn, int utypeIn)
{

   USN = usnIn;
   password = passwordIn;
   fname = fnameIn;
   lname = lnameIn;
   utype = utypeIn;
}
