from collections import defaultdict
from itertools import combinations


def false(a):
    return a*2+1


def true(a):
    return a*2


def disjoint(a, b):
    m0, m1 = meetings[a], meetings[b]
    return m0[1] <= m1[0] or m1[1] <= m0[0]


def scc(here):
    global vertexCounter, sccCounter
    vertexCounter += 1
    ret = discovered[here] = vertexCounter
    st.append(here)
    for there in adj[here]:
        if discovered[there] == -1:
            ret = min(ret, scc(there))
        elif sccId[there] == -1:
            ret = min(ret, discovered[there])
    if ret == discovered[here]:
        while True:
            t = st.pop()
            sccId[t] = sccCounter
            if t == here:
                break
        sccCounter += 1
    finish[here] = 1
    return ret


def solve2SAT(label):
    n = len(label) // 2
    for a, b in zip(*[iter(range(2*n))]*2):
        if label[a] == label[b]:
            return None
    value = [-1] * n
    order = sorted([(-label[i], i) for i in range(2*n)])
    for i in range(2*n):
        vertex = order[i][1]
        variable, isFalse = vertex // 2, vertex % 2
        if value[variable] != -1:
            continue
        value[variable] = isFalse
    return value


def makeGraph():
    adj = defaultdict(list)
    for a, b in zip(*[iter(range(N*2))]*2):
        adj[false(a)].append(true(b))
        adj[false(b)].append(true(a))
    for a, b in combinations(range(N*2), 2):
        if not disjoint(a, b):
            adj[true(a)].append(false(b))
            adj[true(b)].append(false(a))
    return adj

for case in range(int(input())):
    N = int(input())
    meetings = []
    for _ in range(N):
        aa, ab, ba, bb = map(int, input().split())
        meetings.append((aa, ab))
        meetings.append((ba, bb))
    adj = makeGraph()
    n4 = (4 * N)
    # target scc
    st = []
    sccId = [-1] * n4
    discovered = [-1] * n4
    finish = [0] * n4
    sccCounter = vertexCounter = 0
    for i in range(n4):
        if discovered[i] == -1:
            scc(i)
    group = solve2SAT(sccId)
    if group:
        print("POSSIBLE")
        for i in range(0, 2*N, 2):
            if group[i]:
                ans = meetings[i]
            else:
                ans = meetings[i+1]
            print(ans[0], ans[1])
    else:
        print("IMPOSSIBLE")
