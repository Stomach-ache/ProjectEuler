#!/usr/bin/python
# encoding: utf-8

T = int(input())
while T > 0:
    T -= 1
    N = int(input())
    print -N*(N+1)*(2*N+1)/6 + (N+1)*(N+1)*N*N/4
