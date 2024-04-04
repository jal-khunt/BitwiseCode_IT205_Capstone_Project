#include <iostream>
#include <vector>
#include <string>

#include "classFile.cpp"
//#include "compare_file_older_months.cpp"
#include "comparison.cpp"
using namespace std;

class File;

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
    cin >> s;
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

    //for(int i = 0; i < v.size(); i++) cout << v[i].path << " " << v[i].dateModified << " " << v[i].noOfTimeOpened << endl;

    cout << "File cleaner starting...\n\n";

    //month
    cout << "Removing Old Files..\nRemove files older than (in months): ";
    int months;
    cin >> months;
    cout << "Removing files older than " << months << " months.";
    //compare_months(v, month);
    cout << endl << endl;

    //comparing files and removing duplicates and files with same data

    cout << "Removing duplicates and empty files...\n";
    int c = compareAndDelete(v);
    cout << c << " files have been removed succesfully :)\n\n";

    //





    
    return 0;
}

