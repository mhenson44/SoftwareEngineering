#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <sstream>

//NEEDS ERROR CHECKING
class adminRegistration
{
  public:
  void updateRegistration();
};

void adminRegistration::updateRegistration()
{
    string filename = "Registration.txt";
    string oldWord = "OPEN";
    string newWord = "CLOSED";
    ifstream inputFile(filename); // Open the file for reading
    ofstream outputFile("temp.txt"); // Open a temporary file for writing
    bool isValid = false;
    char ny = 'n';
    
    if (inputFile.is_open()) {
        cout << "Do you want to open/close registration? y/n" << endl;
        cin >> ny;
        while (isValid == false)
        {
            if (ny == 'n' || ny == 'N' || ny == 'y' || ny == 'Y')
                isValid = true;
            else {
                cout << "Invalid input, please enter y or n." << endl;
                cin >> ny;
            }
        }
    }

    else {
        cout << "Error opening file registration.txt." << endl;
        exit(7);
    }

    if (inputFile.is_open()) {
        string line;
        if(ny == 'y' || ny == 'Y') {
            while (getline(inputFile, line)) {
               istringstream iss(line);
               string firstWord;
               iss >> firstWord; // Extract the first word from the line
               if (firstWord == oldWord) {
                  outputFile << newWord << " " << iss.str().substr(firstWord.length()) << endl; // Write the new word and the rest of the line to the temporary file
                  cout << "Registration is now " << newWord << endl;
               } else if (firstWord == newWord) {
                   outputFile << oldWord << " " << iss.str().substr(firstWord.length()) << endl; // Write the new word and the rest of the line to the temporary file
                  cout << "Registration is now " << oldWord << endl;
               } else {
                  outputFile << line << endl; // Write the original line to the temporary file
               }
            }
            inputFile.close();
            outputFile.close();

            remove(filename.c_str()); // Remove the original file
            rename("temp.txt", filename.c_str()); // Rename the temporary file to the original file name
         } else {
             cout << "Okay" << endl;
         }
            } else {
               cout << "Error opening file registration.txt." << endl;
               exit(7);
            }

            string inputFilename = "studentCurrentCourses.txt";
            string outputFilename = "studentPreviousCourses.txt";

            ifstream ainputFile(inputFilename);
            ofstream aoutputFile(outputFilename, ios::app);

            if (ainputFile && aoutputFile) {
               string line;
               while (getline(ainputFile, line)) {
                  aoutputFile << line << endl;
               }
            } else {
               cerr << "Error: Could not open file." << endl;
            }
}
