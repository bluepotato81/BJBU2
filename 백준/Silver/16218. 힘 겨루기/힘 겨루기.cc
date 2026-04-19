#include <stdio.h>

int main() {
    int n,k;
    scanf("%d %d", &n,&k);

    int jc=0, tc=0;
    int op=0;
    int a,b;
    int end=0;
    int res;
    for(int i=0;i<n;i++) {
        scanf("%d %d", &a,&b);
        if(end) {
            continue;
        }
        if(i==n-1) {
            if(tc+b>=k) {
                if(jc+a >=k) {
                    res=1;
                    end=1;
                    continue;
                }
                else {
                    res=-1;
                    end=1;
                    continue;
                }
            }
            else if(jc+(3*a)/2>=k) {
                res=1;
                end=1;
                continue;
            }
            else if(jc + (3*a)/2 >= tc+b+50) {
                res=1;
                end=1;
                continue;
            }
        }
        if(tc+b>=k) {
            if(jc+a >=k) {
                res=1;
                end=1;
                continue;
            }
            else {
                res=-1;
                end=1;
                continue;
            }
        }
        else if(jc+(3*a)/2>=k) {
            res=1;
            end=1;
            continue;
        }
        else if(jc + (3*a)/2 >= tc+b+50) {
            res=1;
            end=1;
            continue;
        }
        else {
            jc+=a;
            tc+=b;
        }

    }

    if(!end) {
        res=0;
    }
    printf("%d", res);

    return 0;
}
