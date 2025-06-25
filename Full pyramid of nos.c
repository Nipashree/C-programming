#include <stdio.h>  
int main()   
{  
   int i, space, r, k = 0, c = 0, c1 = 0;  
   printf("Enter the number of r: ");  
   scanf("%d", &r);  
   for (i = 1; i <= r; ++i)  
   {  
         for (space = 1; space <= r - i; ++space)   
         {  
              printf("  ");  
             ++c;  
       }  
       while (k != 2 * i - 1)  
              {  
                if (c <= r - 1) {  
                        printf("%d ", i + k);  
                    ++c;  
                }   
        else  
         {  
                      ++c1;  
                    printf("%d ", (i + k - 2 * c1));  
              }  
         ++k;  
      }  
      c1 = c = k = 0;  
      printf("\n");  
   }  
   return 0;  
}  
