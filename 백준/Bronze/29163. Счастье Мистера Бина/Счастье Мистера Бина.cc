#include <stdio.h>

int main() {
    int n;
    int o=0;
    int e=0;
    scanf("%d", &n);
    int i;
    while(n--) {
        scanf("%d", &i);
        if(i%2) {
            o++;
        }
        else {
            e++;
        }
    }
    if(e>o) {
        printf("Happy");
    }
    else {
        printf("Sad");
    }
    
    return 0;
}