#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<elf.h>

int main(int argc,char **argv)
{
  Elf64_Ehdr ehdr;
  int fd =open(argv[1],O_RDWR);

 read(fd,&ehdr,sizeof(ehdr));
 printf("Entrypoint : %x\n",ehdr.e_entry);
 ehdr.e_entry = 0x8046be;
 lseek(fd,0,SEEK_SET);
 write(fd,&ehdr,sizeof(ehdr));
 close(fd);
}
