from functools import lru_cache
import random 

@lru_cache(maxsize=None)
def maxx(l, r):
    if l == r:
        return H[l]
    mid = (l+r)//2
    return max(maxx(l, mid), maxx(mid+1, r))


@lru_cache(maxsize=None)
def minn(l, r):
    if l == r:
        return H[l]
    mid = (l+r)//2
    return min(minn(l, mid), minn(mid+1, r))

for c in range(5):
    N, Q = 10000, 10000
    H = [random.randint(1, 20000) for r in range(N)]
    for _ in range(Q):
        l, r = [random.randint(0, N-1) for i in range(2)]
        if l > r:
            l, r = r, l
        maxx(l, r) - minn(l, r)
    print(minn.cache_info())
    print(maxx.cache_info())
    minn.cache_clear()
    maxx.cache_clear()

