#include<string.h>
#include<unistd.h>
#include <stdio.h>
#include <stdlib.h>
/* main program starts */
int main(void)
{
	/* hold the reference to the dataX.dat */
	FILE    *fptr;
	int     i;
	int     num;
	char    num2;
	/* generating random int between the range from 0 to 255*/
	int x=rand()%255+1;
	char file[256];
	/* concatinating random num with the filename */
	sprintf(file,"data%d.dat", x);
	/* creating file with write mode */
	fptr=fopen(file,"w");
	if (fptr == NULL)
	{
		printf("ERROR Creating File!");
		exit(0);
	}
	//    while (str[i] != '\0')
	/* generating the random num and store them in file */
	for (i = 0; i < 60; i++)
	{
		num=rand()%101;	
		fprintf(fptr, "%d\t", num);
	}

	// fprintf(fptr,"%s", str);
	fclose(fptr);
	printf("%d\n",x);
	//	return (0);
	/* exiting with status */
	exit(x);
}


