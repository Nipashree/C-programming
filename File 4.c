#include<stdio.h>
int main()
{
    int a,b,c;
    printf("Enter the value of A and B:\n");
    scanf("%d%d",&a,&b);
    c=a;
    a=b;
    a=c;
    printf("New value of A:%d\n",a);
    printf("New value of b:%d\n",b);
}