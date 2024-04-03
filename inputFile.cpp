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

int str_int(string str){
    int sum = 0;
    for(int i = 0; i < str.size(); i++){
        sum *= 10;
        sum += str[i] - '0';
    }
    return sum;
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
        int c1, c2, ln = line.size();
        if(ln <= 0) break;
        for(c1 = 0; line[c1] != ',' && c1 < ln-1; c1++);
        for(c2 = c1+1; line[c2] != ',' && c2 < ln-1; c2++);

        f.path = line.substr(0, c1);
        f.dateModified = line.substr(c1+1, c2-c1-1);
        f.noOfTimeOpened = str_int(line.substr(c2+1));
        i++;
        v.push_back(f);
    }
    MyReadFile.close();
    return v;

}