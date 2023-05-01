#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <fstream>

class studentRegisterForCourses
{
  public:
  void registerForCourses(user*);
};

void studentRegisterForCourses::registerForCourses(user* passeduser)
{
  user* current=passeduser;
  int userTypeHold = current->getutype();
  string usn;
  usn = current->getUSN();
     if(userTypeHold==1){
        ifstream file("Registration.txt"); // open the file
        string line;

        if (file.is_open()) { // check if file is open
           getline(file, line); // read one line from the file
           char lineCheck[4];
           for (int i = 0 ; i < 4 ; i++) { // reads the first four characters into a char array for comparison
              lineCheck[i] = line[i];
           }
           int openCheck = strcmp(lineCheck, "OPEN"); // performs a string comparison, if it's equal to zero, the reigstration is open
           if(openCheck == 0){
              ifstream file("courseCatalog.txt"); // open the file
              string lines[200]; // declare an array to store the lines
              int count = 0;
              if (file.is_open()) { // check if file is open
                 while (getline(file, lines[count])) { // read lines and store them in the array
                    count++;
                 }
              file.close(); // close the file

              // print out the lines and ask the user to select one
              for (int i = 0; i < count; i++) {
                 cout << i+1 << ": " << lines[i] << endl;
              }
              int selection;
              cout << "Enter the line number of the class you want to register for or enter 0 to exit registration: ";
              cin >> selection;
              if (selection < count + 1 && selection > 0){
                 cout << "You selected: " << lines[selection-1] << endl;
                 // write selected line into another file
                 ofstream outfile("studentFutureCourses.txt", ios::app); // open the output file in append mode
                 if (outfile.is_open()) { // check if file is open
                    string line = lines[selection-1];
                    ifstream checkfile("studentFutureCourses.txt"); // open the output file for checking
                    bool exists = false;
                    string checkline;
                    while (getline(checkfile, checkline)) { // read lines from output file and check if selected line already exists
                       checkline = usn + ' ' +  checkline;
                       if (line == checkline) {
                          exists = true;
                          break;
                       }
                    }
                    checkfile.close(); // close the output file for checking
                    if (exists) { // selected line already exists in output file
                        cout << "Error: Line already exists in output file." << endl;
                    }
                    else { // selected line does not exist in output file, so write it
                       outfile << usn << " " << line << endl;
                       cout << "Selected line has been written to output file." << endl;
                    }
                    outfile.close(); // close the output file
                 }
                 else {
                    cout << "Unable to open output file." << endl;
                 }
              }
              else if (selection == 0) {
                 file.close();
              }
              else {
                 cout << endl << "Invalid course selection." << endl << endl; 
              }
         }
              else {
              cout << "Unable to open file." << endl;
              }
           }
           else {
           cout << endl << "Registration is currently closed." << endl << endl;
           }
        }
        file.close(); // close the file
           
    }
    else {
       cout << "Unable to open file." << endl;
    }
}

