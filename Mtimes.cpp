#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "classFile.cpp"
#include "delete.cpp"
// Time Complexity: O(n^2) in the worst-case scenario, where n is the number of files in the input vector. This is because potentially all files could be deleted, and each deletion could take O(n) time.
// Space Complexity: O(1), as the function uses a constant amount of additional space regardless of the input vector size.
int lessThanMTimes(vector<File> &v, int m){
    int count = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i].noOfTimeOpened < m){
            delete_file(v[i].path,i,v);
            count++;
            i--;
        }
    }
    return count;
}