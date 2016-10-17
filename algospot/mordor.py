import sys
import gc

input = sys.stdin.readline

class RMQ:
    def __init__(self, arr):
        self.n = len(arr)
        sz = 1
        while sz <= self.n:
            sz = sz << 1
        self.data = [0]*(sz*2)
        self.__init(arr, 0, len(arr)-1, 1)
        self.inf = 987654321
        gc.collect()

    def __init(self, arr, left, right, node):
        if left == right:
            self.data[node] = arr[left]
            return self.data[node]
        mid = (left + right) // 2
        self.data[node] = min(self.__init(arr, left, mid, node*2), self.__init(arr, mid+1, right, node*2+1))
        return self.data[node]
    
    def __query(self, left, right, node, nodeLeft, nodeRight):
        if left > nodeRight or nodeLeft > right:
            return self.inf

        if left <= nodeLeft and nodeRight <= right:
            return self.data[node]

        mid = (nodeLeft + nodeRight) // 2
        return min(self.__query(left, right, node*2, nodeLeft, mid), self.__query(left, right, node*2+1, mid+1, nodeRight))

    def query(self, left, right):
        return self.__query(left, right, 1, 0, self.n - 1)

for c in xrange(int(input())):
    N, Q = map(int, input().split())
    H = map(int, input().split())
    minR = RMQ(H)
    maxR = RMQ([ -x for x in H])

    for i in xrange(Q):
        l, r = map(int, input().split())
        print -(maxR.query(l, r) + minR.query(l, r))

