#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    FILE *fptr;//function descriptor
    //fptr = fopen("hello.txt","w");

if((fptr=fopen("hello.txt","r"))==NULL)//if file is null
{
printf("error!");//error messages will pop up
exit(1);
}
fscanf(fptr,"%d",&n);//is used o read set of characters from file
printf("the value of n :%d",n);//print the value 
//scanf("%d",&n);

//printf(fptr,"%d",n);
fclose(fptr);// close the fptr
}


