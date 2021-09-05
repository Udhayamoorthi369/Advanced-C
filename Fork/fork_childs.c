#include<stdio.h>
int main()
{
	if(fork()==0)
	{
		printf("in child..\n");
			printf("pid=%d\n",getpid());
		printf("ppid=%d\n",getppid());
	}
       else
       {
	       if(fork()==0)
	       {
		      printf("in child PID =%d,PPID = %d\n",getpid(),getppid());               }
	       else
	       {
		       if(fork()==0)
		       {
			       printf("in child 3 PID = %d PPID = %d\n",getpid(),getppid());
		       }
		       else
		       {
			       while(1);
		       }
	       }
       }
}
