#include <stdio.h>
#include <stdlib.h>

int sort(const void *a, const void *b) {
    if(*(int*)a == 0) {
        return 1;
    }
    if(*(int*)b ==0) {
        return -1;
    }


    unsigned long long lena=1,lenb=1;
    int copa = *(int*)a;
    int copb= *(int*)b;

    //printf("%d %d\n", copa,copb);
    while(copa>0) {
        copa/=10;
        lena*=10;
    }
     while(copb>0) {
        copb/=10;
        lenb*=10;
    }
    
    unsigned long long la,lb;
    la=*(int*)a;
    lb=*(int*)b;

    //printf("%d %d\n",lenb * *(int*)a + *(int*)b,lena * *(int*)b + *(int*)a);
    if(lenb * la + lb  < lena * lb + la) {
        return 1;
    }
    else {
        return -1;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int list[n];
    int maxlen=0;
    int totlen=0;
    int zerocheck=1;
    for(int i=0; i<n;i++) {
        scanf("%d", &list[i]);
        if(list[i]!=0) {
            zerocheck=0;
        }

        int curlen=0;
        int val=list[i];
        while(val>0) {
            val/=10;
            curlen++;
        }

        totlen+=curlen;
        if(curlen>maxlen) {
            maxlen=curlen;
        }
    }
    if(zerocheck) {
        printf("0");
        return 0;
    }

    qsort(list, n, sizeof(int), sort);
    
    
    for(int i=0; i<n;i++) {
        printf("%d", list[i]);
    }


    return 0;
}
