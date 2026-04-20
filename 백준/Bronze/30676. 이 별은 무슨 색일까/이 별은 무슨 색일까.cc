#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    
    if(n>=620) {
        printf("Red");
    }else if(n>=590) {
        printf("Orange");
    }else if(n>=570) {
        printf("Yellow");
    }else if(n>=495) {
        printf("Green");
    }else if(n>=450) {
        printf("Blue");
    }else if(n>=425) {
        printf("Indigo");
    }else {
        printf("Violet");
    }
    return 0;
}