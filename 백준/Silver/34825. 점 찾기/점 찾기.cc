#include <stdio.h>

int main() {
    long long ax,ay;
    long long bx,by;

    scanf("%lld %lld", &ax,&ay);
    scanf("%lld %lld", &bx,&by);

    long long xd = ax-bx;
    long long xl=bx;
    if(xd<0) {
        xd*=-1;
        xl=ax;
    }
    long long yd = ay-by;
    long long yl=by;
    if(yd<0) {
        yd*=-1;
        yl=ay;
    }

    if((xd+yd)%2 ==1) {
        printf("-1");
        return 0;
    }
    else {
        long long cent=(xd+yd)/2;
        if(xd>yd) {
            if(xl==ax) {
                printf("%lld %lld", xl+cent, ay);
            }
            else {
                printf("%lld %lld", xl+cent, by);
            }
        }
        else {
            if(yl==ay) {
                printf("%lld %lld", ax, yl+cent);
            }
            else {
                printf("%lld %lld", bx, yl+cent);
            }
        }
    }

    return 0;
}
