#!/usr/bin/python
# encoding: utf-8

T = int(input())
while T > 0:
    N = int(input())
    a0, a1 = 1, 1
    ans = 0
    i = 3
    while True:
        a2 = a0 + a1
        if i % 3 == 0 and a2 <= N:
            ans += a2
        a0 = a1
        a1 = a2
        if a2 > N:
            break
        i += 1
    print ans
