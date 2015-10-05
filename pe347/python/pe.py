#!/usr/bin/env python

import math
import itertools

def is_prime(n):
	if n == 1:
		return False
	if n == 2:
		return True
	sqrt_n = math.sqrt(n)
	for i in range(2, int(math.ceil(sqrt_n)) + 1):
		if n % i == 0:
			return False
	return True

def M(p, q, N):
	m = 0
	a = 1
	while p**a * q <= N:
		b = 1
		while p**a * q**b <= N:
			t = p**a * q ** b
			if t > m:
				m = t
			b+=1
		a+=1
	return m

def solve():
#limit = 100
	limit = 10000000
	l = []
	s = 0
	for i in range(2, limit+1):
		if is_prime(i):
			l.append(i)
	for x in itertools.combinations(l, 2):
		if x[0]**2 > limit:
			break
		if x[0]*x[1] > limit:
			continue
		m = M(x[0], x[1], limit)
		s += m
	print('answer: ', s)

if __name__ == '__main__':
	solve()

