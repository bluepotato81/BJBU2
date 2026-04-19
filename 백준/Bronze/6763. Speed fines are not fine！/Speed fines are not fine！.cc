#include <stdio.h>

int main() {
    int a,b;
    scanf("%d%d", &a, &b);
    
    if(b-a<=0) {
        printf("Congratulations, you are within the speed limit!");
    }
    else {
        int k;
        if(b-a<=20) {
            k=100;
        }
        else if(b-a<=30) {
            k=270;
        }
        else {
            k=500;
        }
        
        printf("You are speeding and your fine is $%d.", k);
            
    }
    
    return 0;
}