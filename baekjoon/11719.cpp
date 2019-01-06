#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    std::string str;
    while (getline(cin, str)) {
        cout << str << endl;
        if (cin.bad() || cin.eof())
            break;
    }
    return 0;
}
