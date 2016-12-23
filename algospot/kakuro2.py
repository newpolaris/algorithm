import sys
from functools import lru_cache

# f = open("kakuro2.in")
# input = f.readline


if sys.version_info[0] < 3:
    input = raw_input


MAX_SUM, MAX_L, MAX_VAL = 46, 10, 1024


@lru_cache(maxsize=None, typed=False)
def Sum(v):
    ret = 0
    for i in range(10+1):
        if v & (1 << i):
            ret += i
    return ret


@lru_cache(maxsize=None, typed=False)
def Length(v):
    return bin(v).count("1")


def fill_candidate(candidate):
    # for all possible bit fileld
    for v in range(0, MAX_VAL, 2):
        s, l = Sum(v), Length(v)
        subset = v
        # fill all possible subsets of bitset
        while True:
            candidate[l][s][subset] |= (v & ~subset)
            if subset == 0:
                break
            subset = (subset-1) & v


def fill_hints(hints, hintIdx, sums, lengths):
    for idx, h in enumerate(hints):
        a, b, d, s = h
        sums[idx] = s
        if d == 0:
            j = b
            while j < N and board[a-1][j] == 1: 
                hintIdx[0][a-1][j] = idx
                j += 1
            lengths[idx] = j-b
        else:
            i = a
            while i < N and board[i][b-1] == 1:
                hintIdx[1][i][b-1] = idx
                i += 1
            lengths[idx] = i-a


def get_candidate(i, j):
    a, b = hintIdx[0][i][j], hintIdx[1][i][j]
    def f(idx):
        return candidate[lengths[idx]][sums[idx]][knowns[idx]]
    return f(a) & f(b)


def put(i, j, v):
    for h in range(2):
        knowns[hintIdx[h][i][j]] += (1 << v)
    value[i][j] = v


def remove(i, j, v):
    for h in range(2):
        knowns[hintIdx[h][i][j]] -= (1 << v)
    value[i][j] = 0


def search():
    y, x, minCands = -1, -1, MAX_VAL-1
    for i in range(N):
        for j in range(N):
            if board[i][j] == 1 and value[i][j] == 0:
                cands = get_candidate(i, j)
                if Length(minCands) > Length(cands):
                    minCands = cands
                    y, x = i, j

    if minCands == 0:
        return False
    if y == -1:
        print('\n'.join(' '.join(map(str, row)) for row in value))
        return True
    for val in range(1, 10, 1):
        if minCands & (1 << val):
            put(y, x, val)
            if search():
                return True
            remove(y, x, val)
    return False

# print_matrix
def pm(m):
    for row in m:
        for c in row:
            print('%(digit)02d' % {'digit': c}, end=' ')
        print('')


for case in range(int(input())):
    N = int(input())
    board = [list(map(int, input().split())) for _ in range(N)]
    H = int(input())
    hints = [list(map(int, input().split())) for _ in range(H)]

    candidate = [[[0]*MAX_VAL for s in range(MAX_SUM)] for l in range(MAX_L)]
    fill_candidate(candidate)

    hintIdx = [[[-1]*N for _ in range(N)] for _ in range(2)]
    sums = [0]*H
    knowns = [0]*H
    lengths = [0]*H
    fill_hints(hints, hintIdx, sums, lengths)

    value = [[0]*N for _ in range(N)]
    search()
