
#include <stdio.h>
void ShellSort(int n, int *mass)
{
    int  o;
    int boot;
    int tmp;
    for (boot = n / 2; boot > 0; boot =boot / 2)
        for (int i = boot; i < n; i++)
        {
            tmp = mass[i];
            for (o = i; o >= boot; o =o - boot)
            {
                if ( tmp<mass[o - boot] )
                    mass[o] = mass[o - boot];
                else
                    break;
            }
            mass[o] = tmp;
        }
}
int main()
{
  int n;
  scanf("%d",&n);
  int m[n];
  for (int i = 0; i<n; i++) 
  {
    scanf("%d", &m[i]);
  }
  ShellSort(n,m); 
  for (int i = 0; i<n; i++)
    printf("%d ", m[i]);
}
