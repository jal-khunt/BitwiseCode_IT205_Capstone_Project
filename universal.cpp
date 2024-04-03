#include<bits/stdc++.h>
#include <fstream>
#include <string>
#include "classFile.cpp"
#include "inputFile.cpp"
#include "comparaison.cpp"
#include "compare_file_older_months.cpp" 
#include "delete.cpp"

int strcmp(string s1, string s2){
    if(s1.length() != s2.length()){
        return 0;
    }

    for(int i = 0; i < s1.length(); i++){
        if(s1[i] != s2[i]) return 0;
    }
    return 1;
}
