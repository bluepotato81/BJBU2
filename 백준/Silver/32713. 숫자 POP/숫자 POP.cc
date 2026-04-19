#include <stdio.h>

int main() {
    int n,k;
    scanf("%d %d",&n,&k);

    int list[n];
    for(int i=0; i<n;i++) {
        scanf("%d", &list[i]);
    }

    int maxst=1;
    for(int i=0; i<n;i++) {
        int see=list[i];
        int curst=1;
        int used=k;
        for(int j=i+1;j<n;j++) {
            if(list[j]==see) {
                curst++;
            }
            else {
                if(used==0) {
                    if(maxst<curst){
                        maxst=curst;
                    }
                    break;
                }
                else {
                    int check=0;
                    for(int kk=1;kk<=used;kk++) {
                        if(j+kk<n) {
                            if(list[j+kk]==see) {
                                used-=kk;
                                j=j+kk-1;
                                check=1;
                                break;
                            }
                        }
                    }
                    if(!check) {
                        if(maxst<curst){
                            maxst=curst;
                        }
                        break;
                    }
                }
            }
        }
        if(maxst<curst){
            maxst=curst;
        }
    }

    printf("%d", maxst);

    return 0;
}
