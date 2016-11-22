from itertools import combinations
import sys


input = sys.stdin.readline

for cese in range(int(input())):
    n, m = map(int, input().split())
    x = list(map(int, input().split()))
    y = list(map(int, input().split()))
    adj = [[0]*n for _ in range(n)]
    for i, j in combinations(range(n), 2):
        adj[i][j] = adj[j][i] = (x[i]-x[j])**2 + (y[i]-y[j])**2
    for _ in range(m):
        a, b = map(int, input().split())
        adj[a][b] = adj[b][a] = 0
    minWeight = [1e10]*n
    dist = minWeight[0] = 0.0
    added = [False]*n
    for _ in range(n):
        u = -1
        for i in range(n):
            if not added[i] and (u == -1 or minWeight[u] > minWeight[i]):
                u = i
        added[u] = True
        dist += minWeight[u] ** 0.5
        for i in range(n):
            if not added[i] and adj[u][i] < minWeight[i]:
                minWeight[i] = adj[u][i]
    print(dist)
