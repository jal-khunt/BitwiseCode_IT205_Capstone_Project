#include <iostream>
#include <vector>
#include <string>

#include "main_input.cpp"
#include "classFile.cpp"
#include "Mtimes.cpp"
#include "emptyfiles.cpp"
#include "compare_file_older_months.cpp"
#include "comparison.cpp"
using namespace std;


/*
/home/shreyas/Desktop/testinput.txt
*/

class File;


int main(){

    //getting input file
    int testing;
    cout << "testing?[1/0] ";
    cin >> testing;
    string s;
        if(testing){
            s = "/home/shreyas/Desktop/testinput.txt";
            
        }
        else {
            cout << "Input file location: ";
            cin >> s;
        }

    vector<File> v;

    input_parser(v, s);

        if(v.size() == 0){
            cout << "Empty file provided.\n";
            return 0;
        }

    //vector v is set;


        cout << "File cleaner starting...\n\n";


    //removing old files
        cout << "Removing Old Files..\n\tRemove files older than (in months): ";
        int month = 0;
        cin >> month;
        cout << "\tRemoving files older than " << month << " months.";
        compare_months(v, month);
        cout << endl << endl;


    //Less than M times opened
        cout << "Deleting unused/obsolete files:\n";
        cout << "\tMinimum number of times a file should have been opened: ";
        int m;
        cin >> m;
        int c = lessThanMTimes(v, m);
        cout << "\t" << c << " file(s) have been removed succesfully :)\n\n";

    //deleting empty files
        cout << "Checking for empty files and deleting them...\n";
        int dE = deleteEmptyFiles(v);
        cout << "\t" << dE << " empty file(s) have been removed successfully :)\n\n";


    //comparing files and removing duplicates and files with same data
        cout << "Removing duplicates...\n";
        int ca = compareAndDelete(v);
        cout << "\t" << ca << " file(s) have been removed succesfully :)\n\n";


    cout << "\nProgram end\n";

    return 0;
}

