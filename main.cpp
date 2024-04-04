#include <iostream>
#include <vector>
#include <string>

#include "classFile.cpp"
//#include "compare_file_older_months.cpp"
#include "comparison.cpp"
using namespace std;


/*
/home/shreyas/Desktop/testinput.txt
*/

class File;


int lessThanMTimes(vector<File> v, int m){
    int count = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i].noOfTimeOpened < m){
            delete_file(v[i].path,i,v);
            count++;
        }
    }
    cout << count;
}

int strcmp(string s1, string s2){
    if(s1.length() != s2.length()){
        return 0;
    }

    for(int i = 0; i < s1.length(); i++){
        if(s1[i] != s2[i]) return 0;
    }
    return 1;
}

int main(){

    string s, txt = "txt", csv = "csv";
    cout << "Input file location: ";
    
    //cin >> s;   // testing
    s = "/home/shreyas/Desktop/testinput.csv";
    
    string file_extension = s.substr(s.length()-3, 3);

    
    vector<File> v;

    if(strcmp(file_extension, txt)){
        v = inputFileTXT(s);
    }
    else if(strcmp(file_extension, csv)){
        v = inputFileCSV(s);
    }
    else{
        cout << "Please enter valid .txt or .csv files\n";
        return 0;
    }

    if(v.size() == 0){
        return 0;
    }

    //vector v is set;

    cout << "File cleaner starting...\n\n";

    //month
    cout << "Removing Old Files..\nRemove files older than (in months): ";
    int months = 0;
    //cin >> months;
    cout << "Removing files older than " << months << " months.";
    //compare_months(v, month);
    cout << endl << endl;


    //Less than M times opened
    cout << "Minimum number of times a file should have been opened: ";
    int m;
    cin >> m;
    lessThanMTimes(v, m);

    //comparing files and removing duplicates and files with same data
    cout << "Removing duplicates...\n";
    int c = compareAndDelete(v);
    cout << endl << c << " files have been removed succesfully :)\n\n";

    return 0;
}

