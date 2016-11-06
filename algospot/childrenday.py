def bfs():
    queue = []
    queue.append((0, 0))
    while queue:
        q = queue.pop(0)
        for d in digit:
            t = q[0] * 10 + d
            if t >= n:
                r = t % n + n
            else:
                r = t % n
            num = q[1] * 10 + d
            if r == n+m:
                return num
            if not discovered[r]:
                discovered[r] = True
                queue.append((r, num))
    return -1


for c in range(int(input())):
    d, n, m = input().split()
    n, m = map(int, [n, m])
    digit = list(map(int, list(d)))
    discovered = [False] * (2*n)
    ans = bfs()
    if ans > 0:
        print(ans)
    else:
        print("IMPOSSIBLE")
