#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "classFile.cpp"
#include "delete.cpp"
using namespace std;
class File;

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
