#include <stdio.h>

int main() {
    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);

    int ins1[m];
    int ins2[m];
    int ins3[m];

    for(int i=0;i<m;i++) {
        scanf("%d %d %d", &ins1[i], &ins2[i], &ins3[i]);
    }
    //for(int i=0; i<m;i++) {
        //printf("%d", ins1[i]);
    //}
    //printf("\n");

    int ne[n+1][n+1];
    int rex[n+1];

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            ne[i][j]=0;
        }
        rex[i]=0;
    }

    for(int i=0;i<m;i++) {
        if(rex[ins1[i]]) {
            continue;
        }
        else {
            int sel=ins1[i];
            //printf("%d\n", ins1[i]);
            rex[sel]=1;
            for(int j=0;j<m;j++) {
                if(ins1[j]==sel){
                    if(rex[ins2[j]]==0) {
                        //printf("%d ", ins2[j]);
                        ne[sel][ins2[j]]+=ins3[j];
                    }
                    else {
                        for(int k=0; k<n;k++) {
                            ne[sel][k]+=ins3[j]*ne[ins2[j]][k];
                        }
                    }
                }
            }
            for(int j=1;j<=n;j++) {
                if(ne[j][sel]) {
                    int am= ne[j][sel];
                    ne[j][sel]=0;
                    for(int k=0; k<n;k++) {
                        ne[j][k]+=am*ne[sel][k];
                    }
                }
            }
            //for(int j=1;j<=n;j++) {
             //   printf("%d ", ne[sel][j]);
            //}
            //printf("\n");
        }
    }

    for(int i=1;i<=n;i++) {
        if(ne[n][i]!=0) {
            printf("%d %d\n", i, ne[n][i]);
        }

    }

    return 0;
}
