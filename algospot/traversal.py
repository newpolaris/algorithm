def traversal(pre, ino):
    if pre.empty():
        return []
    d = ino.index(pre[0])
    traversal(pre[1:d], ino[:d])
    traversal(pre[d+1:], ino[d+1:])

    print(pre[0] + " ")

for i in xrange(input()):
    n = input()
    pre = [map(int, raw_input().split())]
    ino = [map(int, raw_input().split())]
    traversal(pre, ino)
