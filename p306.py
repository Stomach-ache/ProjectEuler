#!/usr/bin/env python
# encoding: utf-8

sg = [-1 for i in xrange(1000001)]
lost_state = []

def get_sg(n):
    if n <= 1:
        return 0
    if sg[n] != -1:
        return sg[n]

    s = set()
    for i in xrange(n - 1):
        s.add(get_sg(i) ^ get_sg(n - i - 2))
    g = 0
    while g in s:
        g += 1
    sg[n] = g
    return g

for i in xrange(1, 100 + 1):
    sg[i] = get_sg(i)
    if sg[i] == 0:
        lost_state.append(i)
#        print i, sg[i]

def solve(n):
    while True:
        last = lost_state[-5] + 34
        if n <= last:
            break
        lost_state.append(last)

solve(10**6)
print 10**6 - len(lost_state)
