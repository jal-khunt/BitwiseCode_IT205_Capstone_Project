#include "universal.cpp"
using namespace std;

int main(){

    string s, txt = "txt", csv = "csv";
    cout << "Input file location: ";
    cin >> s;
    string file_extension = s.substr(s.length()-3, 3);
    vector<File> v = inputFile("input.txt");

    if(strcmp(file_extension, txt)){
        int sizeOfV = v.size();
        int i = 0;
        while(sizeOfV--){

            if(compare_months(v,i,8)){
                delete_File(v[i].path,i,v);
            }

            if(compareFile(v[i].path,i,v)){
                delete_File(v[i].path,i,v);
            }
            i++;
        }
    }
    else if(strcmp(file_extension, csv)){

    }
    else{
        cout << "Please ecnter valid .txt or .csv files\n";
    }

    //
    
    return 0;
}