#include<stdio.h>
int main()
{
int ret;
printf("hello");
ret=fork();
printf("ret=%d",ret);
}
