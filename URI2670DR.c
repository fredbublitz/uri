#include <stdio.h>
 
int main() {
 
    int A1,A2,A3,total,i;
    
    for(i=1;i<=3;i++){
        scanf("%d%d%d",&A1,&A2,&A3);
        if(A3>A1 & A3>A2){
            total = ((A1*60)*2 + A2*60)/30;
            printf("%d\n",total);
        }
        if(A2>A1 & A2>A3){
            total = (A1*60 + A3*60)/30;
            printf("%d\n",total);
        }
        if(A1>A2 & A1>A3){
            total = ((A2*60) + ((A3*60)/3))/10;
            printf("%d\n",total);
        }
    }
    
    return 0;
}