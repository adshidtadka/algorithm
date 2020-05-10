N,K = map(int, input().split())
A = list(map(int,input().split()))
 
ls = [1]
s = {1}
cnt = 0
flag = 0
for i in range(K):
    t = A[ls[-1]-1]
    if t in s:
        nls = ls[ls.index(t):]
        flag = 1
        break
    else:
        ls.append(t)
        s.add(t)
        cnt += 1
        
if flag == 1:
    nokori = K-cnt-1
    amari = nokori % len(nls)
    print(nls[amari])
else:
    print(ls[-1])