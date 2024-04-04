#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
/*
// Define the File structure
struct File {
    string path;
    string dateModified;
    int noOfTimeOpened;
};
*/
// Function to delete empty files
void deleteEmptyFiles(vector<File>& files) {
    for (size_t i = 0; i < files.size(); ++i) {
        ifstream file(files[i].path);
        if (file.peek() == ifstream::traits_type::eof()) { // Check if file is empty
            cout << "Deleting empty file: " << files[i].path << endl;
            file.close();
            // Implement delete_file function here
            // delete_file(files[i].path, i, files); // Call delete_file function to delete the empty file
        }
    }
}

/*
for jenish
In C++, ifstream::traits_type::eof() is a way to access the end-of-file (EOF) marker for the stream's character traits.
*/  

/*
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


int main() {
    vector<File> files = inputFile("input.txt");

    deleteEmptyFiles(files); // Delete empty files

    

    return 0;
}
