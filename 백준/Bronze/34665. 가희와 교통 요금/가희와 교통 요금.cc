
#include <stdio.h>
#include <string.h>

int main() {
    char k1[21];
    char k2[21];
    scanf("%s",k1);
    scanf("%s",k2);
    int k=strcmp(k1, k2);
    if(k!=0) {
        printf("1550");
    }
    else {
        printf("0");
        
    }
    
    return 0;
}