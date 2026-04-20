#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);
    
    for(int i=0; i<a/5;i++) {
        printf("V");
    }
    for(int i=0; i<a%5;i++) {
        printf("I");
    }
    
    return 0;
}