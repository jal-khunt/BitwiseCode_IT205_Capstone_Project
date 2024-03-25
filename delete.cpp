#include <iostream>
#include "universal.cpp"
using namespace std;

void delete_entry(string spath, char input[]){

    ifstream file(input);
    
    ofstream out("newfile.txt");

    if(!file.is_open()){
        cout << "Error opening input file\n";
        return;
    }

    string s;
    while(getline(file, s)){
        if(!s.find(spath)){
            cout << "Entry Found!\n";
        }
        else out << s << endl;
    }
    remove(input);
    rename("newfile.txt", input);

    file.close();
    out.close();
}

void delete_file(string file_to_be_deleted, string input){

    char f[file_to_be_deleted.size()+1];
    f[file_to_be_deleted.size()] = '\0';
    for(int i = 0; i < file_to_be_deleted.size(); i++){
        f[i] = file_to_be_deleted[i];
    }
    
    char input_const[input.size()+1];
    input_const[input.size()] = '\0';
    for(int i = 0; i < input.size(); i++){
        input_const[i] = input[i];
    }

    //delete from both file and folder, first search for file in input then delete entry then delete 
    delete_entry(f, input_const);
    ifstream del(file_to_be_deleted);
    
    if(del.is_open()) {
        del.close();
        remove(f);
    }
    else{
        cout << "File doesnt exist\nDeleted entry in input\n";
    }
}
