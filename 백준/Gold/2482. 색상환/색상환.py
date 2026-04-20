import math

n=int(input())
k=int(input())

if k>n//2:
    print("0")
else:
    print((math.comb(n-k-1, k-1) + math.comb(n-k, k))%1000000003)
