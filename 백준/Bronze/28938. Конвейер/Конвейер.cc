#import<ios>
int a,b,k;
main(){
    scanf("%d",&a);
    while(a--){
        scanf("%d",&k);
        b+=k;
    }
    if(b>0){
        printf("Right");
    }
    else if(!b) {
        printf("Stay");
    }
    else {
        printf("Left");
    }
    
}