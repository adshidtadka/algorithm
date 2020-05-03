import itertools

n, m, q = map(int, input().split())
abcd_list = []
for i in range(q):
    abcd_list.append(list(map(int, input().split())))
print(abcd_list)
c_list = list(itertools.combinations([i for i in range(1, m + 1)], n))

ans = 0
for c in c_list:
    ans_tmp = 0
    for abcd in abcd_list:
        if c[abcd[1] - 1] - c[abcd[0] - 1] == abcd[2]:
            ans_tmp += abcd[3]
    if ans < ans_tmp:
        ans = ans_tmp
print(ans)
