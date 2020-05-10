import itertools
N, M, X = map(int, input().split())
C = []
for i in range(N):
    C.append(list(map(int, input().split())))


L = [0, 1]

num = N
bl = list(itertools.product([0, 1], repeat=num))

acost = 10**9

for i in range(len(bl)):
    tcost = 0
    tskill = [0]*M
    t = bl[i]
    for j in range(N):
        if t[j] == 1:
            tcost += C[j][0]
            for k in range(M):
                tskill[k] += C[j][k+1]
    if min(tskill) >= X:
        if acost > tcost:
            acost = tcost

if acost == 10**9:
    print(-1)
else:
    print(acost)
