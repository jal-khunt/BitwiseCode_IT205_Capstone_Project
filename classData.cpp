#include<iostream>
using namespace std;
#include <string>
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

int main(int argc, char const *argv[])
{
    Date d("25/12/2000");
    cout << d.date << "-" << d.mounth << "-" << d.year << endl;
    return 0;
}
