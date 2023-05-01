#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fstream>

//NEEDS ERROR CHECKING
class userViewAccount
{
  public:
  void viewAccount(user*);

  private:
  void modifyAccount(user*);

};

void userViewAccount::viewAccount(user* passeduser)
{

   user* current= passeduser;
   char answer='N';
   //switch(current->getutype()){
   //case 0:
     //admin details
   //case 1:
     cout<<"username: "<<current->getUSN()<<endl;
     cout<<"first name: "<<current->getfname()<<endl;
     cout<<"last name: "<<current->getlname()<<endl;
     cout<<"Would you like to modify? (Y/N)"<<endl;
     cin>>answer;

     if(answer == 'Y' || answer == 'y'){
       modifyAccount(current);
     }
   //case 2:
     //faculty details
     //cout<<"Would you like to modify? (Y/N)"<<endl;
   //default:
   //cout<<"problem with user initialization, shutting down"<<endl;
   //exit(40);

}




void userViewAccount::modifyAccount(user* passeduser)
{
  user* current=passeduser;
 

  //deletes old user from text file
  string filename = "users.txt";
  string search_string;
  search_string = current->getUSN();

  int userTypeHold = current->getutype();  
  string passwordcheck = current->getpassword();
  

  ifstream infile(filename);
  ofstream outfile(filename + ".tmp");
  string line;
  while (getline(infile, line)) {
      if (line.find(search_string) == string::npos) {
          outfile << line << endl;
      }
  }
  infile.close();
  outfile.close();
  remove(filename.c_str());
  rename((filename + ".tmp").c_str(), filename.c_str());




  string fname,lname,password,newPasswordCheck;
 
  cout<<endl<<"Please enter your first name: ";
  cin>>fname;
  cout<<endl<<"Please enter your last name: ";
  cin>>lname;

  //checks the user for old password before letting them enter a new one
  bool passwordIn=false;
  while(passwordIn==false)
  {
    cout<<endl<<"Please enter your previous password: ";
    cin>>password;

    if(password==passwordcheck){
      passwordIn=true;
    }
    else{
    cout<<endl<<"Incorrect"<<endl<<endl;
    }
  }


  SetStdinEcho(false); //hide password as they type
  bool newpassword=false;
  while(newpassword==false)
  {
    //new password setting, makes them type it twice
    cout<<endl<<endl<<"New Password: ";
    cin>>password;
    cout<<endl<<"ReEnter new password: ";
    cin>>newPasswordCheck;

    if(password==newPasswordCheck){
      newpassword=true;
    }
    else{
    cout<<endl<<"Incorrect"<<endl<<endl;
    }
 
  }
  cout<<endl<<endl;
  SetStdinEcho(true);


  ofstream output_file("users.txt", ios::app);
  output_file << search_string << " " << password << " " << userTypeHold << " " << fname << " " << lname << endl;
  current->set(search_string,password,fname,lname);
  output_file.close();


}
