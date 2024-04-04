
#ifndef CLASSFILE_H
#define CLASSFILE_H


#include<iostream>
using namespace std;
#include <string>

class File{
    public:

    string path;
    string dateModified;
    int noOfTimeOpened;

    void print(){
        cout << path << "\t\t" << dateModified << "\t" << noOfTimeOpened << endl;
    }
};

#endif