#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "classFile.cpp" // Include the header file or definition of File class
#include "delete.cpp"
#include "inputFile.cpp"

using namespace std;

// Function to compare files
bool compareFiles(const string& filePath1, const string& filePath2) {
    ifstream file1(filePath1);
    ifstream file2(filePath2);

    if (!file1 || !file2) {
        cerr << "Error opening files." << endl;
        return false;
    }

    string line1, line2;

    while (getline(file1, line1) && getline(file2, line2)) {
        if (line1 != line2) {
            return false;
        }
    }

    return (!file1.eof() || !file2.eof());
}

/*
void compareOneToAnother(string input,int i, vector<File> v){
    bool allFilesEqual = true;
        for(int j = i + 1;j < v.size(); j++){
            if (!compareFiles(v[i].path, v[j].path)) {
                cout << "Files are not equal." << endl;
                allFilesEqual = false;
            } else {
                cout << "Files are equal." << endl;
                delete_file(v[j].path, input);
            }
        }
}
*/


int main() {
    string inputFilePath = "input.txt"; // Path to input file
    vector<File> files = inputFile(inputFilePath); // Read input file and get vector of File objects

    bool allFilesEqual = true;

    for (size_t i = 0; i < files.size(); ++i) {
        for (size_t j = i + 1; j < files.size(); ++j) {
            cout << "Comparing " << files[i].name << " and " << files[j].name << ": ";
            if (!compareFiles(files[i].path, files[j].path)) {
                cout << "Files are not equal." << endl;
                allFilesEqual = false;
            } else {
                cout << "Files are equal." << endl;
                // Delete one of the files
                delete_file(files[j].path, files);
            }
        }
    }

    if (allFilesEqual) {
        cout << "All files are equal." << endl;
    } else {
        cout << "Some files are not equal." << endl;
    }

    return 0;
}
