#include <stdio.h>

void hoarasort(int* a, int first, int last)
{
 
int i = first, j = last;
double tmp, x = a[(first + last) / 2];
 
do {
   while (a[i] < x)
     i++;
   while (a[j] > x)
     j--;
 
   if (i <= j) 
   {
     if (i < j)
     {
       tmp=a[i];
       a[i]=a[j];
       a[j]=tmp;
     }
     i++;
     j--;
   }
} while (i <= j);
 
if (i < last)
   hoarasort(a, i, last);
if (first < j)
   hoarasort(a, first,j);
}
 int sorting_function(int *a,int n)
 {
     hoarasort(a,0,n);
     
 }
int main()
{
    int n;
    scanf("%d",&n);
    int mass[n];
    for (int i = 0 ;i < n;i++)
    scanf("%d",&mass[i]);
    sorting_function(mass,n);
    for (int i = 0 ;i < n;i++)
    printf("%d ",mass[i]);
}


