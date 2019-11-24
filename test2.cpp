#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int cache[51];

class Solution{
public:
    int knapsack(vector<int> w, vector<int> v, int K){
        int n = w.size();
        for (int k = 0; k <= 50; k++)
            cache[k] = -9999;
        cache[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int k = K; k > 0; k--) {
                int prev = k - w[i];
                if (prev >= 0 && cache[prev] >= 0) {
                    cache[k] = std::max(cache[k], cache[prev] + v[i]);
                }
            }   
        }
        return *max_element(cache, cache+K+1);
    }
};

int main() {
    Solution sol;
    vector<int> w = { 10, 20, 30 };
    vector<int> v = { 60, 100, 120 };
    int K = 50;
    cout << sol.knapsack(w, v, K) << endl;
    return 0;
}
