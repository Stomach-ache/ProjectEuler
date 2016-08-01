#!/usr/bin/env python
# encoding: utf-8

from primesieve import *
import heapq

n = 500500
MOD = 500500507

prime = generate_n_primes(n)

ans = 1
for i in xrange(n):
    Min = heapq.heappop(prime)
    heapq.heappush(prime, Min ** 2)
    ans *= Min
    if ans >= MOD:
        ans %= MOD

print ans

