# -*- coding: utf-8 -*-

n = input()
a = list(map(int, input().split()))

isEven = True
ans = 0
while isEven == True:
	for x in range(len(a)):
		if a[x] % 2 == 1 :
			isEven = False
	if isEven == True:
		for x in range(len(a)):
			a[x] /= 2
	else:
		break
	ans += 1

print(ans)
