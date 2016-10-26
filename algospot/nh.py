import sys
import gc

input = sys.stdin.readline


class TrieNode(object):
    max_char = 26

    def __init__(self):
        self.terminal = -1
        self.state = -1
        self.fail = None
        self.child = [None]*TrieNode.max_char
        self.next = [None]*TrieNode.max_char
        self.output = set()

    def __chr_to_idx__(self, char):
        return ord(char) - ord('a')

    def insert(self, ch, i, idx):
        if len(ch) == i:
            self.terminal = idx
        else:
            pos = self.__chr_to_idx__(ch[i])
            if self.child[pos] is None:
                self.child[pos] = TrieNode()
                assert(self.child[pos] is not None)
            self.child[pos].insert(ch, i+1, idx)


def computeFailFunc(root):
    statenum = 0
    root.fail = root
    queue = [root]
    while len(queue) > 0:
        here = queue.pop(0)
        here.state = statenum
        statenum += 1
        for i, ch in enumerate(here.child):
            if ch is None:
                continue
            if here == root:
                ch.fail = root
            else:
                t = here.fail
                while t != root and t.child[i] is None:
                    t = t.fail
                if t.child[i] is not None:
                    t = t.child[i]
                ch.fail = t
            ch.output ^= ch.fail.output
            if ch.terminal != -1:
                ch.output.add(ch.terminal)
            queue.append(ch)


def computeTransition(here):
    for i in range(TrieNode.max_char):
        n = here
        while n is not n.fail and n.child[i] is None:
            n = n.fail
        if n.child[i] is not None:
            n = n.child[i]
        here.next[i] = n
        if here.child[i] is not None:
            computeTransition(here.child[i])


def count(n, node):
    if len(node.output) > 0:
        return 0
    if n == 0:
        return 1

    ret = cache[n][node.state]
    if ret >= 0:
        return ret
    ret = 0
    for i in range(TrieNode.max_char):
        ret += count(n-1, node.next[i])
        ret %= MOD
    cache[n][node.state] = ret
    return ret

for c in range(int(input())):
    n, m = map(int, input().split())
    gc.collect()
    MOD = 10007
    cache = [[-1 for i in range(100*10+1)] for _ in range(101)]
    root = TrieNode()
    for i in range(m):
        root.insert(input().strip(), 0, i)
    computeFailFunc(root)
    computeTransition(root)
    print(count(n, root))
