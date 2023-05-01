#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fstream>

//NEEDS ERROR CHECKING
class userViewCourses
{
  public:
  void viewCurrentCourses(user*);
  void viewPreviousCourses(user*);
};

void userViewCourses::viewCurrentCourses(user* passeduser)
{
  user* current=passeduser;
  int userTypeHold = current->getutype();
  
  if(userTypeHold==2){
     string filename = "facultyCurrentCourses.txt";
     string search_string;
     search_string = current->getUSN();

     ifstream infile(filename);
     string line;
     while (getline(infile, line)) {
         if (line.find(search_string) != string::npos) {
             cout << line << endl;
         }
     }
     infile.close();
  } else if(userTypeHold==1){
     string filename = "studentCurrentCourses.txt";
     string search_string;
     search_string = current->getUSN();

     ifstream infile(filename);
     string line;
     while (getline(infile, line)) {
         if (line.find(search_string) != string::npos) {
             cout << line << endl;
         }
     }
     infile.close();     
  }

}



void userViewCourses::viewPreviousCourses(user* passeduser)
{
  user* current=passeduser;
  int userTypeHold = current->getutype();
  
  if(userTypeHold==2){
     string filename = "facultyPreviousCourses.txt";
     string search_string;
     search_string = current->getUSN();

     ifstream infile(filename);
     string line;
     while (getline(infile, line)) {
         if (line.find(search_string) != string::npos) {
             cout << line << endl;
         }
     }
     infile.close();
  } else if(userTypeHold==1){
     string filename = "studentPreviousCourses.txt";
     string search_string;
     search_string = current->getUSN();

     ifstream infile(filename);
     string line;
     while (getline(infile, line)) {
         if (line.find(search_string) != string::npos) {
             cout << line << endl;
         }
     }
     infile.close();     
  }

}
