#include<stdio.h>
int i=10;
int main()
{
if(fork()==0)
{
printf("in child i = %d\n",i);
i=200;
printf("in child i = %d\n",i):
sleep(1);
printf("child exit \n");
}
else
{
sleep(5);
printf("parents \n");
printf("i=%d\n",i);

