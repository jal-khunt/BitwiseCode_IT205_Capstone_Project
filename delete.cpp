#ifndef DELETE_H
#define DELETE_H

#include <iostream>
using namespace std;

/*
use delete_file function:
input:
    (string) file to be deleted, (string) input
output:
    void
*/


int delete_file(string file_to_be_deleted, int index, vector<File> &F){

    char f[file_to_be_deleted.size()+1];
    f[file_to_be_deleted.size()] = '\0';
    for(int i = 0; i < file_to_be_deleted.size(); i++){
        f[i] = file_to_be_deleted[i];
    }
    
    ifstream del(file_to_be_deleted);
    
    if(del.is_open()) {
        del.close();
        
        if (index < 0 || index >= F.size()) {
            cout << "Invalid index" <<endl;
        }else{
            F.erase(F.begin() + index);
            remove(f);
            return 1;
        }
    }
    else{
        cout << "File doesnt exist\n";
        return 0;
    }
    return 0;
}

#endif