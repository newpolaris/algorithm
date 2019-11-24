// https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/
// https://codeforces.com/blog/entry/14516
#include <map>
#include <iostream>
using namespace std;
#define long long long
const long M = 1'000'000;
map<long, long> F;

long f(long n) {
    if (F.count(n)) return F[n];
    long k = n/2;
    if (n % 2 == 0) { // n = 2*k
        return F[n] = (f(k)*f(k) + f(k-1)*f(k-1)) % M;
    } else { // n = 2*k + 1
        return F[n] = (f(k)*f(k+1) + f(k-1)*f(k)) % M;
    }
}

int main() {
    long n;
    F[0] = F[1] = 1;
    cin >> n;
    cout << (n == 0 ? 0 : f(n - 1)) << endl;
}
