import sys
from collections import defaultdict, deque, Counter
from heapq import heappush, heappop, heapify
from bisect import bisect_left, bisect_right
from itertools import accumulate, permutations, combinations, product
from functools import lru_cache, cache
from math import gcd, inf, isqrt

input = sys.stdin.readline
sys.setrecursionlimit(10**7)

def ii(): return int(input())
def mi(): return map(int, input().split())
def li(): return list(map(int, input().split()))
def si(): return input().rstrip()

def solve():
    k = ii()
    l = li()
    l.sort()
    l.reverse()
    q = deque()
    ans = 0
    cur = 0
    prev = -1
    for v in l:
        if v == prev:
            cur+=1
            if(cur<=2):
                ans+=1
            q.append(v)
        else:
            prev = v
            cur=1
            ans+=1
            q.appendleft(v)
    print(ans)
    for v in q:
        print(v,end=" ")
    print()



def main():
    t = ii()
    for _ in range(t):
        solve()

main()