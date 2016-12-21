def rotate(block):
    return list(zip(*reversed(block)))


def transpose(block):
    return list(zip(*block))


def binarize(cell):
    return cell > 0


def revert_rotate(t):
    i, j, c = t
    return (N-i, N-j, 0, c)


def revert_transpose(t):
    i, j, c = t
    return (N-j, N-i, 1, c)


def get_hint(block):
    for i, row in enumerate(block):
        add = 0
        for j, c in enumerate(row):
            add += c
            if c == 0:
                if add > 0:
                    yield (i, j, add)
                add = 0

T = int(input())
print(T)
for t in range(T):
    N = int(input())
    board = [list(map(int, input().split())) for _ in range(N)]

    # 180 deg rototation
    rotated = rotate(rotate(board))
    transposed = transpose(rotated)

    binary = [list(map(binarize, row)) for row in board]
    hint = list(map(revert_rotate, [t for t in get_hint(rotated)]))
    hint += list(map(revert_transpose, [t for t in get_hint(transposed)]))
    hint.sort(key=lambda x: (x[2], x[0], x[1]))

    print(N)
    for row in binary:
        for c in row:
            print(1 if c else 0, end=" ")
        print()
    print(len(hint))
    for i, j, d, v in hint:
        print(i, j, d, v)
