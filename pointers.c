#include <stdio.h>

int main(){
    int a;
    int *p = &a ;
    printf("whats the value of the a?\n");
    scanf("%d",&a);
    printf("the location of the a is %p\n",p);
    printf("the value of the a is %d\n",*p);

    printf("the value of the a is %p\n",a);
    return 0;
}
