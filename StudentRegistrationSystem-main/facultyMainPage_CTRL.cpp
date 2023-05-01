#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <sstream>
#include "userViewAccount_CTRL.cpp"
#include "userViewCourses_CTRL.cpp"

using namespace std;

bool logoutNotSelectedfac=true;

class facultyMainPage
{

  public:

  void printOptions(user*);

  private:
  void callAppropriate(int selection, user* passeduser);


};




void facultyMainPage::printOptions(user* passedUser){


  user* current=passedUser;
  
  // loops infinitely until a user selects logout, ensuring user is able to perform as many actions as they want during a session
  while(logoutNotSelectedfac == true)
  {
    
    int pass = 0;
    bool validSelection = false; 
    // loops to check to ensure valid user input
    while(validSelection == false)
    {

      cout<<"Welcome "<<current->getfname()<<" to the student registration system!"<<endl;
      cout<<"Faculty Main Page"<<endl;

      cout<<"1. View Current Courses"<<endl;
      cout<<"2. View Previous Courses"<<endl;
      cout<<"3. View Account"<<endl;
      cout<<"4. Logout"<<endl;
      cout<<"Enter selection 1-4:";
      cin>>pass;
      cout<<endl;
      if(pass == 1 || pass == 2 || pass == 3 || pass == 4)
      {
        validSelection = true;
        callAppropriate(pass,current);
        if(pass == 4)
        {
          logoutNotSelectedfac = false;
        }
      } 
     
      else
      {
        cout << "Invalid input, please enter a value 1-4." << endl;
      }
    }
  }
}


void facultyMainPage::callAppropriate(int selection, user* current)
{
   //friendship ended with switch statements not if else is my best friend
   
     if(selection == 1){
       // Views the students currnet courses
       userViewCourses hold1;
       hold1.viewCurrentCourses(current);       
  } else if (selection == 2){
       // Views the students preivous courses
       userViewCourses hold2;
       hold2.viewPreviousCourses(current);       
  } else if (selection == 3) {
      userViewAccount hold;
      hold.viewAccount(current);

  } else if (selection == 4) {
       // Logs the faculty out
       logoutNotSelectedfac = false;
  } 


}
