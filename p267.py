#!/usr/bin/env python
# encoding: utf-8

C = [[0 for i in xrange(1001)] for j in xrange(1001)]

for i in xrange(1, 1001):
    C[i][0] = C[i][i] = 1
    for j in xrange(1, i):
        C[i][j] = C[i - 1][j] + C[i - 1][j - 1]


s = sum(C[1000][432:])

for i in xrange(1000):
    s = s * 0.5;

print "%.12f" % s
