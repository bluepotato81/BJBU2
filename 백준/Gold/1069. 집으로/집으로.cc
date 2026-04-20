#include <stdio.h>
#include <math.h>

int main() {
    double x,y,d,t;
    scanf("%lf %lf %lf %lf",&x,&y,&d,&t);
    double k= sqrt(x*x+y*y);

    double time=0;
    if(t>=d) {
        printf("%.10lf", k);
    }
    else {
        /*double l = k-floor(k/d)*d;
        if(l<d/2) {
            time+=floor(k/d) * t;
            time+=l;
        }
        else {
            time+=floor(k/d) * t;
            time+=t;
            time+=d-l;
        }*/

        int jumps = floor(k/d)+1;
        if(jumps<=1) {
            if(2*t<k && 2*t< t+fabs((k-d))) {
                printf("%.10lf", 2*t);
            }
            else {
                if(k< t+fabs((k-d))) {
                    printf("%.10lf", k);
                }
                else {
                    printf("%.10lf", t+fabs((k-d)));
                }
            }
        }
        else {
            if(jumps*t< (jumps-1)*t+fabs((k-(jumps-1)*d))) {
                printf("%.10lf", jumps*t);
            }
            else {
                printf("%.10lf", (jumps-1)*t+fabs((k-(jumps-1)*d)));
            }
        }

        //printf("%.10lf", time);
    }





    return 0;
}
