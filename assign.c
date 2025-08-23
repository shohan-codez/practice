#include<stdio.h>
float final(float a){
    a = a+a*0.18;
    return a;
} 
int main(){
  
    float products[3];
    printf("write the value of the products\n");
    scanf("%f %f %f",&products[0],&products[1],&products[2]);
    float a,b,c;
    a=final(products[0]);
    b=final(products[1]);
    c=final(products[2]);
    
    printf("product 1:%f\n product 2:%f\n product 3:%f",a,b,c);

    return 0;
}

