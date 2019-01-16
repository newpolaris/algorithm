n = int(input())
a = [list(map(int, input())) for _ in range(n)]
def f(x, y):
    if x < 0 or x >= n or y < 0 or y >= n or not a[x][y]:
        return 0
    a[x][y] = 0
    return f(x + 1, y) + f(x - 1, y) + f(x, y + 1) + f(x, y - 1) + 1
d = list()
for i in range(n):
    for j in range(n):
        if a[i][j]:
            d.append(f(i, j))
d.sort()
print(len(d))
print('\n'.join(map(str, d)))
