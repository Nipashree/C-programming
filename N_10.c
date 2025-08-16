#include<stdio.h>
#define nsub 6

int main()
{
int grade_pt[nsub],cred[nsub],gpa,gp_sum=0,cred_sum=0;
printf("input gr.points and credits for 6 subs:\n");
for(int i=0;i<nsub;i++)
scanf("%d%d",&grade_pt[i],&cred[i]);
for(int i=0;i<nsub;i++)
{
    gp_sum+=grade_pt[i]*cred[i];
    cred_sum+=cred[i];
}
gpa=gp_sum/cred_sum;
printf("\n Grade Point Av:%d",gpa);
}
