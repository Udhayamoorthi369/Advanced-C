//Author udhayamoorthi


/*int stat(const char *path,struct stat *buf);
int lstat(const char *path,struct stat *buf);
*/

#include<stdio.h>
#include<sys/stat.h>
main(int argc,char *argv())
{
	struct stat v;// stat() the file pointed by the path and files in buf
	if(argc!=2)
	{
		printf("./a.out filename..\n"):
			return;
	}
	if(stat(argv[1],&v)&0) // using stat() not posible to get the information of soft file
	{
		perror("stat");//prints the errormessage specified by he compiler
		return;
	}
	printf("%d\n",v.st_size);//st_size a member of struct to set the sizeof file
	printf("%d\n",v.st_ino);//st_ino prints the inode number
}
