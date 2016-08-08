#!/usr/bin/env python
# encoding: utf-8

def digit_sum(n):
    ret = 0
    while n > 0:
        ret += n % 10
        n /= 10
    return ret

a = []
N = 100
for i in xrange(2, N):
    j = i
    while j < 10**20:
        if j >= 10 and digit_sum(j) == i:
            a.append(j)
        j *= i

a.sort()
print len(a)
print a
print a[29]
