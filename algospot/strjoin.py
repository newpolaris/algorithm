from heapq import heapify, heappop, heappush


for case in range(int(input())):
    input()
    h = list(map(int, input().split()))
    heapify(h)
    t = 0
    while len(h) > 1:
        a, b = heappop(h), heappop(h)
        t += a + b
        heappush(h, a + b)
    print(t)
