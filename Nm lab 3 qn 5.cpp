#include<stdio.h>

#include<math.h>
#define f(x) x*x*x+1
int main()
{
  
   float a,b,h,c,d,It;
   printf("\nEnter initial value of X:");
   scanf("%f",&a);
   printf("\nEnter  Final  value of X:");
   scanf("%f",&b);
   h=(b-a)/2;
   c=h+a;
   d=c+h;
   It =(3*h/8)*(f(a)+3*f(c)+3*f(d)+f(b));
   printf("\nThe integration value of function :%f",It);
   return 0;
}