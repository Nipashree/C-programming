#include<stdio.h>
int main()
{
    int a, b;
    printf("Enter the value of A and B:\n");
    scanf("%d%d", &a, &b);
    a = a + b;
    b = a - b;
    a = a - b;
    printf("New value of A:%d\n", a);
    printf("New value of B:%d\n", b);
}