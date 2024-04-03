#include<iostream>
#include<vector>
#include <string>
#include "classFile.cpp"

class File;

using namespace std;

// This function is for checking the file is older then user given month if it is then it returns true otherwise it returns false
bool compare_months( vector<File> v, int i, int month)
{
    // get the system time
    
    time_t tt;
    struct tm* ti;
    
    time(&tt);
    
    ti = localtime(&tt);

    // get the month and year in individual variables
    int current_year = ti->tm_year + 1900, current_month = ti->tm_mon + 1;

    // Extracting month and year from the file's last modified date
    stringstream ss(v[i].dateModified);

    // for saving the file's creation date 
    int file_year, file_month, file_day;

    // to discard '/' characters in the date format
    char discard;

    ss >> file_day >> discard >> file_month >> discard >> file_year;

    int months_diff;

    // Calculating the diffrence between the current date and file's last modified date 
    if (current_month < file_month) {
        months_diff = (current_year - file_year - 1) * 12 + (current_month + 12 - file_month);
    } else {
        months_diff = (current_year - file_year) * 12 + (current_month - file_month);
    }

    // if the difference in months is greater than or equal to the user given month value, return true
    if(months_diff >= month){
        return true;
    }

    // Otherwise, return false 
    return false;
}
