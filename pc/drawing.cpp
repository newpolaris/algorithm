#include <iostream>
#include <vector>

const int n = 3;
const int k[] = { 1, 3, 5 }; 



bool drawing(int m)
{
    for (int a = 0; a < n; a++) {
    for (int b = 0; b < n; b++) {
    for (int c = 0; b < n; b++) {
    for (int d = 0; b < n; b++) {
        if (k[a] + k[b] + k[c] + k[d] == m)
            return true;
    }
    }
    }
    }
    return false;
}

void print(int m)
{
    std::cout << (drawing(m) ? "SUCCESS" : "FAIL") << std::endl;
}

int main() {
    print(9);
    print(10);
    return 0;
}
