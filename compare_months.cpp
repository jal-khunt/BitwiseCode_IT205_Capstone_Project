#include <iostream>
#include <string>
#include <vector>
#include "classDate.cpp"
#include "delete.cpp"


class File;
using namespace std;

/*
bool compare_different(int i, vector<File> &v, int month, string todaysDate)
{
    Date currDate(todaysDate);
    Date fileDate(v[i].dateModified);

    int months_diff;

    if (currDate.year == fileDate.year) {

        if (currDate.mounth == fileDate.mounth) {
            months_diff = 0;
            months_diff += (currDate.date - fileDate.date) > 0 ? 1 : 0;
            months_diff = currDate.mounth - fileDate.mounth - 1;
            months_diff += (currDate.date >= fileDate.date) ? 1 : 0; 
        }
    } 
    else {
        months_diff = (currDate.year - fileDate.year - 1) * 12;
        months_diff += (12 - fileDate.mounth) + currDate.mounth;
        months_diff += (currDate.date >= fileDate.date) ? 1 : 0; 

    }
    cout << months_diff << endl;

    if(months_diff >= month)
        return true;

    return false;
}
*/

int compare_months(vector<File> &v, int month, string date){
    int count = 0;
    for(int i = 0; i < v.size(); i++){
        if(compare_different(i, v, month, date)){
            cout << endl << v[i].path << " ";
        }
    }
    return count;
}