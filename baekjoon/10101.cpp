#include <cstdio>
#include <numeric>

int main() {
    int a[3];
    scanf("%d %d %d", &a[0], &a[1], &a[2]); 
    if (std::accumulate(a, a+3, 0) != 180)
        printf("Error\n");
    else if (a[0] != a[1] && a[1] != a[2] && a[0] != a[2])
        printf("Scalene\n");
    else if (a[0] == a[1] && a[1] == a[2] && a[0] == a[2])
        printf("Equilateral");
    else 
        printf("Isosceles\n");
    return 0;
}
