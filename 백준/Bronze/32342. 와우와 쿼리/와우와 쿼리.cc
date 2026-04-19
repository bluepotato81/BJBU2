#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    while(n--) {
        char k[1001];
        scanf("%s", k);
        size_t len=strlen(k);
        int c=0;
        for(size_t i=2; i<len;i++) {
            if(k[i-2]=='W' && k[i-1]=='O' && k[i]=='W') {
                c++;
            }
        }
        printf("%d\n", c);
    }
    
    return 0;
}