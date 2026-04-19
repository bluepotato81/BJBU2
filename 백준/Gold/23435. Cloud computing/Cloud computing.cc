#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    if (n==2) {
        printf("? 0 1\n");
        fflush(stdout);

        char k;
        scanf(" %c", &k);

        if (k == '<') {
            printf("! 1\n");
        } else {
            printf("! 0\n");
        }

        fflush(stdout);
        return 0;
    }

    int layer=0;

    int copn = n;
    while(copn>0) {
        layer++;
        copn/=2;
    }

    layer -= 2;

    int comp=1;
    for(int i=0; i<layer+1; i++) {
        comp*=2;
    }

    if(n>comp) {
        layer++;
    }

    //printf("%d\n", layer);

    int sel[layer+1][(n/2)+(n%2)+1];

    copn=n;
    int lo = n/2;
    copn = copn/2 + copn%2;
    for(int i=0; i<lo;i++) {
        printf("? %d %d\n", i*2, (i*2)+1);
        fflush(stdout);
        char k;
        scanf(" %c", &k);
        if(k == '<'){
            sel[0][i] = i*2;
        }
        else {
            sel[0][i]=(i*2)+1;
        }
    }
    if(n%2) {
        sel[0][copn-1]=n-1;
    }
    if(copn%2){
        sel[0][copn]=-1;
    }
    //printf("a\n");
    //printf("%d\n", sel[0][3]);
    for(int i=1; i<layer+1; i++) {
        int org=copn;
        copn = copn/2 + copn%2;
        //printf("c: %d\n", copn);
        for(int j=0; j<org/2;j++) {
            printf("? %d %d\n", sel[i-1][j*2], sel[i-1][(j*2)+1]);
            fflush(stdout);
            char k;
            scanf(" %c", &k);
            if(k == '<'){
                sel[i][j] = sel[i-1][j*2];
            }
            else {
                sel[i][j]=sel[i-1][(j*2)+1];
            }
        }
        if(org%2){
            sel[i][copn-1]=sel[i-1][org-1];
        }
        if(copn%2) {
            sel[i][copn]=-1;
        }

        /*for(int j=0; j<copn;j++) {
            printf("%d ",sel[i][j]);
        }
        printf("\n");*/
    }
    //printf("a");
    /*int mi;
    printf("? %d %d\n", sel[layer-1][0], sel[layer-1][1]);
    fflush(stdout);
    char k;
    scanf(" %c", &k);
    if(k == '<'){
        mi = sel[layer-1][0];
    }
    else {
        mi = sel[layer-1][1];
    }*/

    //printf("%d\n",sel[0][3]);

    int mi = sel[layer][0];

    int cand[layer+1];
    int see = mi;

    if(mi%2==0) {
        cand[0]=mi+1;
        if(mi==n-1){
            cand[0]=-1;
        }
    }
    else {
        cand[0]=mi-1;
    }

    see/=2;

    for(int i=1; i<layer+1;i++) {
        if(see%2 == 0) {
            cand[i] = sel[i-1][see+1];
            see/=2;
        }
        else {
            cand[i] = sel[i-1][see-1];
            see--;
            see/=2;
        }
    }

    /*for(int i=0; i<=layer;i++) {
        printf("%d ", cand[i]);
    }
    printf("\n");*/

    int sp=0;
    for(int i=1; i<layer+1;i++) {
        if(cand[i]!=-1) {
            if(cand[sp]==-1) {
                sp=i;
                continue;
            }
        }
        if(cand[i]==-1) {
            continue;
        }
        printf("? %d %d\n", cand[sp], cand[i]);
        fflush(stdout);
        char p;
        scanf(" %c", &p);
        if(p=='>') {
            sp=i;
        }
    }

    printf("! %d\n", cand[sp]);
    fflush(stdout);


    return 0;
}
