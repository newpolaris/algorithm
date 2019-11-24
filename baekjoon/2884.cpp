#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
#ifdef _DEBUG
#endif
    int h, m;
    cin >> h >> m;
    if (m < 45) {
        m += 15;
        h = ((h - 1) + 24) % 24;
    }
    else m -= 45;
    cout << h << " " << m << endl;
    return 0;
}
