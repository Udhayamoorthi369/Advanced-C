#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    FILE *fptr;
    //fptr = fopen("hello.txt","w");

if((fptr=fopen("hello.txt","r"))==NULL)
{
printf("error!");
exit(1);
}
fscanf(fptr,"%d",&n);
printf("the value of n :%d",n);
//scanf("%d",&n);

//printf(fptr,"%d",n);
fclose(fptr);
}


