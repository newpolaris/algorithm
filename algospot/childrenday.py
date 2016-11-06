def bfs():
    queue = []
    queue.append((0, 0))
    while queue:
        q = queue.pop(0)
        for d in digit:
            # next layer 여부는 r 의 임시값으로 판단 가능 (q[0] * 10 + d)
            r = (q[0] * 10 + d) % n
            num = q[1] * 10 + d
            if r == m and num >= n + m:
                return num
            # 0 이 무한 반복 되는 현상 막기
            if num != q[1]:
                # bfs visited 방문 check 가 없으니 comp이 엄청 상승함
                queue.append((r, num))
    return -1


for c in range(int(input())):
    d, n, m = input().split()
    n, m = map(int, [n, m])
    digit = list(map(int, list(d)))
    ans = bfs()
    if ans > 0:
        print(ans)
    else:
        print("IMPOSSIBLE")
