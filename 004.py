#!/usr/bin/python
# encoding: utf-8


ans = 0
for i in xrange(1, 1000):
    for j in xrange(i, 1000):
        num = i * j
        if str(num) == str(num)[::-1]:
            ans = max(ans, num)

print ans
