import operator


for case in range(int(input())):
    input()
    m = map(int, input().split())
    e = map(int, input().split())
    me = sorted(zip(m, e), key=operator.itemgetter(1), reverse=True)
    total, current = 0, 0
    for m, e in me:
        current += m
        total = max(total, current + e)
    print(total)
