n=int(input())

am=[0,0,0,0]
while n:
    st,ram=input().split()
    k=int(ram)
    
    if st=="BANANA":
        am[0]+=k
    if st=="STRAWBERRY":
        am[1]+=k
    if st=="LIME":
        am[2]+=k
    if st=="PLUM":
        am[3]+=k
    n-=1

ch=1
for l in am:
    if l==5:
        print("YES")
        ch=0
        break
if ch:
    print("NO")