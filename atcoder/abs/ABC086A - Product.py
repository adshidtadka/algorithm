# -*- coding: utf-8 -*-
# 整数の入力
a, b = map(int, input().split())
 
if a*b % 2 == 0:
	ans = "Even"
else:
	ans = "Odd"
 
print(ans)