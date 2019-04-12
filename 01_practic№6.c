#include <stdio.h>
void sorting_function(int n, int *mass){
  int y = n-1;
  int tmp;
  while(y>=1)
  {
    for(int i=0;i<n-y;i++){
    if(mass[i]>mass[i+y]){
    tmp=mass[i];
    mass[i]=mass[i+y];
    mass[i+y]=tmp;
      }
    }
   y = y - 1 ;
        }
}
int main ()
{
    int rang;
    scanf("%d",&rang);
    int mass[rang];
    for (int i = 0 ;i < rang;i++)
    
        scanf("%d",&mass[i]);
        
    sorting_function(rang,mass);
    for (int i = 0 ; i < rang;i++)
    printf("%d ",mass[i]);
    printf("\n");
}
