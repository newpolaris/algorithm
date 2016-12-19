# f = open("boardcover2.in")
# input = f.readline
input = raw_input

def rotate(A):
    B = [[0]*len(A) for _ in range(len(A[0]))]
    for i in range(len(A)):
        for j in range(len(A[0])):
            B[j][len(A)-i-1] = A[i][j]
    return B


def generateRotations(block):
    rots = []
    for r in range(4):
        oy, ox = -1, -1
        rotation = []
        for i in range(len(block)):
            for j in range(len(block[i])):
                if block[i][j] == 1:
                    if oy == -1:
                        oy, ox = i, j
                    rotation.append((i-oy, j-ox))
        rots.append(rotation)
        block = rotate(block)
    unique = []
    [unique.append(item) for item in rots if item not in unique]
    return unique, len(unique[0])


def Set(y, x, rot, add):
    bSuc = True
    for t in rot:
        r, c = t
        r += y
        c += x
        if 0 <= r < R and 0 <= c < C:
            Board[r][c] += add
            if Board[r][c] > 1:
                bSuc = False
        else:
            bSuc = False
            break
    return bSuc


def search(placed, used):
    global best
    remain = Blanks - (used + placed*blockSize)
    if remain//blockSize + placed <= best:
        return
    y, x = -1, -1
    for i in range(R):
        for j in range(C):
            if Board[i][j] == 0:
                y, x = i, j
                break
        if y != -1:
            break
    if y == -1:
        best = max(best, placed)
        return
    for rot in rotations:
        if Set(y, x, rot, 1):
            search(placed+1, used)
        Set(y, x, rot, -1)
    Board[y][x] = 1
    search(placed, used+1)
    Board[y][x] = 0
    return placed


for case in range(int(input())):
    R, C, BR, BC = map(int, input().split())
    Board = [[1 if c == '#' else 0 for c in input()] for r in range(R)]
    Block = [[1 if c == '#' else 0 for c in input()] for r in range(BR)]
    Blanks = R*C - sum([sum(line) for line in Board])
    rotations, blockSize = generateRotations(Block)
    best = 0
    search(0, 0)
    print(best)
