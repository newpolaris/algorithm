# f = open("allergy.in")
# input = f.readline


# 음식을 먹을 수 있는 친구의 인덱스를 반환
def getEator(friends):
    names = input().split()[1:]
    return [friends.index(name) for name in names]


# 친구별 먹을 수 있는 음식의 인덱스를 반환
def getEatable(eaters):
    canEat = [[] for _ in range(n)]
    for i in range(len(eaters)):
        for food in eaters[i]:
            canEat[food].append(i)
    return canEat


def search(chosen, edible):
    global best
    if chosen >= best:
        return
    first = 0
    # 아직 먹을 음식이 없는 첫 번째 친구를 찾는다
    while first < n and edible[friendList[first]] > 0:
        first += 1
    if first == n:
        best = chosen
        return
    first = friendList[first]
    for food in canEat[first]:
        for i in eaters[food]:
            edible[i] += 1
        search(chosen+1, edible)
        for i in eaters[food]:
            edible[i] -= 1


for case in range(int(input())):
    n, m = map(int, input().split())
    friends = input().split()
    # eaters[i]: i번 음식을 먹을 수 있는 친구들의 집합
    eaters = [getEator(friends) for _ in range(m)]
    # canEat[i]: i번 친구가 먹을 수 있는 음식의 집합
    canEat = getEatable(eaters)
    # 먹을 수 있는 음식의 종류가 적은 친구 부터 정렬한 리스트
    friendList = [len(eat) for eat in canEat]
    friendList = sorted(range(n), key=lambda k: friendList[k])
    best = m
    search(0, [0]*n)
    print(best)
