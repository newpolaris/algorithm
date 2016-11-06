def bfs():
    queue = []
    queue.append((0, 0))
    while queue:
        q = queue.pop(0)
        for d in digit:
            t = q[0] * 10 + d
            # 나누는 수가 n 이므로 여기서 체크해도 됨!
            if t >= n:
                r = t % n + n
            else:
                r = t % n
            num = q[1] * 10 + d
            if r == n+m:
                return num
            # 2 layer 구조를 꾸며야 한다. 갔던 노드 또 간다면 comp 대폭 증가임
            if not discovered[r]:
                discovered[r] = True
                queue.append((r, num))
    return -1


for c in range(int(input())):
    d, n, m = input().split()
    n, m = map(int, [n, m])
    # 사전순으로 가장 먼저 있는 걸 찾기 위해
    digit = sorted(list(map(int, list(d))))
    discovered = [False] * (2*n)
    ans = bfs()
    if ans > 0:
        print(ans)
    else:
        print("IMPOSSIBLE")
