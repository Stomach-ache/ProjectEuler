#!/usr/bin/env python
# encoding: utf-8

import sys

sys.setrecursionlimit(10000)

sg = [-1, 0, 1]
for i in xrange(3, 10**4 + 1):
    sg.append(sg[-2] + 1 ^ sg[-1] + 1)

MOD = 10**18
cache = {}

def solve(n, target):
    if target == -1:
        return 1
    if n == 1:
        return 0
    if n == 2:
        return 1 if target == 0 else 0

    if (n, target) in cache:
        return cache[(n, target)]

    lft, rgt = solve(n - 1, (target ^ sg[n - 2] + 1) - 1), solve(n - 2, (target ^ sg[n - 1] + 1) - 1)
    cache[(n, target)] = (lft + rgt) % MOD
    return cache[(n, target)]

print solve(5, 0)
print solve(10, 0)
print solve(10**4, 0)
