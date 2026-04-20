#include <stdio.h>

int main() {
    char k[5];
    scanf("%s",k);
    
    if(k[0]=='N') {
        printf("North London Collegiate School");
    }
    if(k[0]=='B') {
        printf("Branksome Hall Asia");
    }
    if(k[0]=='K') {
        printf("Korea International School");
    }
    if(k[0]=='S') {
        printf("St. Johnsbury Academy");
    }
    
    
    return 0;
}