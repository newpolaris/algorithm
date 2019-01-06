#include <iostream>
using namespace std;
int n, a, b;
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    while (n--) {
        cin >> a >> b;
        cout << a + b << '\n';
    }
}
