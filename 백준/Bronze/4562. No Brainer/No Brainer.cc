#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int a,b;
        scanf("%d %d", &a, &b);
        if(a<b) {
            printf("NO BRAINS\n");
        }
        else {
            printf("MMM BRAINS\n");
        }
    }
    
    return 0;
}