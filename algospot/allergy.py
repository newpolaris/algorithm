from collections import defaultdict


# f = open("allergy.in")
# input = f.readline


# 음식을 먹을 수 있는 친구의 인덱스를 반환
def getEator(friends):
    names = input().split()[1:]
    return [friends.index(name) for name in names]


def search(chosen, edible):
    global best
    if chosen >= best:
        return
    for i, ds in dishes:
        if edible[i] == 0:
            break
    else:
        best = chosen
        return
    for d in ds:
        for i in eaters[d]:
            edible[i] += 1
        search(chosen+1, edible)
        for i in eaters[d]:
            edible[i] -= 1


for case in range(int(input())):
    n, m = map(int, input().split())
    friends = input().split()
    # eaters[i]: i번 음식을 먹을 수 있는 친구들의 집합
    eaters = [getEator(friends) for _ in range(m)]
    # dishes[i]: i번 친구가 먹을 수 있는 음식의 집합
    dishes = defaultdict(list)
    for i, fs in enumerate(eaters):
        for f in fs:
            dishes[f].append(i)

    dishes = sorted(dishes.items(), key=lambda x: len(x[1]))

    best = m
    search(0, [0]*n)
    print(best)
