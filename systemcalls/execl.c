#include<stdio.h>
#include<unistd.h>
/*
 * exec family of function useful for minimizing the number o process creation
 */
int main()
{
	printf("hello..\n");//it will print hello
	execl("/bin/ls","ls",NULL);// PRESENT WORKING DIRECTIORIES
	printf("after execl()..\n");
}
