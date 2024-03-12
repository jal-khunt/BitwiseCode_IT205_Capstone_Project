#include <iostream>
#include <boost/filesystem.hpp>
#include <string>
using namespace std;
using namespace boost::filesystem;

int main() {

    path filePath;
    cin >> filePath;

    if (!exists(filePath)) {
        cout << "not exist :(\n";
        return 0;
    }

    time_t lastModified = last_write_time(filePath);
    string timeString = asctime(localtime(&lastModified));
    
    cout << "Last modified time of " << filePath << " is: " << timeString << endl;
    return 0;
}
