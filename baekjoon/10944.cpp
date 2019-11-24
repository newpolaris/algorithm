#include <random>
#include <iostream>
using namespace std;
int main() {
    random_device rd;
    mt19937 eng(rd());
    uniform_int_distribution<int> dist(0, 10'000);
    cout << dist(eng) << endl;

}
