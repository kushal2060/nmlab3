#include<stdio.h>

#include<math.h>
#define f(x) x*x*x+1
int main()
{
  
   float a,b,h,c,It;
   printf("\nEnter initial value of X:");
   scanf("%f",&a);
   printf("\nEnter  Final  value of X:");
   scanf("%f",&b);
   h=(b-a)/2;
   c=h+a;
   It =(h/3)*(f(a)+4*f(c)+f(b));
   printf("\nThe integration value of function :%f",It);
   return 0;
}