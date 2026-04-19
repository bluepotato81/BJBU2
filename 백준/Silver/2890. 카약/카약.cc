#include <stdio.h>

int main() {
    int r,c;
    scanf("%d %d", &r, &c);

    char map[r][c];
    for(int i=0;i<r;i++) {
        scanf("%s", map[i]);
    }

    int done[r];
    for(int i=0;i<r;i++) {
        done[i]=0;
    }

    int place[9];

    int d=1;

    for(int i=c-2;i>=0;i--) {
        int num=0;
        for(int j=0;j<r;j++) {
            if(map[j][i]>='0' && map[j][i]<='9') {
                if(done[j]==0) {
                    done[j]=1;
                    place[map[j][i]-'1']=d;
                    num++;
                }
            }
        }
        if(num) {
            d++;
        }
    }

    for(int i=0;i<9;i++) {
        printf("%d\n", place[i]);
    }

    return 0;
}
