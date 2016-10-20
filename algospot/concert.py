def volume(idx, cur):
    if cur < 0 or cur > vm:
        return -1
    if idx >= n:
        return cur
    if cache[idx][cur] > -2:
        return cache[idx][cur]
    ret = max(volume(idx + 1, cur+a[idx]), volume(idx + 1, cur-a[idx]))
    cache[idx][cur] = ret
    return ret

for t in range(int(input())):
    n, vs, vm = map(int, input().split())
    a = list(map(int, input().split()))
    cache = [[-2 for x in range(vm+1)] for y in range(n)]
    print(volume(0, vs))
