# f = open("boardcover2.in")
# input = f.readline
# input = raw_input


def rotate(block):
    return zip(*reversed(block))


def relativeize(block):
    basei = basej = -1
    ret = []
    for i, row in enumerate(block):
        for j, cell in enumerate(row):
            if cell == 1:
                if basei == -1:
                    basei, basej = i, j
                ret.append((i-basei, j-basej))
    return ret


def place_block(i, j, rot, add):
    bSuc = True
    for di, dj in rot:
        if 0 <= di+i < R and 0 <= dj+j < C:
            board[di+i][dj+j] += add
            if board[di+i][dj+j] > 1:
                bSuc = False
        else:
            bSuc = False
            break
    return bSuc


def search(placed, blanks):
    global best
    if blanks / blocksize + placed <= best:
        return

    for i in range(R):
        for j in range(C):
            if board[i][j] == 0:
                break
        else:
            continue
        break
    else:
        best = max(best, placed)
        return

    for rot in rotations:
        if place_block(i, j, rot, 1):
            search(placed+1, blanks - blocksize)
        place_block(i, j, rot, -1)

    board[i][j] = 1
    search(placed, blanks - 1)
    board[i][j] = 0


def binarize(cell):
    return 1 if cell == '#' else 0

for case in range(int(input())):
    R, C, BR, BC = map(int, input().split())
    board = [list(map(binarize, input())) for r in range(R)]
    block = [list(map(binarize, input())) for r in range(BR)]

    rotations = []
    for r in range(4):
        rot = relativeize(block)
        if rot not in rotations:
            rotations.append(rot)
        block = list(rotate(block))

    best = 0
    blanks = R*C - sum(sum(line) for line in board)
    blocksize = len(rotations[0])

    search(0, blanks)
    print(best)
