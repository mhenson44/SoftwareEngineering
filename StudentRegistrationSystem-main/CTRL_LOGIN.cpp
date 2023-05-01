#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <sstream>
#include "passwordHider.cpp"
#include "user.h"
#include "studentImp.cpp"
#include "facultyImp.cpp" 
#include "adminImp.cpp"

using namespace std;

class login
{
  public:
   user* loginCtrl();
  private:
};


user* login::loginCtrl(){
  string username; //holds the username that the user entered (not validated and not to be used for searches)
  string password; //holds the password that the user entered (not validated)
  //do not use these variables past log in, use the functions for the user and subsequent classes

  bool notLoggedIn=true;  //as long as true, the system will continue to ask user for login info
  bool invalidLogIn=false; 
  //controls the ouput of an error message (if false-> no error message, if true->error)
  //lets the user know that they entered invalid login info 



  //will run unti the user selects logout
    printf("Welcome to the student registration system! \n");

	   
    while(notLoggedIn){  //will run until the user enters valid log in info
       if(invalidLogIn){ //if the flag is raised that means that they entered invalid login and throws an error msg
         printf("Invalid username and/or password \n");
    }
   
      printf("Username: ");
      cin>>username;

      printf("\nPassword: ");
      SetStdinEcho(false);  //this hides the password as the user types it is
      cin>>password;
      SetStdinEcho(true);  //changes it back to showing what the user types in    
      cout<<endl<<endl;

      ifstream file("users.txt");
      if (file.is_open()) {
          string line;
          while (getline(file, line)) {
              // parse the line
              string user, pass, num, first, last;
              stringstream ss(line);
              ss >> user >> pass >> num >> first >> last;
              if (user == username && pass == password) {
                  notLoggedIn=false;
                  
                  //converts grabbed utype to int from string                  
                  int utype = stoi(num);


		  //create a user depending on utype and return
	 	  //this returns a pointer to the object just fyi
		  if(utype==0){
                  admin* current1= new admin(user,pass,first,last,utype); 
	          return current1;
                  } else if(utype==1){
                  student* current2= new student(user,pass,first,last,utype);
                  return current2;
                  } else if(utype==2){
                  faculty* current3= new faculty(user,pass,first,last,utype);
                  return current3;
                  }

                                    
              }
         }
         invalidLogIn=true;
     } else {
       cout << "Unable to open file." << endl;
     }

  }

 //here only for compiler can be safely ignored
 admin* current4= new admin("jday","password","jacob","day",1);
 return current4;

}
