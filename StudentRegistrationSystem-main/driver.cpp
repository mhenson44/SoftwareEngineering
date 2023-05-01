#include <iostream>
#include "userImp.cpp"
#include "CTRL_LOGIN.cpp"
#include "facultyMainPage_CTRL.cpp"
#include "studentMainPage_CTRL.cpp"
#include "adminMainPage_CTRL.cpp"

using namespace std;


int main(){

  string usercatch;
  login loginpage;

  user* current= loginpage.loginCtrl();
  //calls the main page of the corresponding user type 
  if(current->getutype() == 0){
    adminMainPage adm;
    adm.printOptions(current);
  } else if(current->getutype() == 1){
    studentMainPage stu;
    stu.printOptions(current);
  } else if(current->getutype() ==2){
    facultyMainPage fac;
    fac.printOptions(current);
  }


  
  //free the memory of the object
  delete current;
  cout<<endl<<endl<<endl<< "Thank you for using our system" << endl <<endl;
  return 0;
}
