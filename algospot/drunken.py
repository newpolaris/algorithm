def minimize(ab, ak, kb, d):
    akb_sum = ak[0]+kb[0]
    akb_max_delay = max(ak[1], kb[1], d)
    t0 = ab[0]+ab[1]
    t1 = akb_sum+akb_max_delay
    if t0 > t1 or (t0 == t1 and akb_max_delay >= ab[1]):
        return (akb_sum, akb_max_delay)
    else:
        return ab

v, e = map(int, input().split())
delay = list(map(int, input().split()))
inf = 1e10
adj = [[inf for _ in range(v)] for _ in range(v)]
for _ in range(e):
    a, b, c = map(int, input().split())
    adj[a-1][b-1] = c
    adj[b-1][a-1] = c
cost = [[(inf, 0) for _ in range(v)] for _ in range(v)]
for i in range(v):
    for j in range(v):
        if i != j:
            cost[i][j] = (adj[i][j], 0)
        else:
            cost[i][j] = (0, 0)
for k in range(v):
    for i in range(v):
        for j in range(v):
            cost[i][j] = minimize(cost[i][j], cost[i][k], cost[k][j], delay[k])
for t in range(int(input())):
    a, b = map(int, input().split())
    print(sum(cost[a-1][b-1]))
