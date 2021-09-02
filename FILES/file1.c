#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    FILE *fptr;
    fptr = fopen("hello.txt","w");

if(fptr==NULL)
{
printf("error!");
exit(1);
}
printf("the name : ");
scanf("%d",&n);

fprintf(fptr,"%d",n);
fclose(fptr);
}


