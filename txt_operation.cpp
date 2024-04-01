#include "universal"

void txt_op(vector<File> v){
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