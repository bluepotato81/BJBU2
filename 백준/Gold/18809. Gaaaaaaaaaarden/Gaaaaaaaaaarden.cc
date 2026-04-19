#include <iostream>
#include <queue>

using namespace std;

typedef struct{
    int x;
    int y;
}coord;

int ma[50][50];
int pal[10];
coord av[10];
int n,m,g,r;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};

int ans=0;
int avnum=0;
int skch=0;

int swap1[2]={1,-1};
int swap2[2]={2,-2};

void calc() {
    int flowers=0;
    queue<coord> inter;
    int cop[50][50];
    for(int i=0; i<n;i++) {
        for(int j=0; j<m;j++) {
            cop[i][j]=0;
        }
    }
    for(int i=0; i<avnum;i++) {
        if(pal[i]!=0) {
            cop[av[i].y][av[i].x]=pal[i];
            inter.push({av[i].x, av[i].y});
        }
    }


    int sw=0;
    while(1) {
        skch=0;
        size_t len = inter.size();
        while(len--){
                coord see = inter.front();
                inter.pop();
                int i = see.y;
                int j = see.x;
                if(cop[i][j]==swap1[sw]) {
                    for(int k=0; k<4;k++) {
                        int newx=j+dx[k];
                        int newy=i+dy[k];
                        if(newx>=0 && newx<m && newy>=0 && newy<n && ma[newy][newx]!=0) {
                            if(cop[newy][newx]==0) {
                                cop[newy][newx]=-swap1[sw];
                                skch++;
                                inter.push({newx, newy});
                            }
                            else if(cop[newy][newx]==-swap2[sw]) {
                                flowers++;
                                cop[newy][newx]=5;
                                skch++;
                            }
                        }
                    }
                    cop[i][j]=3;
                }
                if(cop[i][j]==swap2[sw]) {
                    for(int k=0; k<4;k++) {
                        int newx=j+dx[k];
                        int newy=i+dy[k];
                        if(newx>=0 && newx<m && newy>=0 && newy<n && ma[newy][newx]!=0) {
                            if(cop[newy][newx]==0) {
                                cop[newy][newx]=-swap2[sw];
                                skch++;
                                inter.push({newx, newy});
                            }
                            else if(cop[newy][newx]==-swap1[sw]) {
                                flowers++;
                                cop[newy][newx]=5;
                                skch++;
                            }
                        }

                    }
                    cop[i][j]=4;
                }
        }

        /*for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                printf("%d ", cop[i][j]);
            }
            printf("\n");
        }*/

        if(skch==0) {
            break;
        }
        sw=(sw+1)%2;
    }
    //printf("-------\n");

    if(flowers>ans) {
        ans=flowers;
    }
}

void repl(int cur, int prelim) {
    if(cur==r) {
        /*for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                printf("%d ", pal[i][j]);
            }
            printf("\n");
        }*/
        calc();
    }
    else {
        for(int i=prelim; i<avnum;i++) {
            if(pal[i]==0) {
                pal[i]=2;
                repl(cur+1, i+1);
                pal[i]=0;
            }
        }
    }
}

void grpl(int cur, int prelim) {
    if(cur==g) {
        repl(0,0);
    }
    else{
        for(int i=prelim; i<avnum;i++) {
            if(pal[i]==0) {
                pal[i]=1;
                grpl(cur+1, i+1);
                pal[i]=0;
            }

        }
    }
}



int main() {
    scanf("%d %d %d %d", &n, &m, &g, &r);

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            scanf("%d", &ma[i][j]);
            if(ma[i][j]==2) {
                av[avnum].x=j;
                av[avnum].y=i;
                avnum++;
            }
        }
    }

    grpl(0, 0);

    printf("%d", ans);



    return 0;
}
