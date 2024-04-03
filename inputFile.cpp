#include<vector> 
#include<string>
#include<fstream>
using namespace std;
#include "classFile.cpp"

vector<File> inputFile(string input){

    string pathOfFile,lastModifiedDate;
    int accessedNumber;
    vector<File> v;
    ifstream MyReadFile(input);
    int i = 0;

    while (MyReadFile.eof()==0) {
        
        File f;
        v.push_back(f);
        MyReadFile >> pathOfFile;
        v[i].path = pathOfFile;


        MyReadFile >> lastModifiedDate;
        v[i].dateModified = lastModifiedDate;

        MyReadFile >> accessedNumber;
        v[i].noOfTimeOpened = accessedNumber;
        i++;
    }
    MyReadFile.close();
    return v;

}

/*
// Function to read input file and create vector of File objects
vector<File> inputFile(const string& input) {
    string pathOfFile, lastModifiedDate;
    int accessedNumber;
    vector<File> v;
    ifstream MyReadFile(input);

    while (MyReadFile >> pathOfFile >> lastModifiedDate >> accessedNumber) {
        File f;
        f.path = pathOfFile;
        f.dateModified = lastModifiedDate;
        f.noOfTimeOpened = accessedNumber;
        v.push_back(f);
    }

    MyReadFile.close();
    return v;
}
*/