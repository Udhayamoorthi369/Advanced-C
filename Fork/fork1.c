#include<stdio.h>
int main()
{
int ret;
printf("hello");
ret=fork();//the fork() will return the value
printf("ret=%d",ret);//the value of return
}
