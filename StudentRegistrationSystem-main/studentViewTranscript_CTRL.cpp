#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fstream>

//NEEDS ERROR CHECKING
class studentViewTranscript
{
  public:
  void viewTranscript(user*);
};

void studentViewTranscript::viewTranscript(user* passeduser)
{
  user* current=passeduser;

  double totalgrade = 0.0;
  double cnt = 0.0;
  double avggrade = 0.0;
  
  string filename = "studentCurrentCourses.txt";
  string search_string;
  search_string = current->getUSN();

  ifstream infile(filename);
  string line;
  while (getline(infile, line)) {
     if (line.find(search_string) != string::npos) {
         cout << line << endl;
         string user, course, section, grade;
	 stringstream ss(line);
	 ss >> user >> course >> section >> grade;
         cnt++;
         if(grade == "A"){
               totalgrade += 4.0;
         } else if (grade == "B"){
               totalgrade += 3.0;
         } else if (grade == "C"){
               totalgrade += 2.0;
         } else if (grade == "D"){
               totalgrade += 1.0;
         } else if (grade == "F"){
               totalgrade += 0.0;
         }
     }
  }
  infile.close();     
  
  string filename2 = "studentPreviousCourses.txt";

  ifstream infile2(filename2);
  
  while (getline(infile2, line)) {
     if (line.find(search_string) != string::npos) {
         cout << line << endl;
         string user, course, section, grade;
	 stringstream ss(line);
	 ss >> user >> course >> section >> grade;
         cnt++;
         if(grade == "A"){
               totalgrade += 4.0;
         } else if (grade == "B"){
               totalgrade += 3.0;
         } else if (grade == "C"){
               totalgrade += 2.0;
         } else if (grade == "D"){
               totalgrade += 1.0;
         } else if (grade == "F"){
               totalgrade += 0.0;
         }
     }
  }
  infile2.close();     
  avggrade = totalgrade / cnt;
  cout << "Your Final GPA is a: " << avggrade << endl;
}
