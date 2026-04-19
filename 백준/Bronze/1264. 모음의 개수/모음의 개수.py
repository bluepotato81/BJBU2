while True:
    k=input()
    if k=="#":
        break
    a=0
    for l in k:
       if l=='a' or l=='e' or l=='i' or l=='o' or l=='u' or l=='A' or l=='E' or l=='I' or l=='O' or l=='U':
           a+=1
    print(a)