#include <iostream>
#include "universal.cpp"
using namespace std;

void delete_entry(string spath, string input){
    ifstream file(input);
    char input_const[input.size()+1];
    input_const[input.size()] = '\0';
    for(int i = 0; i < input.size(); i++){
        input_const[i] = input[i];
    }
    ofstream out("newfile.txt");

    if(!file.is_open()){
        cout << "Error opening file\n";
        return;
    }
    string s;
    while(getline(file, s)){
        if(!s.find(spath)){
            cout << "found\n";
        }
        else out << s << endl;
    }
    remove(input_const);
    rename("newfile.txt", input_const);
}

void delete_file(string file_to_be_deleted, string input){
    string f = file_to_be_deleted;
    //delete from both file and folder, first search for file in input then delete entry then delete 
    delete_entry(f, input);
    
    for(int i = 0; i < f.size(); i++){
        //remove()
    }
}

int main(){
    cout << "\n\nstarting:\n";

    string c = "input.txt", f = "path3";
    delete_file(f, c);
    return 0;
}