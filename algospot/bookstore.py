for c in range(int(input())):
    n, m = map(int, input().split())
    a = [list(map(int, input().split())) for _ in range(n)]
    d = [[0]*n for _ in range(m)]
    for s in range(m):
        for b in range(n):
            d[s][b] = (a[b][s*2], a[b][s*2+1])
    for s in range(m):
        d[s].sort(key=lambda x: (-x[1], x[0]))
    price = 10000*n
    for s in range(m):
        p = 0
        point = 0
        for b in range(n):
            saleprice = max(d[s][b][0] - point, 0)
            p = p + saleprice
            point = d[s][b][1] + (point - min(d[s][b][0], point))
        price = min(price, max(p, 0))
    print(price)
