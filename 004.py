#!/usr/bin/python
# encoding: utf-8

a = []
def init():
    for i in xrange(100, 1000):
        for j in xrange(i, 1000):
            num = i * j
            if len(str(num)) is not 6:
                continue
            if str(num) == ''.join(list(reversed(str(num)))):
                #global a
                a.append(num)

if __name__ == '__main__':
    init()
    a.sort()
    T = int(raw_input())
    while T > 0:
        T -= 1
        N = int(raw_input())
        ans = -1
        for i in xrange(len(a)):
            if a[i] < N:
                ans = a[i]
            else:
                break
        print ans
