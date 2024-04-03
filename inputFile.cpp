#include<vector> 
#include<string>
#include <sstream>
#include<fstream>
using namespace std;
#include "classFile.cpp"

vector<File> inputFileTXT(string input){

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

vector<File> inputFileCSV(string input){

    string pathOfFile,lastModifiedDate;
    int accessedNumber;
    vector<File> v;
    ifstream MyReadFile(input);
    int i = 0;

    while (MyReadFile.eof()==0) {
        
        File f;
        string line;
        MyReadFile >> line;
        char c[line.size()];
        c[line.size()-1] = '\0';
        for(int i = 0; i < line.size(); i++) c[i] = line[i];
        
        sscanf(c, "%s,%s,%s", f.path, f.dateModified, f.noOfTimeOpened);
        cout << f.path << " " << f.dateModified << " " << f.noOfTimeOpened << endl;
        i++;
        v.push_back(f);
    }
    MyReadFile.close();
    return v;

}