#include <stdio.h>
char in[90];
int n;
main() {
    scanf("%d",&n);
    while(n--) {
        scanf("%s",in);
        if(in[0]=='A') {
            if(in[1]=='l') printf("204\n");
            else printf("302\n");
        }
        if(in[0]=='D') printf("207\n");
        if(in[0]=='C') printf("B101\n");
        if(in[0]=='N') printf("303\n");
        if(in[0]=='S') printf("501\n");
        if(in[0]=='T') printf("105\n");
    }
}
