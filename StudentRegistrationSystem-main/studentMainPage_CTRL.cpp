#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <sstream>
#include "studentViewTranscript_CTRL.cpp"
#include "studentRegisterForCourses_CTRL.cpp"

using namespace std;
bool logoutNotSelected = true;
class studentMainPage{

  public:

  void printOptions(user*);

  private:
  void callAppropriate(int selection, user* passeduser);
};

void studentMainPage::printOptions(user* passeduser){

  user* current=passeduser;
  
  // loops infinitely until a user selects logout, ensuring user is able to perform as many actions as they want during a session
  while(logoutNotSelected == true)
  {
    cout<<"Welcome "<<current->getfname()<<" to the student registration system!"<<endl;
    cout<<"Student Main Page"<<endl;
    cout<<"1. View Current Courses"<<endl;
    cout<<"2. View Previous Courses"<<endl;
    cout<<"3. View Account"<<endl;
    cout<<"4. View Transcript"<<endl;
    cout<<"5. Register for Courses"<<endl;
    cout<<"6. Logout"<<endl;
    
    int pass = 0;
    bool validSelection = false; 
    // loops to check to ensure valid user input
    while(validSelection == false)
    {
      cout<<"Enter selection 1-6:";
      cin>>pass;

      if(pass == 1 || pass == 2 || pass == 3 || pass == 4 || pass == 5 || pass == 6){
         validSelection = true;
         callAppropriate(pass,current);
         if(pass == 6){
            logoutNotSelected = false;
         }
      } 
     
      else
      {
        cout << "Invalid input, please enter a value 1-6." << endl;
      }
    }
  }
}


void studentMainPage::callAppropriate(int selection, user* current)
{
  if(selection == 1){
       // Views the students currnet courses
       userViewCourses hold1;
       hold1.viewCurrentCourses(current);       
  } else if (selection == 2){
       // Views the students preivous courses
       userViewCourses hold2;
       hold2.viewPreviousCourses(current);       
  } else if (selection == 3) {
       // Views the Students Account
       userViewAccount hold3;
       hold3.viewAccount(current);
  } else if (selection == 4) {
       // Views the Students Transcript
       studentViewTranscript hold4;
       hold4.viewTranscript(current);
  } else if (selection == 5) {
       // Displays the students registration
       studentRegisterForCourses hold5;
       hold5.registerForCourses(current);
  } else if (selection == 6) {
       // Logs the Student out
       logoutNotSelected = false;
  }
/*
  switch(selection){

    case 1:
      //view current courses ctrl class call
       userViewCourses hold1;
       hold1.viewCurrentCourses(current);       
    case 2:
      //view previous courses ctrl class call
       userViewCourses hold2;
       hold2.viewPreviousCourses(current);       
    case 3:
       //view previous courses ctrl class call
       userViewAccount hold3;
       hold3.viewAccount(current);
    case 4:
       studentViewTranscript hold4;
       hold4.viewTranscript(current);
    case 5:
       studentRegisterForCourses hold5;
       hold5.registerForCourses(current);
    case 6:
      //shut down sustem
       logoutNotSelected = false;
       break;
    default:
    cout<<"Selection not avaliable"<<endl;
*/
  }
