#include<stdio.h>
#include<unistd.h>
int main()
{
	printf("hello..\n");
	execl("/bin/ls","ls",NULL);// PRESENT WORKING DIRECTIORIES
	printf("after execl()..\n");
}
