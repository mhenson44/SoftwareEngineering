#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <vector>
using namespace std;
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

     
    /* if the user is a facutly it will print all of their previous courses to the terminal
    from facultypreviouscourses.txt then it will prompt them to select a course to view the roster
    if they select 0 it will exit the function howver if they select a course it will open the file
    named after them and the course and print all of those entries to the terminal */
    string filename = "facultyCurrentCourses.txt";
    string search_string;
    search_string = current->getUSN();
    int count=1;

    ifstream infile(filename);
    string line;
    vector<string> matching_lines;
    while (getline(infile, line)) {
      if (line.find(search_string) != string::npos) {
        cout <<count<< ' '<< line << endl;
        count++;
        matching_lines.push_back(line); // Store matching lines in a vector
      }
    }
    infile.close();

    if (matching_lines.empty()) {
      cout << "No matching lines found." << endl;
      // Handle this case as needed.
    } else {
      cout << "Select a class to view roster or 0 to exit: ";
      int selected_line_number;
      cin >> selected_line_number;
      if (selected_line_number > 0 && selected_line_number <= matching_lines.size()) {
        string selected_line = matching_lines[selected_line_number - 1];
        
        //formatting file name
        selected_line.erase(remove_if(selected_line.begin(),selected_line.end(),::isspace),selected_line.end());
        selected_line+=".txt";
    
        string filepath = "facultyCurrentRosters/"+selected_line;
        ifstream file(filepath);
        string wohoo;
        
        if(!file.is_open()){
          cout<<"Error opening roster file"<<endl<<endl;
          cout<<"Attempted to open file:  "<<filepath<<endl;
          exit(7); //7 denotes missing file
        }
  
        while(getline(file,wohoo)){
          cout<< wohoo <<endl;
        }
        cout<<endl<<endl;
        file.close();

      }else if(selected_line_number==0){
      } else{
        cout << "Invalid selection." << endl;
      }

    }


  } else if(userTypeHold==1){

        ifstream file("studentCurrentCourses.txt"); // open the file
        string line;

        if (file.is_open()) { // check if file is open
           string lines[100]; // declare an array to store the lines
           int count = 0;

           string search_string; // string variable to search for username
           search_string = current->getUSN(); // Set the variable to the username
           
           if (file.is_open()) { // check if file is open
              while (getline(file, lines[count])) { // read lines and store them in the array
                  if (lines[count].find(search_string) != string::npos) {
                     count++;
                     cout << count << ": " << lines[count-1] <<endl;
                  }
              }
              file.close(); // close the file

              int selection; // Variable to hold what the user selects
	      bool flag = true; // Variable to know if the user selected a proper selection
              char yn = 'y';


             //this is commented out because individual assignment grades have been removed for simplicity
             /* while (flag){
                 cout << "Enter the line number of the class you want to view grades for: ";
                 cin >> selection; // get the line of the class the user wants to view grades for
                 cout << endl;
                    if(selection < count + 1) { // checks to see if the user input works
                       cout << "You selected: " << lines[selection-1] << endl; // outputs what line the user selected
                       string filename = "courseGrades.txt"; // searches this file
                       string search_string; // variable to store username
                       search_string = current->getUSN(); // setting the variable to the username of the user

                       ifstream infile(filename); // opens the file to search
                       string line; // variable to store whole line
                       while (getline(infile, line)) { // while loop to print everything in the file
                          if (line.find(search_string) != string::npos) { // 
                             cout << line << endl; // output the line
                          }
                       }
                       infile.close(); // close the file
                       flag = false; // exit the while loop
                       cout << endl;
                    } else { // in case the user enters incorrect input to the line number
                       cout << "Please enter a line number: " << endl; // prompt the user again
                    }
                    
             }*/
          } else {
              cout << "Unable to open file." << endl; // error if file doesnt exist
          }
       }
    } else {
       cout << "Unable to open file." << endl; // error if file doesnt exist
    }
}



void userViewCourses::viewPreviousCourses(user* passeduser)
{
  user* current=passeduser;
  int userTypeHold = current->getutype();
  
  if(userTypeHold==2){
     
    /* if the user is a facutly it will print all of their previous courses to the terminal
    from facultypreviouscourses.txt then it will prompt them to select a course to view the roster
    if they select 0 it will exit the function howver if they select a course it will open the file
    named after them and the course and print all of those entries to the terminal */
    string filename = "facultyPreviousCourses.txt";
    string search_string;
    search_string = current->getUSN();
    int count=1;

    ifstream infile(filename);
    string line;
    vector<string> matching_lines;
    while (getline(infile, line)) {
      if (line.find(search_string) != string::npos) {
        cout <<count<< ' '<< line << endl;
        count++;
        matching_lines.push_back(line); // Store matching lines in a vector
      }
    }
    infile.close();

    if (matching_lines.empty()) {
      cout << "No matching lines found." << endl;
      // Handle this case as needed.
    } else {
      cout << "Select a class to view roster or 0 to exit: ";
      int selected_line_number;
      cin >> selected_line_number;
      if (selected_line_number > 0 && selected_line_number <= matching_lines.size()) {
        string selected_line = matching_lines[selected_line_number - 1];
        
        //formatting file name
        selected_line.erase(remove_if(selected_line.begin(),selected_line.end(),::isspace),selected_line.end());
        selected_line+=".txt";
    
        string filepath = "facultyPreviousRosters/"+selected_line;
        ifstream file(filepath);
        string wohoo;
        
        if(!file.is_open()){
          cout<<"Error opening roster file"<<endl<<endl;
          exit(7); //7 denotes missing file
        }
  
        while(getline(file,wohoo)){
          cout<< wohoo <<endl;
        }
        cout<<endl<<endl;
        file.close();

      }else if(selected_line_number==0){
      } else{
        cout << "Invalid selection." << endl;
      }
    }   
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
