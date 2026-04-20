#include <stdio.h>

char m[10000][500];
int visited[10000][500]={0, };
int r,c;
int cy[3]={-1,0,1};

int pos=0;
int a=0;


void print() {
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            printf("%c", m[i][j]);
        }
        printf("\n");
    }
}

int belcheck(int x, int y) {
    visited[y][x]=1;

    if(x==c-1) {
        m[y][x]='x';
        return 1;
    }


    for(int i=0; i<3;i++) {
        int newy=y+cy[i];
        int newx=x+1;
        if(newy>=0 && newy<r && m[newy][newx]!='x' && visited[newy][newx]==0) {
            if(belcheck(newx, newy)) {
                m[y][x]='x';
                return 1;
            }
        }
    }
    return 0;
}

void cal(int p) {
    int ch=belcheck(0, p);

    if(!ch) {
        pos++;
    }
    else {
        a++;
    }

    while(pos<r && m[pos][0]=='x') {
        pos++;
    }

    if(pos==r) {
        pos=-1;
    }


}


int main() {
    scanf("%d %d", &r, &c);
    char dum;

    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            scanf(" %c", &m[i][j]);
        }
    }


    int p;

    while(pos!=-1) {
        cal(pos);
    }

    printf("%d", a);



    return 0;
}
