/* CDM stands for create delete modify */
#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <vector>
#include <cstdio>
 
using namespace std;

//NEEDS ERROR CHECKING
class adminUserCDM
{
  public:
  void CDM_CTRLER();

  private:
  //the int is used to modify the dialouge based on wether it is a completely new user or a new version of an old user
  //no effect on implementation
  void create();
  void delUser();
  void modifyUser();
};

void adminUserCDM::CDM_CTRLER(){
  bool notSelected=true;
  string answer="";
  while(notSelected==true){
    //prompt admin for choic
    cout<<endl<<endl<<"Would you like to add, delete, or modify a user?";
    cin>>answer;

    if(answer=="add" || answer=="Add")
    {
 
      notSelected=false;
      create();

    }else if(answer=="delete" || answer == "Delete"){
         
      notSelected=false;
      delUser();
    }else if(answer=="modify" || answer == "Modify"){
    
     notSelected=false;
     modifyUser();
    
    }
  }
};



void adminUserCDM::create(){

  string filename = "users.txt";
  string newlinegrab;


  // Prompt the user for five strings, with error checking
  cout <<endl<<endl<< "Please enter the information of the new user: ";
  string s1, s2, s3, s4, s5;
  do {
      cout<<endl<<endl;
      cout << "Enter the username:";
      getline(cin, newlinegrab); //a newline character is left over in input string do not remove
      getline(cin, s1);
      cout<<endl<<endl;
  }while (s1.empty());
  do {
      cout << "Enter password (It is recommended to enter a temporary password and let the user change it later) :";
      getline(cin, s2);
      cout<<endl<<endl;
  }while (s2.empty());
  do {
      cout << "Enter user type (0 for admin, 1 for student, 2 for faculty) :";
      getline(cin, s3);
      cout<<endl<<endl;
  } while (s3.empty());
  do {
      cout << "Enter first name: ";
      getline(cin, s4);
      cout<<endl<<endl;
  } while (s4.empty());
  do {
      cout << "Enter last name: ";
      getline(cin, s5);
      cout<<endl<<endl;
  } while (s5.empty());

    // Open the file in append mode
  ofstream outFile(filename, ios::app);
  if (!outFile){
    cerr << "Unable to open users.txt";
    exit(7); //7 denotes missing file
  }

  outFile << s1 << " " << s2 << " " << s3 << " " << s4 << " " << s5;

  // Close the file
  outFile.close();

  cout << "User added!"<<endl<<endl;

}


void adminUserCDM::delUser(){

  string answer="";
  int count=1;
  while(answer!="Y" && answer!="N"){

    //outputs error if no coreect choice selected
    if(count!=1){
      cout<<"please enter a valid option"<<endl;
    }

    cout<<endl<<endl<<"Do you know the username of the user you wish to delete/modify (Y/N)?";
    cin>>answer;
    count++;

  }


  //if the admin know the username they wish to delete follow below
  if(answer=="Y"){

    string searchString;
    cout<<endl<<endl<<"Enter the username of the user you wish to delete/modify:"<<endl;
    cin>>searchString;
   

    ifstream inFile("users.txt");
    if (!inFile)
    {
        cerr << "Unable to open users.txt";
        exit(7);  //7 denotes missing file
    }

    ofstream tempFile("temp.txt");
    if (!tempFile)
    {
        cerr << "Unable to create temp file";
        exit(8); //8 denotes file cant create
    }

    string line;
    while (getline(inFile, line))
    {
        if (line.find(searchString) != string::npos)
        {
            // The search string was found, skip this line
            continue;
        }

        // The search string was not found, write this line to the temporary file
        tempFile << line << endl;
    }

    // Close both files
    inFile.close();
    tempFile.close();

    // Delete the original file
    remove("users.txt");

    // Rename the temporary file to the original filename
    rename("temp.txt", "users.txt");



 
  }else{
   
    ifstream file("users.txt");
    string line;
    vector<string> lines;

    // Read the file line by line
    while (getline(file, line)) {
        lines.push_back(line);
    }

    int page_size = 20;
    int num_pages = (lines.size() + page_size - 1) / page_size;

    for (int page = 0; page < num_pages; page++) {
        int start = page * page_size;
        int end = min((page + 1) * page_size, (int)lines.size());

        // Output the current page
        for (int i = start; i < end; i++) {
            cout << i+1 << ": " << lines[i] << endl;
        }

        // Prompt the user to delete a line
        int line_to_delete = 0;
        do {
            cout << "Enter the number of the user to delete/modify (or 0 to continue): ";
            cin >> line_to_delete;
        } while (line_to_delete < 0 || line_to_delete > end - start);

        // Delete the selected line
        if (line_to_delete != 0) {
            lines.erase(lines.begin() + start + line_to_delete - 1);
            cout << "Line deleted." << endl;
        }
    } 


    // Save the modified file
      ofstream output("users.txt");
      for (int i = 0; i < lines.size(); i++) {
          output << lines[i] << endl;
      }
      output.close();


  }
};



void adminUserCDM::modifyUser(){

  delUser();
  create();
};

