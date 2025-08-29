#include<stdio.h>

void swapByValue(int x,int y){
    int temp;
    temp=x;
    x=y;
    y=temp;
}

void swapByReference(int *x,int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

int main(){
    int a,b;
    scanf("%d",&a);
    scanf("%d",&b);
    printf("a= %d,b= %d\n",a,b);
    swapByValue(a,b);
    printf("a= %d,b= %d\n",a,b);
    swapByReference(&a,&b);
    printf("a= %d,b= %d\n",a,b);
    return 0;
}