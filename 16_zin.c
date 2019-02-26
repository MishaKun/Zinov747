#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void)
{
signed long long int rez = 0;
int count = 0 ;
int number= 0 ;
scanf ("%d",&count);
for (int i=1;i<=count;i++)
{
scanf("%d",&number);
number = abs(number);
rez = rez + (pow(-1,i+1)*pow(number,3));
number = 0 ;
}
printf("%lli",rez);
}
