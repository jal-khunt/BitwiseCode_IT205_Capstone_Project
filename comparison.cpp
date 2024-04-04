#include<iostream>
#include<vector>
#include <string>
#include <fstream>

#include "classFile.cpp"
#include "delete.cpp"
#include "inputFile.cpp"


// Function to compare files

bool compareFiles(const string& filePath1, const string& filePath2) {
    ifstream file1(filePath1);
    ifstream file2(filePath2);

    if (!file1 || !file2) {
        cerr << "Error opening files." << endl;
        return false;
    }

    string content1((istreambuf_iterator<char>(file1)), istreambuf_iterator<char>());
    string content2((istreambuf_iterator<char>(file2)), istreambuf_iterator<char>());
    return (content1==content2);
}

/*
// Function to delete file
void delete_file(const string& file_to_be_deleted, vector<File>& files, size_t index) {
    char f[file_to_be_deleted.size() + 1];
    f[file_to_be_deleted.size()] = '\0';
    for (size_t i = 0; i < file_to_be_deleted.size(); i++) {
        f[i] = file_to_be_deleted[i];
    }

    ifstream del(file_to_be_deleted);

    if (del.is_open()) {
        del.close();

        if (index < files.size()) {
            files.erase(files.begin() + index);
        } else {
            cout << "Invalid index" << endl;
            return;
        }
        remove(f);
    } else {
        cout << "File doesn't exist\n";
    }
}

// Function to read input file and create vector of File objects
vector<File> inputFile(const string& input) {
    string pathOfFile, lastModifiedDate;
    int accessedNumber;
    vector<File> v;
    ifstream MyReadFile(input);

    while (MyReadFile >> pathOfFile >> lastModifiedDate >> accessedNumber) {
        File f;
        f.path = pathOfFile;
        f.dateModified = lastModifiedDate;
        f.noOfTimeOpened = accessedNumber;
        v.push_back(f);
    }

    MyReadFile.close();
    return v;
}
*/

/*
optional can be use by making changes in the main function  
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
