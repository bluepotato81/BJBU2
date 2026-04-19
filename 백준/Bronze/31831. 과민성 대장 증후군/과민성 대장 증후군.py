n,m=map(int,input().split(" "))
k=input().split(" ")
k=list(map(int,k))
comp=0
days=0
for i in k:
    comp+=i
    if comp<0:
        comp=0
    if comp>=m:
        days+=1
print(days)
