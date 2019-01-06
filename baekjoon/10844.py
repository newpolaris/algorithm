# wotnek2's

import sys
T = int(sys.stdin.readline())

a = [0] + [1] * 9

for i in range(T-1):
    b = [0] * 10
    b[0] = a[1]
    b[9] = a[8]
    for j in range(1, 9):
        b[j] = a[j-1] + a[j+1]

    a = b
print(sum(a) % 1000000000)
