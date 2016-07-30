#!/usr/bin/python
# encoding: utf-8

T = int(input())
while T > 0:
    N = int(input())
    a0, a1 = 1, 1
    ans = 0
    while True:
        a2 = a0 + a1
        if a2 > N:
            break
        if a2 % 2 == 0:
            ans += a2
        a0, a1 = a1, a2
    print ans
