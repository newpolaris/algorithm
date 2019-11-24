#include <algorithm>
#include <cmath>
using namespace std;

class Solution{
public:
    double solution(int x1, int m1, int x2, int m2){
        int cnt = 1000;
        double l = x1, r = x2;
        while (cnt--) {
            double mid = double(l + r) / 2;
            double r1 = log(abs(mid - x1));
            double r2 = log(abs(mid - x2));
            double f1 = log(double(m1)) - r1*2;
            double f2 = log(double(m2)) - r2*2;
            if (f1 > f2) {
                l = mid;
            } else if (f1 < f2) {
                r = mid;
            }
        }
        return (l+r)/2;
    }
};

int main() {
    Solution sol;
    sol.solution(1, 1, 2, 1000);
    return 0;
}
