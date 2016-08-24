# http://www.grantjenks.com/docs/sortedcontainers/implementation.html
# The first is that Python lists are fast, really fast. 
# They have great characteristics for memory management and random access. 
# The second is that bisect.insort is fast. 
from bisect import bisect

for c in xrange(input()):
    n = input()
    count = 0
    keys = []
    datas = []
    for idx in xrange(n):
        k, d = map(int, raw_input().split())
        # to find i using bisect. make data array asceding sorted
        d = -d
        i = bisect(keys, k)
        if i == len(keys) or datas[i] > d:
            keys.insert(i, k)
            datas.insert(i, d)
        j = bisect(datas, d, 0, i)
        del keys[j:i]
        del datas[j:i]
        count += len(keys)
    print count
