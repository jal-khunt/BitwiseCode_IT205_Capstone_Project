#include<iostream>
#include<vector>
#include <string>
#include <fstream>

#include "classFile.cpp"
#include "delete.cpp"


// Function to compare files

bool compareFiles(const string& filePath1, const string& filePath2) {
    ifstream file1(filePath1);
    ifstream file2(filePath2);

    if (!file1 || !file2) {
        //cout << filePath1 << " " << filePath2;
        cerr << "Error opening files." << endl;
        return false;
    }

    string content1((istreambuf_iterator<char>(file1)), istreambuf_iterator<char>());
    string content2((istreambuf_iterator<char>(file2)), istreambuf_iterator<char>());
    return (content1==content2);
}

// Function to compare files and delete duplicates
int compareAndDelete(vector<File>& files) {
    vector<int> index;
    int count = 0;

    for (int i = 0; i < files.size(); ++i) {
        for (int j = i + 1; j < files.size(); ++j) {

            if (compareFiles(files[i].path, files[j].path)) {
                // push file into the delete function
                delete_file(files[j].path, j, files);
                count++;
                j--;
            }
        }
    }
    return count;
}
