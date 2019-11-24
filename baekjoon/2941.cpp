#include <iostream>
#include <string>
using namespace std;
int main() {
    string line, pattern[] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
    cin >> line;
    int p = 0, c = 0, n = line.size();
    while (p < n) {
        bool match = false;
        for (auto pa : pattern) {
            int k = pa.size();
            if (n - p - k < 0) continue;
            if (pa == line.substr(p, k)) {
                p += pa.size();
                match = true;
                break;
            }
        }
        if (!match)
            p += 1;
        c++;
    }
    cout << c << endl;
    return 0;
}
