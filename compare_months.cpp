#include <iostream>
#include <vector>
#include "classDate.cpp"
#include "delete.cpp"


class File;
using namespace std;


bool compare_different(int i, vector<File> v, int month, string todaysDate){
    Date currDate(todaysDate);
    Date fileDate(v[i].dateModified);

    int months_diff = 0;

    if (currDate.year == fileDate.year) {

        if (currDate.mounth == fileDate.mounth) {
            return(currDate.date > fileDate.date);
        }
        else{
            return (currDate.mounth > fileDate.mounth);
        }
    } 
    else {
        return(currDate.year > fileDate.year);
    }
        
}

int compare_months(vector<File> &v, int month, string today){
    int count = 0;
    for(int i = 0; i < v.size(); i++){
        if(compare_different(i, v, month, today)){
            int p = delete_file(v[i].path, i, v);
            if(p == 0) continue;
            count++;
            i--;
        }
    }
    return count;

}