#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char    str[10];
    FILE    *fptr;
    int     i;
    int     num,avg=0,k,status,x;
    char    num2;
    i = 0;
    pid_t child=fork();
    if(child==0)
{
 char  *a[]={"./myRand",NULL};
 execl("./myRand",a);
}
else
{
wait(&status);
k=WEXITSTATUS(status);
}
    fptr = fopen("dataX1.dat", "w");

    if (fptr == NULL)
    {
        printf("ERROR Creating File!");
        exit(1);
    }
//    while (str[i] != '\0')

for (int i = 0; i < 60; ++i)
{
  fscanf(fptr, "%d\n",&num);
printf("%d ",num);
avg+=num;
}
printf("avg:%d\n",avg/60);  
 
    fclose(fptr);
    return (0);
}


