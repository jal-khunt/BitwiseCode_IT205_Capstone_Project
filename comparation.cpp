#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

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

int main() {
    vector<string> filePaths = {"D:/file1.txt", "D:/file2.txt", "D:/file3.txt"}; // Replace with the paths to your files

    bool allFilesEqual = true;

    for (size_t i = 0; i < filePaths.size(); ++i) {
        for (size_t j = i + 1; j < filePaths.size(); ++j) {
            cout << "Comparing " << filePaths[i] << " and " << filePaths[j] << ": ";
            if (!compareFiles(filePaths[i], filePaths[j])) {
                cout << "Files are not equal." << endl;
                allFilesEqual = false;
            } else {
                cout << "Files are equal." << endl;
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
