#include<bits/stdc++.h>

#include <fstream>
#include <string>
#include "claasFile.cpp"
#include "inputFile.cpp"

using namespace std;

int main(){

    vector<File> v = inputFile("input.txt");
    
    cout << v[0].noOfTimeOpened << endl;


    // Close the file
    return 0;
}