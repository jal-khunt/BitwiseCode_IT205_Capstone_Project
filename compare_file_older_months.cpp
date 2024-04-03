#include "universal.cpp"

class File;

using namespace std;

bool compare_months(string, vector<File> v, int i, int month)
{
    time_t tt;
    struct tm* ti;
    
    time(&tt);
    
    ti = localtime(&tt);

    int current_year = ti->tm_year + 1900, current_month = ti->tm_mon + 1;

    stringstream ss(v[i].dateModified);

    int file_year, file_month, file_day;
    char discard;

    ss >> file_day >> discard >> file_month >> discard >> file_year;

    int months_diff;
    if (current_month < file_month) {
        months_diff = (current_year - file_year - 1) * 12 + (current_month + 12 - file_month);
    } else {
        months_diff = (current_year - file_year) * 12 + (current_month - file_month);
    }

    if(months_diff >= month){
        return true;
    }

    return false;
}