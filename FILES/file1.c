#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    FILE *fptr;// function pointer
    fptr = fopen("hello.txt","w");//fopen is used to open a file  and w create an empty file

if(fptr==NULL)//pointer to a null pointer
{
printf("error!");
exit(1);
}
printf("the name : ");//user has to enter he name
scanf("%d",&n);

fprintf(fptr,"%d",n);// is used to print content in file insead of stdout console
fclose(fptr);//close the  fptr
}


