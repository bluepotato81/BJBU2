#include <stdio.h>

int img[200][200];
int imgen[200][200];

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void fillin(int h, int w, int x, int y, int color) {
    imgen[y][x]=color;
    for(int i=0; i<4;i++) {
        int newx=x+dx[i];
        int newy=y+dy[i];
        if(newx>=0 && newx<w && newy>=0 && newy<h && img[newy][newx]==1 && imgen[newy][newx]==-1) {
            fillin(h,w,newx,newy,color);
        }
    }
}

int wscan(int h, int w, int x, int y) {
    imgen[y][x]=-1;
    int retval=-2;
    for(int i=0; i<4;i++) {
        int newx=x+dx[i];
        int newy=y+dy[i];
        if(newx>=0 && newx<w && newy>=0 && newy<h && imgen[newy][newx]==0) {
            int k=wscan(h,w,newx,newy);
            if(retval==-2) {
                retval=k;
            }
            else if(retval!=k) {
                retval=-1;
            }
        }
        else if(newx<0 || newx>=w || newy<0 || newy>=h) {
            retval=-1;
        }
        else if(imgen[newy][newx]>=1) {
            if(retval==-2) {
                retval=imgen[newy][newx];
            }
            else if(retval!=imgen[newy][newx]) {
                retval=-1;
            }
        }
    }
    return retval;
}

int main() {
    int t=0;
    while(1){
        t++;
        int h,w;
        scanf("%d %d", &h, &w);

        if(h==0) {
            break;
        }

        char l;
        int val;
        for(int i=0; i<h;i++) {
            for(int j=0; j<w;j++) {
                scanf(" %c", &l);
                if(l>='0' && l<='9') {
                    val=l-'0';
                }
                else {
                    val=l-'a'+10;
                }
                for(int k=3;k>=0;k--) {
                    img[i][(4*j)+k]=val%2;
                    val/=2;
                }
            }
        }

        int n=0;
        for(int i=0; i<h;i++) {
            for(int j=0;j<4*w;j++) {
                imgen[i][j]=-1;
            }
        }
        for(int i=0; i<h;i++) {
            for(int j=0;j<4*w;j++) {
                if(img[i][j]==0) {
                    imgen[i][j]=img[i][j];
                }
                else if (imgen[i][j]==-1){
                    fillin(h,w*4,j,i,n+1);
                    n++;
                }
            }
        }

        int sha[n];
        for(int i=0; i<n;i++) {
            sha[i]=0;
        }

        for(int i=0; i<h;i++) {
            for(int j=0;j<4*w;j++) {
                if(imgen[i][j]==0) {
                    int sur=wscan(h,w*4,j,i);
                    if(sur>0) {
                        sha[sur-1]++;
                    }
                }
            }
        }

        int let[6]={0,0,0,0,0,0};

        for(int i=0; i<n;i++) {
            if(sha[i]==1) {
                let[0]++;
            }
            if(sha[i]==5) {
                let[1]++;
            }
            if(sha[i]==3) {
                let[2]++;
            }
            if(sha[i]==2) {
                let[3]++;
            }
            if(sha[i]==4) {
                let[4]++;
            }
            if(sha[i]==0) {
                let[5]++;
            }
        }

        printf("Case %d: ",t);
        while(let[0]--) {
            printf("A");
        }
        while(let[1]--) {
            printf("D");
        }
        while(let[2]--) {
            printf("J");
        }
        while(let[3]--) {
            printf("K");
        }
        while(let[4]--) {
            printf("S");
        }
        while(let[5]--) {
            printf("W");
        }
        printf("\n");
    }

    return 0;
}
