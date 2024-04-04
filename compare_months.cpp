#include <iostream>
#include <vector>
#include "classData.cpp"

class File;
using namespace std;

bool compare_months_diffrent(int i, vector<File> v, int month, string todaysDate)
{
    Date currDate(todaysDate);
    Date fileDate(v[i].dateModified);
}