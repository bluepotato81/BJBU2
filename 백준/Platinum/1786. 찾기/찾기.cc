#include <stdio.h>
#include <string.h>

char t[10000001];
char p[10000001];
int pi[10000001];
int f[10000001];
int main() {

    fgets(t,sizeof(t),stdin);
    fgets(p,sizeof(p),stdin);

    t[strcspn(t, "\n")] = '\0';
    p[strcspn(p, "\n")] = '\0';

    size_t tlen=strlen(t);
    size_t plen=strlen(p);

    for(int i=0; i<=plen;i++) {
        pi[i]=0;
    }

    int tj=0;
    for(int i=1; i<plen;i++) {
        while(tj>0 && p[i]!=p[tj]) {
            tj=pi[tj-1];
        }
        if(p[i]==p[tj]) {
            tj++;
            pi[i]=tj;
        }
    }



    int j=0;
    int np=0;

    for(int i=0; i<=tlen;i++) {
        while(j>0 && t[i]!=p[j]) {
            j=pi[j-1];
        }
        if(t[i]==p[j]){
            if(j==plen-1) {

                f[np]=i-plen+1;
                np+=1;
                j=pi[j];
            }
            else {
                j++;
            }
        }
    }

    printf("%d\n", np);
    for(int i=0; i<np;i++) {
        printf("%d ", f[i]+1);
    }

    return 0;
}
