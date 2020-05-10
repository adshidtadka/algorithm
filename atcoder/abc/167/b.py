
a, b, c, k = map(int, input().split())

if a >= k:
    print(k)
elif a + b >= k:
    print(k)
else:
    c_take = k - a - b
    print(a - c_take)
