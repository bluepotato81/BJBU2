import math
import sys

n,m,k = map(int, input().split())

totpos = math.comb(n+m,n)

if k>totpos:
    print("-1")
    sys.exit()

ans=[]

while n>0 and m>0:
    npos=math.comb(n+m-1, n-1)

    if k<=npos:
        ans.append("a")
        n-=1
    else:
        ans.append("z")
        m-=1
        k-=npos

ans.extend("a"*n)
ans.extend("z"*m)


print(''.join(ans))

    
        

