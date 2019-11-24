#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
#ifdef _DEBUG
    freopen("1181.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<string> word(n);
    for (auto& w : word)
        cin >> w;
    sort(word.begin(), word.end(), 
            [](auto& a, auto& b) {
                if (a.size() == b.size()) {
                    return a < b;
                }
                else 
                    return a.length() < b.length();
            });
    auto it = std::unique(word.begin(), word.end());
    word.erase(it, word.end());
    for (auto& w : word)
        cout << w << endl;
}
