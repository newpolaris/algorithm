def rotate(block):
    return list(zip(*reversed(block)))


def transpose(block):
    return list(zip(*block))


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

    print(N)
    print('\n'.join(' '.join(map(lambda c: '01'[c > 0], row)) for row in board))

    # 180 deg rototation
    rotated = rotate(rotate(board))
    transposed = transpose(rotated)

    hints = list(map(revert_rotate, [t for t in get_hint(rotated)]))
    hints += list(map(revert_transpose, [t for t in get_hint(transposed)]))

    hints.sort(key=lambda x: (x[2], x[0], x[1]))

    print(len(hints))
    for i, j, d, v in hints:
        print(i, j, d, v)
