#include<bits/stdc++.h>

#include <fstream>
#include <string>
#include "classFile.cpp"
#include "inputFile.cpp"
#include"comparation.cpp"
using namespace std;

int main(){

    vector<File> v = inputFile("input.txt");
    
    int sizeOfV = v.size();
    int i = 0;
    while(sizeOfV--){
        // cout << v[i].path << endl;

        if(checkFileCopy(string,v,i)){
            detleFile(string)
        }
        // cout << 1 << endl;
        i++;
    }
    // cout << v[0].noOfTimeOpened << endl;


    // Close the file
    return 0;
}