//Author : Udhayamoorthi

/*int stat(const char *path,struct stat *buf);
int lstat(const char *path,struct stat *buf);
*/

#include<stdio.h>
#include<sys/stat.h>
main(int argc,char *argv[])
{
   struct stat v1,v2; // stats the file pointed to by pathy and fills in buf
   if(argc!=3)
   {
	   printf("./a.out file1 file ../n");
		   return;
   }
   stat(argv[1],&v1);//check the status of a file such as to check when the file was accessed
   stat(argv[2],&v2);
			   if(v1.st_ino==v2.st_ino) //ino is inode number
			   {
			   lstat(argv[1],&v1);//is identical to stat(),except that if path is a symbolic link,then the link itself stat-ed,not the file that it refers to
			   lstat(argv[2],&v2);
			   if(v1.st_ino==v2.st_ino) //inode num
			   printf("hard link file\n");
			   else
			   printf("soft link file\n");
			   }
			   else
			   printf("no link..\n");
			   }

			   
