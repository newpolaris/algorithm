from bisect import bisect_left

def insert_value(k, d):
    i = bisect_left(keys, k)
    keys.insert(i, k)
    datas.insert(i, d)
    return len(keys)

def insert(k, d):
    upper = bisect_left(keys, k)
    n = len(keys)
    if upper != n and d < datas[upper]:
        return n
    lower = upper
    while lower > 0:
        if datas[lower-1] > d:
            break
        lower -= 1
    del keys[lower:upper]
    del datas[lower:upper]
    insert_value(k, d)
    return len(keys)

for c in xrange(input()):
    n = input()
    count = 0
    keys = []
    datas = []
    for idx in xrange(n):
        p, q = map(int, raw_input().split())
        count += insert(p, q)
    print(count)
