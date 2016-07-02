from itertools import combinations
import sys

sys.stdin = open("arctic.in")

for C in xrange(input()):
    N = int(input())
    P = [map(float, raw_input().split()) for _ in range(N)]
    W = [[0]*N for _ in range(N)] 
    for r, c in combinations(range(N), 2):
        W[r][c] = W[c][r] = (P[r][0]-P[c][0])**2 + (P[r][1]-P[c][1])**2
    # prim simple
    visited = set()
    dist = [1e200]*N
    dist[0] = 0
    for n in xrange(N):
        K = [i for i in range(0, N) if i not in visited]
        near = min(K, key=lambda p: dist[p])
        visited.add(near)
        K.remove(near)
        for k in K:
            dist[k] = min(W[near][k], dist[k])
    print('%.2f' %max(dist)**0.5)
