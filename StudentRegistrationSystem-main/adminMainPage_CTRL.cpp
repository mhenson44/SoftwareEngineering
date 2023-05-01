#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <sstream>
#include "admin.h"
#include "adminRegister_CTRL.cpp"
#include "adminUserCDM_CTRL.cpp"
#include "adminCourseCDM_CTRL.cpp"

using namespace std;
bool logoutNotSelectedd = true;

class adminMainPage{

  public:

  void printOptions(user*);

  private:
  void callAppropriate(int selection, user* passeduser);
};

void adminMainPage::printOptions(user* passeduser){

  user* current=passeduser;
  
  // loops infinitely until a user selects logout, ensuring user is able to perform as many actions as they want during a session
  while(logoutNotSelectedd == true)
  {
    cout<<endl;
    cout<<"Welcome "<<current->getfname()<<" to the student registration system!"<<endl;
    cout<<"Admin Main Page"<<endl;
    cout<<"1. CDM users"<<endl;
    cout<<"2. CDM courses"<<endl;
    cout<<"3. Change Registration"<<endl;
    cout<<"4. logout"<<endl;
    
    int pass = 0;
    bool validSelection = false; 
    // loops to check to ensure valid user input
    while(validSelection == false)
    {
      cout<<"Enter selection 1-4:";
      cin>>pass;

      if(pass == 1 || pass == 2 || pass == 3 || pass == 4){
         validSelection = true;
         callAppropriate(pass,current);
         if(pass == 4){
            logoutNotSelectedd = false;
         }
      } 
     
      else
      {
        cout << "Invalid input, please enter a value 1-6." << endl;
      }
    }
  }
}


void adminMainPage::callAppropriate(int selection, user* current)
{
  if(selection == 1){
    adminUserCDM hold1;
    hold1.CDM_CTRLER();
  } else if (selection == 2){
    adminCourseCDM hold2;
    hold2.CCDM_CTRLER();
  } else if (selection == 3) {
       // Updates the registration status
       adminRegistration hold3;
       hold3.updateRegistration();
  } else if (selection == 4) {
       // Logs the admin out
       logoutNotSelectedd = false;
  }
}
