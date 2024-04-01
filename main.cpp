#include "universal.cpp"
using namespace std;

int main(){

    string s, txt = "txt", csv = "csv";
    cout << "Input file location: ";
    cin >> s;
    string file_extension = s.substr(s.length()-3, 3);
    vector<File> v = inputFile("input.txt");

    if(strcmp(file_extension, txt)){

    }
    else if(strcmp(file_extension, csv)){

    }
    else{
        cout << "Please ecnter valid .txt or .csv files\n";
    }

    //
    
    return 0;
}