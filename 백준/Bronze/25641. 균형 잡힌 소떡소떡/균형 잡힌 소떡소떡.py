a=int(input())
st=input()

s=0
t=0;
for k in st:
    if k=='s':
        s+=1
    else:
        t+=1

prin=0
ans=[]
for k in st:
    if s==t:
        prin=1
    
    if not prin:
        if k=='s':
            s-=1
        if k=='t':
            t-=1
    if prin:
        ans.append(k)
    


print(''.join(ans))
