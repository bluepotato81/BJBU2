import heapq

t=int(input())

while t:
    t-=1
    k=int(input())
    l=input().split(" ")
    l=list(map(int,l))
    ans=0
    heapq.heapify(l)
    while k>1:
        sm1 = heapq.heappop(l)
        sm2 = heapq.heappop(l)

        s=sm1+sm2
        ans+=s

        heapq.heappush(l,s)
        
        k-=1
    
    print(ans)
