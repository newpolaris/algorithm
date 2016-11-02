from itertools import combinations, chain


def false(a):
    return a*2+1


def true(a):
    return a*2


def disjoint(m, a, b):
    m0, m1 = m[a], m[b]
    return m0[1] <= m1[0] or m1[1] <= m0[0]


def tarajanSCC(adj):
    st = []
    sccId = [-1] * len(adj)
    discovered = [-1] * len(adj)

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
        return ret

    for i in range(len(adj)):
        if discovered[i] == -1:
            scc(i)
    return sccId


def solve2SAT(adj):
    label = tarajanSCC(adj)
    n = len(label) // 2
    if any(a == b for a, b in zip(*[iter(label)]*2)):
        return None
    value = [-1] * n
    order = sorted([(-label[i], i) for i in range(2*n)])
    for i in range(2*n):
        vertex = order[i][1]
        variable, isTrue = vertex // 2, vertex % 2 == 0
        if value[variable] != -1:
            continue
        value[variable] = not isTrue
    return value


def makeGraph(m):
    adj = [[] for _ in range(len(m)*2)]
    for a, b in zip(*[iter(range(2*N))]*2):
        adj[false(a)].append(true(b))
        adj[false(b)].append(true(a))
    for a, b in combinations(range(2*N), 2):
        if not disjoint(m, a, b):
            adj[true(a)].append(false(b))
            adj[true(b)].append(false(a))
    return adj

for case in range(int(input())):
    N = int(input())
    times = (map(int, input().split()) for _ in range(N))
    meetings = list(zip(*[chain(*times)]*2))
    adj = makeGraph(meetings)
    sccCounter = vertexCounter = 0
    group = solve2SAT(adj)
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
