#include<stdio.h>
int main()
{
	int ret;
	printf("hello");
	ret=fork();
	if(ret==0)
	{
		printf("exclusive %d\n");
		printf("PID=%d",getpid());

	}
}
