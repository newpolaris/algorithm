# fleo0917's answer
for case in range(int(input())):
    N, M = map(int, input().split())
    D = {}
    for _ in range(N):
        w, p = input().split()
        for i in range(1, len(w)+1):
            D[w[:i]] = min(D.get(w[:i], (0, '')), (-int(p), w))

    words = input().split()
    cnt = len(words) - 1
    for w in words:
        if w not in D:
            cnt += len(w)
            continue
        for i in range(1, len(w)):
            if D[w[:i]][1] == w:
                cnt += i+1
                break
        else:
            cnt += len(w)
    print(cnt)
