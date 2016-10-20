def volume(idx, cur):
    if cur < 0 or cur > vm:
        return -1
    if idx >= n:
        return cur
    key = (idx, cur)
    if key in cache:
        return cache[key]
    ret = max(volume(idx + 1, cur+a[idx]), volume(idx + 1, cur-a[idx]))
    cache[key] = ret
    return ret

for t in range(int(input())):
    n, vs, vm = map(int, input().split())
    a = list(map(int, input().split()))
    cache = {}
    print(volume(0, vs))
