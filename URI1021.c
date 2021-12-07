#include<stdio.h>

int main(void){
    
    //Número de entrada
    double num;
    //cedulas e moedas
    int cem, real, cinquenta, vinte, dez, cinco, dois, ccinquenta, cvinte, cdez, ccinco, cent;
    
    //Recebe o valor de entrada
    scanf("%lf", &num);
    
    //Calculo da quantidade de notas de 100
    cem = num/100;
    num = num - cem*100;
       
    cinquenta = num/50;
    num = num - cinquenta*50;
    
    vinte = num/20;
    num = num - vinte*20;
    
    dez = num/10;
    num = num - dez*10;
    
    cinco = num/5;
    num = num - cinco*5;
    
    dois = num/2;
    num = num - dois*2;
        
    real = num;
    num = num - real*1.00;

    //      
    num*=100;

     
    ccinquenta = num/50;  
    num = num - ccinquenta*50;

   // printf("%f\n", num);    
    cvinte = num/25;
    num = num - cvinte*25;
    
    //   printf("%f\n", num);  
    cdez = num/10;
    num = num - cdez*10;
    
       printf("%f\n", num);  
    ccinco = num/05;
    num = num - ccinco*05;
    
       printf("%f\n", num);  
    cent = (num+0.1);
    
    
    printf("NOTAS:\n");
    printf("%d nota(s) de R$ 100.00\n", cem);
    printf("%d nota(s) de R$ 50.00\n", cinquenta);
    printf("%d nota(s) de R$ 20.00\n", vinte);
    printf("%d nota(s) de R$ 10.00\n", dez);
    printf("%d nota(s) de R$ 5.00\n", cinco);
    printf("%d nota(s) de R$ 2.00\n", dois);
    
    printf("MOEDAS:\n");
    printf("%d moeda(s) de R$ 1.00\n", real); 
    printf("%d moeda(s) de R$ 0.50\n", ccinquenta);
    printf("%d moeda(s) de R$ 0.25\n", cvinte); 
    printf("%d moeda(s) de R$ 0.10\n", cdez); 
    printf("%d moeda(s) de R$ 0.05\n", ccinco); 
    printf("%d moeda(s) de R$ 0.01\n", cent); 
    return 0;
}