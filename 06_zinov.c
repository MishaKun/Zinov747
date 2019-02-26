#include <stdio.h>
int main (void ) 
{
int count_numbers = 0;
int input_number = 0;
int count_of_need_numbers = 0;
scanf ("%d",&count_numbers);
for (int i = 0 ; i < count_numbers;i++)
{
scanf("%d",&input_number);
if (input_number > 0)
{
count_of_need_numbers = count_of_need_numbers + 1;
}
input_number = 0;
}
printf ("%d\n",count_of_need_numbers);
return 0 ;
}
