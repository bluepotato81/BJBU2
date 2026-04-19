#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>

int vx, vy;

int cox[1000];
int coy[1000];

int angsort(const void *A, const void *B) {
    int a = *(int*)A;
    int b = *(int*)B;

    int axdif = cox[a]-vx;
    int aydif = coy[a]-vy;
    int bxdif = cox[b]-vx;
    int bydif = coy[b]-vy;

    int ac,bc;

    if(axdif==0) {
        ac=2;
    }
    else if(((float)aydif / (float)axdif)>0) {
        ac=1;
    }
    else if(aydif==0) {
        if(axdif>0) {
            ac=0;
        }
        else {
            ac=4;
        }
    }
    else {
        ac=3;
    }

    if(bxdif==0) {
        bc=2;
    }
    else if(((float)bydif / (float)bxdif)>0) {
        bc=1;
    }
    else if(bydif==0) {
        if(bxdif>0) {
            bc=0;
        }
        else {
            bc=4;
        }
    }
    else {
        bc=3;
    }

    //printf("(%d,%d), (%d,%d) %d %d\n", cox[a],coy[a],cox[b],coy[b],ac,bc);

    if(ac>bc) {
        return 1;
    }
    else if(ac<bc) {
        return -1;
    }
    else {
        if(aydif *bxdif > bydif *axdif) {
            return 1;
        }
        else if (aydif *bxdif < bydif *axdif){
            return -1;
        }
        else {
            if(aydif*aydif - bxdif*bxdif > -axdif*axdif+ bydif*bydif) {
                return -1;
            }
            else {
                return 1;
            }
        }

    }

}

int main() {
    int n, l;
    scanf("%d %d", &n, &l);


    int ymin = 10001;
    int vind;
    for(int i=0; i<n;i++) {
        scanf("%d %d", &cox[i], &coy[i]);
        if(coy[i]<ymin) {
            ymin=coy[i];
            vind=i;
        }
    }

    vx=cox[vind];
    vy=coy[vind];

    int srt[n-1];
    for(int i=0; i<n;i++) {
        if(i>vind) {
            srt[i-1]=i;
        }
        else if(i<vind) {
            srt[i]=i;
        }
    }

    qsort(srt, n-1, sizeof(int), angsort);

    /*for(int i=0; i<n-1;i++) {
        printf("%d",srt[i]);
    }
    printf("\n");*/

    int st[n];
    st[0]=vind;
    st[1]=srt[0];

    int stlen=2;

    for(int i=1; i<n-1;i++) {
        int x1=cox[st[stlen-2]];
        int y1=coy[st[stlen-2]];
        int x2=cox[st[stlen-1]];
        int y2=coy[st[stlen-1]];
        int x3=cox[srt[i]];
        int y3=coy[srt[i]];

        int ccw = (x2 -x1)*(y3-y1) - (y2-y1)*(x3-x1);
        if(ccw>=0) {
            st[stlen]=srt[i];
            stlen++;
        }
        else {
            stlen--;
            i--;
        }
        /*for(int j=0; j<stlen;j++) {
            printf("%d",st[j]);
        }
        printf("\n");*/
    }

    double len=0;
    for(int i=0;i<stlen-1;i++) {
        double x1=cox[st[i]];
        double y1=coy[st[i]];
        double x2=cox[st[i+1]];
        double y2=coy[st[i+1]];

        len+=sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
    }

    double x1=cox[st[stlen-1]];
    double y1=coy[st[stlen-1]];
    double x2=cox[st[0]];
    double y2=coy[st[0]];
    len+=sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));

    len+=2*M_PI*l;


    printf("%.0lf", round(len));

    return 0;
}
