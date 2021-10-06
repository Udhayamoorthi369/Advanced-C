#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	//char    str[10];
	FILE *fptr;
	int i;
	int num,avg=0,k,status,x;
	/* create child process */

	char file[256];
	pid_t cpid;
	cpid=fork();
	/* child process */
	if(cpid==0)
	{
		char  *arg[]={"myRand",NULL};
		execl("./myRand",arg);
	}
	/*! parent process */
	else
	{ /* wait for child to finish */
		wait(&status);
		/* status is returned by child process */
		k=WEXITSTATUS(status);
	}
	/* concatinating exit status returned by myRand program with the filename */
	sprintf(file,"data%d.dat",k);
	/* opening dataX.dat file in read mode */
	fptr = fopen(file, "r");

	if (fptr == NULL)
	{
		printf("ERROR Creating File!");
		exit(0);
	}
	/* reading data from dataX.dat file */
	//    while (str[i] != '\0')

	for (i = 0; i < 60; i++)
	{
		fscanf(fptr, "%d\n",&num);
		printf("%d ",num);
		avg+=num;
	}
	/*printing the avgerage */
	printf("avg:%d\n",avg/60);  

	/* closing the file */
	fclose(fptr);


}


