#include <iostream>
using namespace std;
int main() {
    int N;
    string num;
    cin >> N >> num;
    int sum = 0;
    for (auto c : num) {
        sum += c - '0';
    }
    cout << sum << endl;
    return 0;
}
