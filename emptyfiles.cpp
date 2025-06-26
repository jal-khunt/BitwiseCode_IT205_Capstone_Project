#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "classFile.cpp"
#include "delete.cpp"
using namespace std;
class File;
//Time Complexity->O(n^2) where n is size of the vector if all files are emply
//Space Complexity->O(1)
int deleteEmptyFiles(vector<File>& files) {
    int count = 0;

    for (size_t i = 0; i < files.size(); ++i) {
        
        ifstream file(files[i].path);
        string s;
        file >> s;
        if (s.size() == 0) {
            file.close();
            int in = delete_file(files[i].path, i, files);
            count++;
            if(in == 0) continue;
            i--;
        }
    }

    return count;
}
