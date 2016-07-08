def read():
    k = map(float, raw_input().split())
    return list(zip(*[iter(k)]*2))

def low(hull):
    v = -1e20
    for h in hull:
         v = max(v, min(x for x, y in h))
    return v

def high(hull):
    v = 1e20
    for h in hull:
         v = min(v, max(x for x, y in h))
    return v

def between(a, b, x):
    x1, y1 = a
    x2, y2 = b
    return x1 <= x <= x2 or x2 <= x <= x1

def at(a, b, x):
    x1, y1 = a
    x2, y2 = b
    return y1 + (x-x1)*(y2-y1)/(x2-x1)

def vertical(x):
    minY = min(at(seg[0], seg[1], x) for seg in upper if between(seg[0], seg[1], x)) 
    maxY = max(at(seg[0], seg[1], x) for seg in lower if between(seg[0], seg[1], x)) 
    return minY - maxY

for C in xrange(input()):
    N, M = map(int, raw_input().split())
    hull = (read(), read())

    lower, upper = [], []
    for h in hull:
        for a, b in zip(h, h[1:]+h[:1]):
            if a[0] < b[0]:
                lower.append((a, b))
            elif a[0] > b[0]:
                upper.append((a, b))
    lo, hi = low(hull), high(hull)
    ans = 0
    if hi > lo:
        for i in range(100):
            a = (lo*2 + hi) / 3
            b = (lo + hi*2) / 3
            if vertical(a) < vertical(b):
                lo = a
            else:
                hi = b
        ans = max(0, vertical(lo))
    print(ans)
