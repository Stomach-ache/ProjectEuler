#!/usr/bin/env python
# encoding: utf-8

N = 51

C = [[1] for i in xrange(N)]
C[1].append(1)

s = set([1])

for i in xrange(2, N):
    for j in xrange(1, i):
        C[i].append(C[i - 1][j] + C[i - 1][j - 1])
        if C[i][j] not in s:
            s.add(C[i][j])
    C[i].append(1)

#print max(s)

#because C(n, k) = n!/(k! * (n - k)!) so the largest prime factor doesnot exceed sqrt(n)
p = [2, 3, 5, 7]

t = set(s)
for v in t:
    for pi in p:
        if pi * pi > v:
            break
        if v % pi != 0:
            continue
        if v % (pi * pi) == 0:
            s.remove(v)
            break

print sum(s)


