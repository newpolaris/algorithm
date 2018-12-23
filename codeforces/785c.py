(n, m) = map(int, input().split())
lo = m
hi = n
while lo < hi:
    a = lo + (hi - lo) // 2
    p = a - 1
    k = n - (p - m + 1)*(m + p)//2 + (p - m + 1)*m
    if k - a <= 0:
        hi = a
    else:
        lo = a + 1
print(min(lo, n))
