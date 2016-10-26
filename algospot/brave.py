import sys

input = sys.stdin.readline


class DisjointSet:
    def __init__(self, n):
        self.rank = [0]*n
        self.parent = [i for i in range(n)]
        self.size = [1]*n

    def merge(self, p, q):
        p, q = self.find(p), self.find(q)
        if p == q:
            return self.size[p]
        if self.rank[p] > self.rank[q]:
            p, q = q, p
        self.parent[p] = q
        self.size[q] += self.size[p]
        if self.rank[p] == self.rank[q]:
            self.rank[q] += 1
        return self.size[q]

    def find(self, p):
        if self.parent[p] != p:
            self.parent[p] = self.find(self.parent[p])
        return self.parent[p]


def group(a, b):
    return s.merge(a, b)


for t in range(int(input())):
    n, m = map(int, input().split())
    s = DisjointSet(n)
    l = [list(map(int, input().split())) for i in range(m)]
    print(max(group(k[0] - 1, k[1] - 1) for k in l))
