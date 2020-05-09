import math

x = int(input())
balance = 100.0
ans = 0

while balance < x:
    ans += 1
    balance += math.floor(balance * 0.01)

print(ans)
