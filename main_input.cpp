#include <iostream>
#include <vector>
#include <string>

#include "inputFile.cpp"
#include "classFile.cpp"
using namespace std;

int strcmp(string s1, string s2){
    if(s1.length() != s2.length()){
        return 0;
    }

    for(int i = 0; i < s1.length(); i++){
        if(s1[i] != s2[i]) return 0;
    }
    return 1;
}

int input_parser(vector<File> &v, string s){
    string txt = "txt", csv = "csv", xls = "xls";

    string file_extension = s.substr(s.length()-3, 3);

        if(strcmp(file_extension, txt)){
            v = inputFileTXT(s);
        }
        else if(strcmp(file_extension, csv)){
            v = inputFileCSV(s);
        }
        else if(strcmp(file_extension, xls)){
            ;
        }
        else{
            cout << "Please enter valid .txt or .csv files\n";
            return 0;
        }
}