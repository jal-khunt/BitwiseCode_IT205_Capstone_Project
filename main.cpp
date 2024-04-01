#include<bits/stdc++.h>
#include <fstream>
#include <string>
#include "classFile.cpp"
#include "inputFile.cpp"
#include "comparation.cpp"
#include "compare_file_older_months.cpp" 
#include "delete.cpp"
using namespace std;

int main(){

    vector<File> v = inputFile("input.txt");
    
    int sizeOfV = v.size();
    int i = 0;
    while(sizeOfV--){

        if(compare_months(v,i,8)){
            delete_File(v[i].path,i,v);
        }

        if(compareFile(v[i].path,i,v)){
            delete_File(v[i].path,i,v);
        }
        i++;
    }
    return 0;
}