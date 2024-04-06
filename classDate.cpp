#ifndef CLASSDATE_H
#define CLASSDATE_H

#include<iostream>
using namespace std;
#include <vector>
#include <string>
#include "classFile.cpp"
#include "delete.cpp"


class Date{
    public:
    int date;
    int mounth;
    int year;

    Date(string DateConvert){
        int x = (DateConvert[0]-'0')*10;
        int y = DateConvert[1]-'0';

        date = x+y;

        x = (DateConvert[3]-'0')*10;
        y = DateConvert[4]-'0';

        mounth = x+y;

        x = (DateConvert[6]-'0')*1000;
        y = (DateConvert[7]-'0')*100;
        int z = (DateConvert[8]-'0')*10;
        int a = (DateConvert[9]-'0')*1;

        year = x + y + z + a;
    }


};

//return difference in days
//dM = today, dT = file created date
//Time Complexity->O(1)     Space Complexity->O(1)
int dateComparison(Date dM,Date dT){

    if(dM.mounth == dT.mounth && dM.year == dT.year){
        return 0;
    }

    else if(dM.year == dT.year){


        if(dT.date > dM.date){
            return dT.mounth - dM.mounth;
        }


        else if(dT.date < dM.date){
            return dT.mounth - dM.mounth-1;
        }


    }

    else{


        if(dT.mounth>dM.mounth){
            int yearMounth = (dT.year - dM.year)*12;
            int mountMounth ;
            if(dT.date > dM.date){
                mountMounth = dT.mounth - dM.mounth;
            }
            else if(dT.date < dM.date){
                mountMounth = dT.mounth - dM.mounth-1;
            }
        return yearMounth + mountMounth;
        }


        else if(dT.mounth<dM.mounth){
            int yearMounth = (dT.year - dM.year - 1)*12;
            int mountMounth ;
            if(dT.date > dM.date){
                mountMounth = dT.mounth + (12 - dM.mounth);
            }
            else if(dT.date < dM.date){
                mountMounth = dT.mounth + (12 - dM.mounth) - 1;
            }
            return yearMounth + mountMounth;
        }
    }
    return 0;
}


int compare_month(vector<File> &v,int month, string todaysDate){
    int count = 0;
    Date todayDateObj(todaysDate);

    for(int i = 0; i < v.size(); i++){
        Date lastModifidedDateObj(v[i].dateModified);

        int diffMonth = dateComparison(lastModifidedDateObj,todayDateObj);
        cout << diffMonth << " " << v[i].path << endl;
        
        if(diffMonth >= month){
            if(delete_file(v[i].path,i,v)){
                i--;
                count++;
            }
        }
    }

    return count;

}


#endif