#!/usr/bin/python
# encoding: utf-8

T = int(input())
while T > 0:
    T -= 1
    N, K = map(int, raw_input().split())
    s = raw_input()

    ans = 0
    for i in xrange(N-K):
        ans = max(ans, reduce(lambda x, y: x*y, map(int, s[i:i+K]), 1))
    print ans
