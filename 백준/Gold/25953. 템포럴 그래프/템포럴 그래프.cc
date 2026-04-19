#include <stdio.h>

int min(int a,int b) {
    return a>b?b:a;
}

int main() {
    int n,t,m;
    scanf("%d %d %d", &n, &t,&m);
    int s,e;
    scanf("%d %d", &s, &e);

    int acc_point[n];
    int min_dis[n];

    for(int i=0;i<n;i++) {
        acc_point[i]=0;
        min_dis[i]=2000000000;
    }

    acc_point[s]=1;
    min_dis[s]=0;

    int newacc[m];
    int newdis[n];
    for(int i=0;i<t;i++) {
        for(int j=0;j<n;j++) {
            newdis[j]=2000000000;
        }
        for(int j=0;j<m;j++) {
            newacc[j]=-1;
            int a,b,c;
            scanf("%d %d %d", &a,&b,&c);
            if(acc_point[a]) {
                newdis[b]=min(newdis[b],min(min_dis[b], min_dis[a]+c));
                newacc[j]=b;

            }
            if(acc_point[b]) {
                newdis[a]=min(newdis[a],min(min_dis[a], min_dis[b]+c));
                newacc[j]=a;
            }
        }
        for(int j=0;j<m;j++) {
            if(newacc[j]!=-1) {
                acc_point[newacc[j]]=1;
            }
        }
        for(int j=0;j<n;j++) {
            if(newdis[j]!=2000000000) {
                min_dis[j]=newdis[j];
            }
            //printf("%d\n", min_dis[j]);
        }
        //printf("\n");
    }

    if(acc_point[e]==0) {
        printf("-1");
    }
    else {
        printf("%d", min_dis[e]);
    }


    return 0;
}
