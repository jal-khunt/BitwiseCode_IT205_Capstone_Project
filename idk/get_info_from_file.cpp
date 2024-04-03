#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class fileInfo
{
    public :
        string path;
        string date;
        int no_opend;
    
    void display(vector<fileInfo> &v)
    {
        for(int i = 0; i < v.size(); i++){
            cout << "Path : " << v[i].path << endl;
            cout << "Date : " << v[i].date << endl;
            cout << "No times opend : " << v[i].no_opend << endl << endl;
        }
    }
};

int main()
{
    ifstream file("input.txt");
    fileInfo Cfile;
    
    vector<fileInfo> v;
    
    while(file >> Cfile.path >> Cfile.date >> Cfile.no_opend){
        v.push_back(Cfile);
    }
    
    Cfile.display(v);
    return 0;
}
