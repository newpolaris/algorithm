from bisect import bisect_left
from random import shuffle

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

for c in xrange(50):
    # n = input()
    # v = [map(int, raw_input().split()) for i in xrange(n)]
    xx = range(50000)
    yy = range(50000)
    shuffle(xx)
    shuffle(yy)
    v = zip(xx, yy)
    n = len(v)
    count = 0
    keys = []
    datas = []
    for i in v:
        count += insert(i[0], i[1])
    print(count)

