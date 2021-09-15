#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>

/*! headers */
int main(int argc,char *argv[])
{
if(argc<2)
{
printf("filename is missing..");
exit(1);
}
int fd,data;

fd=open(argv[1],O_RDONLY);
if(fd<0)
{
printf("failed to open file..\n");
exit(1);
}

read(fd,&data,sizeof(data));

if(data == 0x464c457f)
{
printf("the file is ELF..\n");
}
else
{
printf("the file is not ELF..\n");
}
}
