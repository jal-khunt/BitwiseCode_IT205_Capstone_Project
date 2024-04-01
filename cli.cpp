#include "universal.cpp"

using namespace std;

int main(){
    string s;
    cout << "Input file location: ";
    cin >> s;
    cout << s[s.length()-1] << s[s.length()-2] << s[s.length()-3];
}