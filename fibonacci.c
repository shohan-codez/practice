#include<stdio.h>
int fib(int a, int b, int n);
int main(){
    int n;
    int a,b,*fibo;
    a=0;
    b=1;
    
    printf("number of  fibonacci?\n");
    scanf("%d",&n);
    printf("0\n1");
    
    for(int i=2;i<n;i++){
        *(fibo+i)=fib(a,b,n); 
        printf("%d\n",fibo[i]);
    }  
    
    
   
    return 0;
}
int fib(int a, int b ,int n){
     for(int i=2;i<=n;i++){
        
       
       int s = a+b;
        return s;
       a=b;
       b=s;
      
    }
}