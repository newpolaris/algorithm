from operator import itemgetter


def cost(store):
    cost, point = 0, 0
    for c, p in store:
        cost += c - min(c, point)
        point += p - min(c, point)
    return cost

for c in range(int(input())):
    n, m = map(int, input().split())
    stores = zip(*(zip(*[map(int, input().split())]*2) for _ in range(n)))
    stores = (sorted(s, key=itemgetter(1), reverse=True) for s in stores)
    print(min(map(cost, stores)))
