//additinal feauture function will directly being called in main function 

#include<iostream>
#include<vector>
#include <string>
#include <fstream>

#include "classFile.cpp"
#include "delete.cpp"

using namespace std;

// Function to compare CSV files
// Time Complexity->O(m + n) where m and n are size of file
// Space Complexity->O(m + n) where m and n are size of file
bool compareCSVFiles(const string& filePath1, const string& filePath2) {
    ifstream file1(filePath1);
    ifstream file2(filePath2);

    if (!file1 || !file2) {
        cerr << "Error opening files." << endl;
        return false;
    }

    string line1, line2;

    // Read and compare line by line
    while (getline(file1, line1) && getline(file2, line2)) {
        if (line1 != line2) {
            return false; // Files are different
        }
    }

    // If one file has more lines than the other
    if (file1.eof() != file2.eof()) {
        return false; // Files are different
    }

    return true; // Files are identical
}

// Function to compare CSV files and delete duplicates
int compareAndDeleteCSV(vector<File>& files) {
    int count = 0;

    for (int i = 0; i < files.size(); ++i) {
        for (int j = i + 1; j < files.size(); ++j) {
            if (compareCSVFiles(files[i].path, files[j].path)) {
                // push file into the delete function
                int del = delete_file(files[j].path, j, files);
                if (del == 0) continue;
                count++;
                j--;
            }
        }
    }
    return count;
}
