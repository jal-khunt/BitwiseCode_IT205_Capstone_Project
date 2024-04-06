#include <iostream>
#include <vector>
#include <string>

#include "main_input.cpp"
#include "classFile.cpp"
#include "classDate.cpp"
#include "Mtimes.cpp"
#include "emptyfiles.cpp"
#include "comparison.cpp"
using namespace std;


/*
/home/shreyas/Desktop/testinput.txt
*/

class File;


int main(){
    string s;
    int testing;
    vector<File> v;

    cout << "testing?[1/0] ";
    cin >> testing;
        if(testing){
            s = "/home/shreyas/Desktop/testinput.txt";
            
        }
        else {  
            //getting input file
            cout << "Input file location: ";
            cin >> s;
        }


    input_parser(v, s);                          //vector v is set;

        if(v.size() == 0){
            cout << "Empty file provided.\n";
            return 0;
        }
   


    cout << "File cleaner starting...\n\n";


    //removing old files
        cout << "Removing Old Files..\n\tRemove files older than (in months): ";
        int month = 0;
        string date;
        cin >> month;
        cout << "\tToday's date: ";
        cin >> date;
        cout << "\tRemoving files older than " << month << " months.\n";
        int del_date = compare_month(v, month, date);
        cout << "\t" << del_date << "file(s) have been removed succesfully :)\n\n";
        cout << endl << endl;
        if(v.empty()){
            cout << "\nFolder is empty\n";
            return 0;
        }


    //Less than M times opened
        cout << "Deleting unused/obsolete files:\n\tMinimum number of times a file should have been opened: ";
        int m;
        cin >> m;
        int c = lessThanMTimes(v, m);
        cout << "\t" << c << " file(s) have been removed succesfully :)\n\n";
        if(v.empty()){
            cout << "\nFolder is empty\n";
            return 0;
        }

    //deleting empty files
        cout << "Checking for empty files and deleting them...\n";
        int dE = deleteEmptyFiles(v);
        cout << "\t" << dE << " empty file(s) have been removed successfully :)\n\n";
        if(v.empty()){
            cout << "\nFolder is empty\n";
            return 0;
        }


    //comparing files and removing duplicates and files with same data
        cout << "Removing duplicates...\n";
        int ca = compareAndDelete(v);
        cout << "\t" << ca << " file(s) have been removed succesfully :)\n\n";
        if(v.empty()){
            cout << "\nFolder is empty\n";
            return 0;
        }


    cout << "\nProgram end\n";

    return 0;
}

